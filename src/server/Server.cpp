#include <fstream>
#include <sstream>
#include <algorithm>
#include "Server.h"
#include "stdlib.h"
#include "CommandsManager.h"
#include "ServerOperations.h"


using namespace std;
#define  MAX_CONNECTED_CLIENTS 2

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
    bzero((void*)&serverAdress, sizeof(serverAdress));
    serverAdress.sin_family = AF_INET;
    serverAdress.sin_addr.s_addr = INADDR_ANY;
    serverAdress.sin_port = htons(port);
    if (bind(serverSocket, (struct sockaddr*)&serverAdress, sizeof(serverAdress)) ==-1) {
        throw "Error on binding";
    }
    //start listening to incoming connections
    listen(serverSocket, MAX_CONNECTED_CLIENTS);
    //todo: to be exported to other thread
    Server::ThreadArgs threadArgs;
    threadArgs.server = this;
   /* (*this).threads.push_back(threadNum);
    pthread_create(&(*this).threads.back(), NULL,ServerOperations::acceptClient,(void *)&threadArgs);
*/

acceptClient();

    string exit;
    cin >> exit;
    if (exit.compare("exit")==0) {
        for(int i =0; i<(*this).rooms.size();i++) {
            int clientSocket = (*this).rooms.at(i).getFirstClientSocket();
          //  int n = write(clientSocket,EXIT, )
            //todo: how to inform all clients ??!
        }
    }

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



















///my threads:

void* Server::handleClient(int client1, int client2) {
    //ThreadArgs *args = (ThreadArgs*) clients1;
    int clientSocket1 = client1;
    int clientSocket2 = client2;
   // vector<Room>& rooms = args->rooms;

    int x;
    int y;
    int gameStatus;
    int currentClientSocket = clientSocket1;
    int otherClientSocket = clientSocket2;
    //commandsManager commandsManagerCurrentClient(clientSocket1);
    //CommandsManager commandsManagerOtherClient(clientSocket2);

    /*while (true) {
        //take move from current player
        vector<string> splittedCommand = splitCommand(readCommandFromClient(currentClientSocket));
        if (splittedCommand.at(0).compare("close")==0) {
            break;
        }
        commandsManagerCurrentClient.executeCommand(splittedCommand.at(0),splittedCommand,rooms);
        swapClients(&currentClientSocket, &otherClientSocket,
                    &commandsManagerCurrentClient, &commandsManagerOtherClient);
    }*/

    //int x;
    //int y;
    //int gameStatus;
    //int currentClientSocket = clientSocket1;
    //int otherClientSocket = clientSocket2;
    while (true) {
        int n;
        vector<string> splittedCommand = splitCommand(readCommandFromClient(currentClientSocket));
        cout << endl << splittedCommand[0] << endl;
        if (splittedCommand.at(0).compare("close")==0) {
            gameStatus = GAME_OVER;
            n = write(otherClientSocket,&gameStatus,sizeof(gameStatus));
            // notify other player the game is over
            if (n ==-1) {
                cout <<"Error writing to socket" <<endl;
                break;
            }
            break;
        }
        gameStatus = KEEP_PLAYING;
        //take move from current player
        n = read(currentClientSocket, &x, sizeof(x));
        if (n==-1) {
            cout << "Error reading x";
            break;
        }
        n = read(currentClientSocket,&y,sizeof(y));
        if (n ==-1) {
            cout <<"Error reading y" <<endl;
            break;
        }
        n = write(otherClientSocket,&gameStatus,sizeof(gameStatus));
        if (n ==-1) {
            cout <<"Error writing to socket" <<endl;
            break;
        }
        //inform opponent about selected move
        n = write(otherClientSocket,&x,sizeof(x));
        if (n ==-1) {
            cout <<"Error writing to socket" <<endl;
            break;
        }
        n = write(otherClientSocket,&y,sizeof(y));
        if (n ==-1) {
            cout <<"Error writing to socket" <<endl;
            break;
        }
        cout << endl << x << "," << y << endl;
        splittedCommand = splitCommand(readCommandFromClient(otherClientSocket));
        //read game status after one move
        n = read(otherClientSocket,&gameStatus,sizeof(gameStatus));
        if (splittedCommand.at(0).compare("close")==0) {
            gameStatus = GAME_OVER;
            break;
        }
        swapClients(&currentClientSocket, &otherClientSocket);
    }
}

void Server::swapClients(int * current, int* opponent) {
    int temp = *current;
    *current = *opponent;
    *opponent = temp;
}



void Server::acceptClient() {
    while (true) {
        cout << "Waiting for client connections..." << endl;
        //inform types
        int clientSocket = getClientSocket();

        //todo: create preGameRequests thread
        cout <<"about to call preGameRequests";
        (*this).preGameRequests(clientSocket);

    }
}



void * Server::preGameRequests(int clientSocket) {

    //todo: initialize params of this function
   // int clientSocket;

    cout <<"enter preGameRequests";
    //as long as no other user connected read client request and write to him
    CommandsManager commandsManagerPerClient(clientSocket);
    while (true) {

        string command = readCommandFromClient(clientSocket);
        //todo: to be deleted just for debug
        // command = "start <liz>";

        vector<string> splitedCommand = splitCommand(command);
        int result = ERROR;
        if (splitedCommand.size() != 0) {
            result = commandsManagerPerClient.executeCommand(splitedCommand.at(0), splitedCommand, (*this).rooms);
        }

        //stop running the while loop
        if (command.compare("list_games") != 0 && result == VALID) {
            break;//end handle of this client for now until game starts
        }
    }
        //todo: create handle client thread after join from here!
        cout <<"create handle client thread after join from here!r";
        //continue thread of accept
        /*pthread_mutex_t count_mutex;
        pthread_mutex_lock(&count_mutex);*/
        for (int i = 0; i < (*this).rooms.size(); i++) {
            if (rooms.at(i).getRoomStatus() == Room::TwoPlayersConnected) {
                //todo: create handle client of two client sockets
                (*this).handleClient(rooms.at(i).getFirstClientSocket(),rooms.at(i).getSecondClientSocket());

                 rooms.at(i).setRoomStatus(Room::Running);
            }
        }
       /* pthread_mutex_unlock(&count_mutex);*/


    //###############################################thread


}

string Server::readCommandFromClient(int clientSocket){
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



vector<string> Server::splitCommand(string command){
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


int Server::getClientSocket() {
    //define the client socket's structures
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen;
    //accept a new client connection
    int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddressLen);
    (*this).numberOfConnectedClients++;
    cout <<"Client connected" <<endl;
    if (clientSocket==-1) {
        throw "Error on accept";
    }
    return clientSocket;
}

int Server::getPort() const {
    return port;
}

int Server::getServerSocket() const {
    return serverSocket;
}

int Server::getNumberOfConnectedClients() const {
    return numberOfConnectedClients;
}

vector<Room> &Server::getRooms()  {
    return rooms;
}

vector<pthread_t> &Server::getThreads() {
    return threads;
}

int Server::getThreadNum() const {
    return threadNum;
}

pthread_mutex_t &Server::getCount_mutex() {
    return count_mutex;
}

