#include "Server.h"


using namespace std;
#define  MAX_CONNECTED_CLIENTS 2

Server::Server(int port): port(port), serverSocket(0) {
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
    cout <<"Waiting for client connections..."<<endl;
    //inform types
    int clientSocket1 = getClientSocket();
    int result = WAITING;
    //inform player 1 that we are waiting to other player
    int n = write(clientSocket1,&result,sizeof(result));
    if (n ==-1) {
        cout <<"Error writing to socket" <<endl;
        return;
    }
    int clientSocket2 = getClientSocket();
    //inform both players about their types!
    result = BLACK_TYPE;
    n = write(clientSocket1,&result,sizeof(result));
    if (n ==-1) {
        cout <<"Error writing to socket" <<endl;
        return;
    }
    result = WHITE_TYPE;
    n = write (clientSocket2,&result,sizeof(result));
    if (n ==-1) {
        cout <<"Error writing to socket" <<endl;
        return;
    }
    handleClient(clientSocket1,clientSocket2);
    //reach this point if game ended
    close(clientSocket1);
    close(clientSocket2);


}

int Server::getClientSocket() {
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

void Server::handleClient(int clientSocket1, int clientSocket2) {
    int x;
    int y;
    int gameStatus;
    int currentClientSocket = clientSocket1;
    int otherClientSocket = clientSocket2;
    while (true) {
        //take move from current player
        int n = read(currentClientSocket, &x, sizeof(x));
        if (n==-1) {
            cout << "Error reading x";
            return;
        }
        n = read(currentClientSocket,&y,sizeof(y));
        if (n ==-1) {
            cout <<"Error reading y" <<endl;
            return;
        }
        if ((x == GAME_OVER && y ==GAME_OVER)) {
            gameStatus = GAME_OVER;
            n = write(otherClientSocket,&gameStatus,sizeof(gameStatus));
            // notify other player the game is over
            if (n ==-1) {
                cout <<"Error writing to socket" <<endl;
                return;
            }
            //end while loop!! end of game
            return;
        }
        gameStatus = KEEP_PLAYING;
        n = write(otherClientSocket,&gameStatus,sizeof(gameStatus));
        if (n ==-1) {
            cout <<"Error writing to socket" <<endl;
            return;
        }
        //inform opponent about selected move
        n = write(otherClientSocket,&x,sizeof(x));
        if (n ==-1) {
            cout <<"Error writing to socket" <<endl;
            return;
        }
        n = write(otherClientSocket,&y,sizeof(y));
        if (n ==-1) {
            cout <<"Error writing to socket" <<endl;
            return;
        }
        //read game status after one move
        n = read(otherClientSocket,&gameStatus,sizeof(gameStatus));
        if (n ==-1) {
            cout <<"Error writing to socket" <<endl;
            return;
        }
        if (gameStatus == GAME_OVER) {
            return;
        }
        swapClients(&currentClientSocket, &otherClientSocket);
    }
}

void Server::swapClients(int * current, int* opponent) {
    int temp = *current;
    *current = *opponent;
    *opponent = temp;
}


void Server::stop() {
    close(serverSocket);
}
