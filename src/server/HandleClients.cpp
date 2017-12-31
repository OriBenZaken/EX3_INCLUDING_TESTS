
#include "HandleClients.h"

void* HandleClients::handleClient(void* arguments) {
    Server::ThreadArgs *args = (Server::ThreadArgs*) arguments;
    int clientSocket1 = args->clientSocket1;
    int clientSocket2 = args->clientSocket2;
    RoomsCollection* roomsCollection = args->roomsCollection;
    vector<Room>& rooms = (*roomsCollection).getRooms();
    pthread_mutex_t &count_mutex = (*roomsCollection).getCount_mutex();
    int currentClientSocket = clientSocket1;
    int otherClientSocket = clientSocket2;
    while (true) {
        //take move from current player
        string command = readCommandFromClient(currentClientSocket);
        vector<string> splittedCommand = splitCommand(command);
        CommandsManager commandsManager(currentClientSocket);
        if (splittedCommand.at(0).compare("close")==0) {
            break;
        }
        commandsManager.executeCommand(splittedCommand.at(0),splittedCommand,rooms,count_mutex);
        swapClients(&currentClientSocket, &otherClientSocket);
    }
}

void HandleClients::swapClients(int * current, int* opponent) {
    int temp = *current;
    *current = *opponent;
    *opponent = temp;
}



void* HandleClients::acceptClient(void* arguments) {
    Server::ThreadArgs *args = (Server::ThreadArgs *) arguments;
    Server* server = args->server;
    int serverSocket = (*server).getServerSocket();
    while (true) {
        cout << "Waiting for client connections..." << endl;
        //inform types
        int clientSocket = getClientSocket(serverSocket);
        args->clientSocket1 = clientSocket;

        /*pthread_create(&pthread, NULL, HandleClients::acceptClient, (void *) &threadArgs);
        (*this).threads.push_back(pthread);*/

        pthread_t pthread;
        pthread_create(&pthread, NULL,HandleClients::preGameRequests,args);
        (*server).getThreads().push_back(pthread);

       // pthread_detach(*(*server).getThreads().back());

    }
}



void * HandleClients::preGameRequests(void * arguments) {
    Server::ThreadArgs *args = (Server::ThreadArgs *) arguments;
    int clientSocket = args->clientSocket1;
    Server *server = args->server;
    RoomsCollection *roomsCollection = args->roomsCollection;
    vector<Room> &rooms = (*roomsCollection).getRooms();
    pthread_mutex_t &count_mutex = (*roomsCollection).getCount_mutex();
    //as long as no other user connected read client request and write to him
    CommandsManager commandsManagerPerClient(clientSocket);
    string command = "";
    while (true) {
        command = readCommandFromClient(clientSocket);
        vector<string> splitedCommand = splitCommand(command);
        int result = ERROR;
        if (splitedCommand.size() != 0) {
            result = commandsManagerPerClient.executeCommand(splitedCommand.at(0), splitedCommand, rooms, count_mutex);
        }
        //stop running the while loop
        if (command.compare("list_games") != 0 && result == VALID) {
            break;//end handle of this client for now until game starts
        }
    }
    //continue thread of accept
    pthread_mutex_lock(&count_mutex);
    for (int i = 0; i < rooms.size(); i++) {
        if (rooms.at(i).getRoomStatus() == Room::TwoPlayersConnected) {
            rooms.at(i).setRoomStatus(Room::Running);
            args->clientSocket2 = rooms.at(i).getSecondClientSocket();
            args->clientSocket1 = rooms.at(i).getFirstClientSocket();
            pthread_t pthread;
            pthread_create(&pthread, NULL, HandleClients::handleClient, args);
            //pthread_detach(*(*server).getThreads().back());
            (*server).getThreads().push_back(pthread);


        }
    }
    pthread_mutex_unlock(&count_mutex);
}




string HandleClients::readCommandFromClient(int clientSocket){
    char commandCharArr[MSG_SIZE];
    int n = read(clientSocket, commandCharArr, sizeof(commandCharArr));
    if (n == -1) {
        cout << "Error reading command";
        return "";
    }
    //convert from char arr to string
    stringstream stringStream;
    stringStream << commandCharArr;
    return stringStream.str();
}



vector<string> HandleClients::splitCommand(string command){
    vector<string> splitedCommand;
    //list_games
    if (command.compare("list_games")==0) {
        splitedCommand.push_back("list_games");
        return splitedCommand;
    }

    std::istringstream ss(command);
    std::string token;

    while(std::getline(ss, token, '<')) {
        splitedCommand.push_back(token);
    }
    for (int i=0; i<splitedCommand.size();i++){
        string item;
        for (int j=0; j<splitedCommand.at(i).size();j++) {
            if(splitedCommand.at(i).at(j)!='>' && splitedCommand.at(i).at(j)!= ' ') {
                item += splitedCommand.at(i).at(j);
            }
        }
        splitedCommand.at(i) = item;
    }
}


int HandleClients::getClientSocket(int serverSocket) {
    //define the client socket's structures
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen = sizeof(clientAddress);
    bzero((void *) &clientAddress, sizeof(clientAddress));
    //accept a new client connection
    int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddressLen);
    cout <<"Client connected" <<endl;
    if (clientSocket==-1) {
        throw "Error on accept";
    }
    return clientSocket;
}