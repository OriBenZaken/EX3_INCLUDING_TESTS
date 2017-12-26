//
// Created by liz on 24/12/17.
//

#include "ServerOperations.h"




void* ServerOperations::handleClient(void* arguments) {
    cout <<"enter handleClient"<<endl;
    Server::ThreadArgs *args = (Server::ThreadArgs*) arguments;
    int clientSocket1 = args->clientSocket1;
    int clientSocket2 = args->clientSocket2;
    Server* server = args->server;
    vector<Room>& rooms = (*server).getRooms();


    int x;
    int y;
    int gameStatus;
    int currentClientSocket = clientSocket1;
    int otherClientSocket = clientSocket2;
    cout<<"current clientsocket "<<clientSocket1<<endl;
    cout<<"opposite clientsocket "<<clientSocket2<<endl;



    while (true) {
        //take move from current player
        cout<<"handel client is about to call readCommandFromClient: "<<endl;
        string command = readCommandFromClient(currentClientSocket);
        cout<<"handel client recieved this command: "<<command<<endl;
        vector<string> splittedCommand = splitCommand(command);
        CommandsManager commandsManager(currentClientSocket);
        if (splittedCommand.at(0).compare("close")==0) {
            break;
        }
        commandsManager.executeCommand(splittedCommand.at(0),splittedCommand,rooms);
        swapClients(&currentClientSocket, &otherClientSocket);
    }







   /* int x;
    int y;
    int gameStatus;
    int currentClientSocket = clientSocket1;
    int otherClientSocket = clientSocket2;
    *//*CommandsManager commandsManagerCurrentClient(clientSocket1);
    CommandsManager commandsManagerOtherClient(clientSocket2);*//*
    while (true) {
        //take move from current player
        vector<string> splittedCommand = splitCommand(readCommandFromClient(currentClientSocket));
        CommandsManager commandsManager(currentClientSocket);
        if (splittedCommand.at(0).compare("close")==0) {
            break;
        }
        commandsManager.executeCommand(splittedCommand.at(0),splittedCommand,rooms);
        swapClients(&currentClientSocket, &otherClientSocket);
    }*/
}

void ServerOperations::swapClients(int * current, int* opponent) {
    int temp = *current;
    *current = *opponent;
    *opponent = temp;
   /* CommandsManager temp1 = *commandsManagerCurrentClient;
    *commandsManagerCurrentClient = *commandsManagerOtherClient;
    *commandsManagerOtherClient = temp1;*/
}



void* ServerOperations::acceptClient(void* arguments) {
    cout <<"enter acceptClient"<<endl;

    Server::ThreadArgs *args = (Server::ThreadArgs *) arguments;
    Server* server = args->server;
    int serverSocket = (*server).getServerSocket();
    while (true) {
        cout << "Waiting for client connections..." << endl;
        //inform types
        int clientSocket = getClientSocket(serverSocket);
        cout << "got client socket: " << clientSocket << endl;

        //todo: create preGameRequests thread

        args->clientSocket1 = clientSocket;
        cout << "args->clientSocket1: " << args->clientSocket1 << endl;
        (*server).getThreads().push_back(0);
        cout << "creating pthread" << endl;
        pthread_create(&(*server).getThreads().back(), NULL,ServerOperations::preGameRequests,args);


    }
}



void * ServerOperations::preGameRequests(void * arguments) {
    cout <<"enter preGameRequests"<<endl;

    Server::ThreadArgs * args = (Server::ThreadArgs *) arguments;
    int clientSocket = args->clientSocket1;
    Server *server = args->server;
    vector<Room> &rooms = (*server).getRooms();
    pthread_mutex_t &count_mutex = (*server).getCount_mutex();

    cout << "recieved in preGame client socket: " << clientSocket << endl;

    //todo: initialize params of this function

    //as long as no other user connected read client request and write to him
    CommandsManager commandsManagerPerClient(clientSocket);
    string command = "";
    while (true) {
        command = readCommandFromClient(clientSocket);
        //todo: to be deleted just for debug

        vector<string> splitedCommand = splitCommand(command);
        int result = ERROR;
        if (splitedCommand.size() != 0) {
            result = commandsManagerPerClient.executeCommand(splitedCommand.at(0), splitedCommand, rooms);
        }

        //stop running the while loop
        if (command.compare("list_games") != 0 && result == VALID) {
            break;//end handle of this client for now until game starts
        }
    }
    //todo: create handle client thread after join from here!
   // if (command.compare("join") == 0)
        //continue thread of accept
       // pthread_mutex_lock(&count_mutex);
    for (int i = 0; i < rooms.size(); i++) {
        if (rooms.at(i).getRoomStatus()==Room::TwoPlayersConnected) {
            //todo: create handle client of two client sockets
            rooms.at(i).setRoomStatus(Room::Running);
            args->clientSocket2 = rooms.at(i).getSecondClientSocket();
            args->clientSocket1 =rooms.at(i).getFirstClientSocket();
            (*server).getThreads().push_back(0);
            cout <<"we are on function preGameRequests, first client socket "<<args->clientSocket1<<"second client socket "<<args->clientSocket2 <<endl;
            pthread_create(&(*server).getThreads().back(), NULL, ServerOperations::handleClient, args);


        }
    }
   // pthread_mutex_unlock(&count_mutex);
}




string ServerOperations::readCommandFromClient(int clientSocket){
    cout <<"enter readCommandFromClient, want to talk to "<< clientSocket<<endl;
    char commandCharArr[MSG_SIZE];
    int n = read(clientSocket, commandCharArr, sizeof(commandCharArr));
    cout << n << endl;
    if (n == -1) {
        cout << "Error reading command";
        return "";
    }
    //convert from char arr to string
    stringstream stringStream;
    stringStream << commandCharArr;
    return stringStream.str();
    return "";
}



vector<string> ServerOperations::splitCommand(string command){
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
            cout <<splitedCommand.at(i).at(j);
            if(splitedCommand.at(i).at(j)!='>' && splitedCommand.at(i).at(j)!= ' ') {
                item += splitedCommand.at(i).at(j);
            }
        }
        splitedCommand.at(i) = item;
    }
}


int ServerOperations::getClientSocket(int serverSocket) {
    //define the client socket's structures
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen;
    //accept a new client connection
    int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddressLen);
    cout <<"Client connected" <<endl;
    if (clientSocket==-1) {
        throw "Error on accept";
    }
    return clientSocket;
}