
#include "Server.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
    Server server(8003);
    try {
        server.start();
    } catch (const char* ex) {
        cout <<"Cannot start server. Reason: " << ex <<endl;
        exit(-1);
    }
    return 0;
}