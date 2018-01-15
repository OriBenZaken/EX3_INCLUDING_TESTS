#include "Server.h"
#include "ThreadPool.h"


Server::Server(int port): port(port), serverSocket(0), numberOfConnectedClients(0) {
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
    ThreadArgs threadArgs;
    RoomsCollection *roomsCollection = new RoomsCollection();
    threadArgs.roomsCollection = roomsCollection;
    threadArgs.server = this;
    ThreadPool pool(THREADS_NUM);
    threadArgs.pool = &pool;
    vector<Task*> tasks;
    threadArgs.tasks = &tasks;
    Task* task = new Task(HandleClients::acceptClient,(void *) &threadArgs);
    tasks.push_back(task);
    pool.addTask(task);

    string exit;
    cin >> exit;
    if (exit.compare("exit") == 0) {
        for (int i = 0; i < roomsCollection->getRooms().size(); i++) {
            switch (roomsCollection->getRooms().at(i).getRoomStatus()) {
                case Room::Running:
                case Room::TwoPlayersConnected:
                case Room::Stopped:
                    close(roomsCollection->getRooms().at(i).getFirstClientSocket());
                    close(roomsCollection->getRooms().at(i).getSecondClientSocket());
                    break;
                case Room::WaittingToOtherPlayer:
                    close(roomsCollection->getRooms().at(i).getFirstClientSocket());
                    break;

            }

        }
        pool.terminate();

        for (int i = 0; i < tasks.size(); i++) {
            delete tasks[i];
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


int Server::getServerSocket() const {
    return serverSocket;
}