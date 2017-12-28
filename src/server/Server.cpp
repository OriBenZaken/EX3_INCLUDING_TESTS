#include "Server.h"


Server::Server(int port): port(port), serverSocket(0), numberOfConnectedClients(0), threadNum(0) {
    cout<<"Server" <<endl;
}

void Server::start() {
    //create a socket point
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    //make sure socket was created successfully
    if (serverSocket == -1) {
        throw "Error openning socket";
    }
    //assign a local adress to the socket
    struct sockaddr_in serverAdress;
    bzero((void *) &serverAdress, sizeof(serverAdress));
    serverAdress.sin_family = AF_INET;
    serverAdress.sin_addr.s_addr = INADDR_ANY;
    serverAdress.sin_port = htons(port);
    if (bind(serverSocket, (struct sockaddr *) &serverAdress, sizeof(serverAdress)) == -1) {
        throw "Error on binding";
    }
    //start listening to incoming connections
    listen(serverSocket, MAX_CONNECTED_CLIENTS);
    //todo: to be exported to other thread
    ThreadArgs threadArgs;
    RoomsCollection *roomsCollection = new RoomsCollection();
    threadArgs.roomsCollection = roomsCollection;
    threadArgs.server = this;
    (*this).threads.push_back(threadNum);
    pthread_create(&(*this).threads.back(), NULL, HandleClients::acceptClient, (void *) &threadArgs);
    string exit;
    cin >> exit;
    if (exit.compare("exit") == 0) {
        pthread_cancel(threads[0]);
        for (int i = 0; i < roomsCollection->getRooms().size(); i++) {
            close(roomsCollection->getRooms().at(i).getFirstClientSocket());
            close(roomsCollection->getRooms().at(i).getSecondClientSocket());
        }

        for (int i = 1; i < (*this).threads.size(); i++) {
            pthread_cancel(threads[i]);
        }
    }
    this->stop();
    delete roomsCollection;

}

void Server::stop() {
    close(serverSocket);
}

int Server::getPortFromFile(string serverSettingsFileName) {
    try {
        ifstream fileInput(serverSettingsFileName.c_str()); // supposed to be fileName. Just for debug.
        if (fileInput == NULL) {
            perror("Error while open the server settings file");
        }
        string portString;
        getline(fileInput, portString);
        portString = portString.replace(0, sizeof("Port: ") - 1, "");
        stringstream ss(portString);
        int port = 0;
        ss >> port;
        return port;
    } catch (char * ex) {
        cout<<"failed to read setting file";
        exit(-1);

    }
}

vector<pthread_t> &Server::getThreads() {
    return threads;
}

int Server::getServerSocket() const {
    return serverSocket;
}