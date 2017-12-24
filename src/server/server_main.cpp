
#include "Server.h"


using namespace std;

/*void la(vector<string> &d) {
    d.push_back("la");
}*/

int main() {
/*vector<string> d;
    d.push_back("liz");
    la(d);*/
    int port = Server::getPortFromFile("ServerPort.txt");
    Server server(port);
//    vector<string> splitCommands = server.splitCommand("play <7> <8>");
    try {
        server.start();
    } catch (const char* ex) {
        cout <<"Cannot start server. Reason: " << ex <<endl;
        exit(-1);
    }
    return 0;
}


