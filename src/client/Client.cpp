
#include <sstream>
#include "Client.h"
using namespace std;
Client::Client(const char *serverIP, int serverPort):
        serverIP(serverIP), serverPort(serverPort),
        clientSocket(0) {
}

void Client::connectToServer() {
    // Create a socket point
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        throw "Error opening socket";
    }
    // Convert the ip string to a network address
    struct in_addr address;
    if (!inet_aton(serverIP, &address)) {
        throw "Can't parse IP address";
    }
    // Get a hostent structure for the given host address
    struct hostent *server;
    server = gethostbyaddr((const void *)&address, sizeof
            address, AF_INET);
    if (server == NULL) {
        throw "Host is unreachable";
    }
    // Create a structure for the server address
    struct sockaddr_in serverAddress;
    bzero((char *)&address, sizeof(address));
    serverAddress.sin_family = AF_INET;
    memcpy((char *)&serverAddress.sin_addr.s_addr, (char
    *)server->h_addr, server->h_length);
    // htons converts values between host and network byte orders
    serverAddress.sin_port = htons(serverPort);
    // Establish a connection with the TCP server
    if (connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error connecting to server";
    }
    cout << "Connecting to server..." << endl;
}

int Client::getType() {
    // Read the result from the server
    int result;
    int n;
    Board::Cell type;
    n = read(clientSocket, &result, sizeof(result));
    if (n == -1 || n == 0) {
        throw "Error reading result from socket";
    }
    return result;
}

pair<int,int> Client:: getMoveFromServer() {
    int n;
    int x;
    int y;
    n = read(clientSocket, &x, sizeof(x));
    if (n == -1 || n == 0) {
        throw "Error reading x from socket";
    }
    if (x == GAME_OVER) {
        return make_pair(x,x);
    }
    n = read(clientSocket, &y, sizeof(y));
    if (n == -1 || n == 0) {
        throw "Error reading y from socket";
    }
    return make_pair(x,y);
}


bool Client::sendStartNewGameRequest(string name) {
    string str = "start <";
    str.append(name);
    str.append(">");
    char msg[MSG_BUFFER_SIZE] = "";
    str.copy(msg, str.length());
    int n = write(clientSocket, msg, sizeof(msg));
    if (n == -1 || n == 0) {
        throw "Error writing start request to socket";
    }
    int res;
    n = read(clientSocket, &res, sizeof(res));
    if (n == -1 || n == 0) {
        throw "Error reading respond start request from socket";
    }
    if (res == 1) {
        return true;
    }
    return false;
}

vector<string> Client::getGamesList() {
    char msg[] = "list_games";
    int n = write(clientSocket, msg, sizeof(msg));
    if (n == -1 || n == 0) {
        throw "Error writing list_games request to socket";
    }
    int buffLength;
    n = read(clientSocket, &buffLength, sizeof(buffLength));
    if (n == -1 || n == 0) {
        throw "Error reading games list length from socket";
    }
    char buff[buffLength];
    n = read(clientSocket, buff, sizeof(buff));
    if (n == -1 || n == 0) {
        throw "Error reading games list from socket";
    }
    vector<string> GameList = getGameListFromString(buff);
    return GameList;
}

vector<string> Client::getGameListFromString(char *buff) {
    vector<string> gamesList;
    string str(buff);
    string name;
    int commaIndex;
    while (true) {
        commaIndex = str.find(",");
        if (commaIndex == -1) {
            gamesList.push_back(str);
            break;
        }
        name = str.substr(0, commaIndex);
        gamesList.push_back(name);
        str = str.substr(commaIndex + 1, str.length());
    }
    return gamesList;
}

bool Client::sendJoinToGameRequest(string name) {
    string str = "join <";
    str.append(name);
    str.append(">");
    char msg[MSG_BUFFER_SIZE] = "";
    str.copy(msg, str.length());
    int n = write(clientSocket, msg, sizeof(msg));
    if (n == -1 || n == 0) {
        throw "Error writing join to game request to socket";
    }
    int res;
    n = read(clientSocket, &res, sizeof(res));
    if (n == -1 || n == 0) {
        throw "Error reading join to game respond from socket";
    }
    if (res == 1) {
        return true;
    }
    return false;
}

void Client::sendCloseGameRequest(string name) {
    string str = "close <";
    str.append(name);
    str.append(">");
    char msg[MSG_BUFFER_SIZE] = "";
    str.copy(msg, str.length());
    int n = write(clientSocket, msg, sizeof(msg));
    if (n == -1) {
        throw "Error writing close game request to socket";
    }
}

void Client::sendPlayCommand(int x, int y) {
    string str = "play <";
    stringstream ss;
    ss << x;
    str.append(ss.str());
    str.append("><");
    ss.str("");
    ss << y;
    str.append(ss.str());
    str.append(">");

    char msg[MSG_BUFFER_SIZE] = "";
    str.copy(msg, str.length());
    int n = write(clientSocket, msg, sizeof(msg));
    if (n == -1 || n == 0) {
        throw "Error writing play command to socket";
    }
}

void Client::GetIntoGameRoom(string &roomName, Printer* printer) {
    string choice;
    printer->remoteGameWelcomeMsg();
    while (true) {
        choice = printer->remoteGameMainMenu();
        if (choice == "1") {
            choice = printer->enterNameForNewRoom();
            if (this->sendStartNewGameRequest(choice)) {
                printer->newRoomWasCreated(choice);
                roomName.assign(choice);
                return;
            } else {
                printer->requestWasRejectedByServer();
                continue;
            }
        } else if (choice == "2") {
            vector<string> rooms = this->getGamesList();
            if (rooms[0] == "") {
                printer->noExistingRooms();
                continue;
            }
            choice = printer->printJoinGameRooms(rooms);
            if (this->sendJoinToGameRequest(choice)) {
                printer->joinedToRoom(choice);
                roomName.assign(choice);
                return;
            } else {
                printer->requestWasRejectedByServer();
                continue;
            }
        } else if (choice == "3") {
            vector<string> rooms = this->getGamesList();
            if (rooms[0] == "") {
                printer->noExistingRooms();
                continue;
            }
            printer->printGameRooms(rooms);
            continue;
        } else {
            printer->invalidInputMainMenu();
        }
    }
}

Client::~Client() {
    delete[] this->serverIP;
}