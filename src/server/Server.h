//
// Created by liz on 03/12/17.
//

#ifndef SERVERREVERSI_SERVER_H
#define SERVERREVERSI_SERVER_H
#define NO_MOVES -2
#define GAME_OVER -3
#define BLACK_TYPE 1
#define WHITE_TYPE 2
#define WAITING 0
#define KEEP_PLAYING -4

class Server {
public:
    Server(int port);
    void start();
    void stop();
private:
    int port;
    int serverSocket; //the socket's file descriptor
    void handleClient(int clientSocket1, int clientSocket2);
    int calc(int arg1, const char op, int arg2) const;
    int moveAnnouncment(int x, int y);
    int getClientSocket();
    int swapClients(int * current, int* opponent);



};
/*struct in_addr {
    unsigned long s_addr;
};*/
/*
struct sockaddr_in {
    short int sin_family;
    unsigned short int sin_port;
    struct in_addr sin_addr;
    unsigned char sin_zero[8];
};
//kflkfldkfldkf
*/

#endif //SERVERREVERSI_SERVER_H
