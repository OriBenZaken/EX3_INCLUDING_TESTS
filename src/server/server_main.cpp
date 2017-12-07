
#include "Server.h"

using namespace std;

int main() {

    int port = Server::getPortFromFile("ServerIPAndPort.txt");
    Server server(port);
    try {
        server.start();
    } catch (const char* ex) {
        cout <<"Cannot start server. Reason: " << ex <<endl;
        exit(-1);
    }
    return 0;
}