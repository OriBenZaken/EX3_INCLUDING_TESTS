
#include "Server.h"


using namespace std;

/**
 * main func of server.
 * runs the server
 * @return 0
 */
int main() {

    int port = Server::getPortFromFile("ServerPort.txt");
    Server server(port);
    try {
        server.start();
    } catch (const char* ex) {
        cout <<"Cannot start server. Reason: " << ex <<endl;
        exit(-1);
    }
    return 0;
}


