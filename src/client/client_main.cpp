
#include "Client.h"
#include "TwoPlayersOneComputerGame.h"
#include "RemoteGame.h"
#include "Printer.h"
#include "ConsolePrinter.h"

#define SIZE 6
using namespace std;
//main function, runs the program
int main() {
    Printer* printer = new ConsolePrinter();

    cout<<"Hello!"<<endl<<"Please choose one of the following options:"<<endl;
    cout<<"1. a human local player."<<endl;
    cout<<"2. an AI player."<<endl;
    cout<<"3. a remote player."<<endl;
    IGame:: PlayersType playersType;
    string input = "";
    //take selected game from player
    do {
        getline(cin,input);
        if (input.compare("1") == 0) {
            playersType = IGame::Humans;
        } else if (input.compare("2") == 0) {
            playersType = IGame::HumanVSAI;
        }else if (input.compare("3") ==0) {
            playersType = IGame::RemoteMode;
        } else {
            cout<<"Please choose correct option."<<endl;
        }
    }while (input.compare("1") != 0 && input.compare("2") != 0 && input.compare("3") != 0);
    Board b(SIZE);
    b.initialize();
    //create game
    IGame* game;
    if (playersType == IGame::Humans || playersType ==IGame::HumanVSAI) {
        game = new TwoPlayersOneComputerGame(&b, playersType, printer);
        game->run();
        delete game;
        return 0;
    }
    try {
        game = new RemoteGame(&b, "ServerIPAndPort.txt", printer);
        game->run();

    } catch (const char *msg) {
        cout << "Failed to connect to server. Reason:" << msg << endl;
        exit(-1);
    }

    delete game;
}