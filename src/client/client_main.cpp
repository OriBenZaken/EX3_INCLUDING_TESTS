
#include "Client.h"
#include "TwoPlayersOneComputerGame.h"
#include "RemoteGame.h"
#include "Printer.h"
#include "ConsolePrinter.h"

#define SIZE 4
using namespace std;
//main function, runs the program
int main() {
    Printer* printer = new ConsolePrinter();

    IGame:: PlayersType playersType;
    string input = "";
    //take selected game from player
    do {
        input = printer->mainMenu();
        if (input.compare("1") == 0) {
            playersType = IGame::Humans;
        } else if (input.compare("2") == 0) {
            playersType = IGame::HumanVSAI;
        }else if (input.compare("3") ==0) {
            playersType = IGame::RemoteMode;
        } else {
            printer->invalidInputMainMenu();
        }
    } while (input.compare("1") != 0 && input.compare("2") != 0 && input.compare("3") != 0);
    Board b(SIZE);
    b.initialize();
    //create game
    IGame* game;
    if (playersType == IGame::Humans || playersType ==IGame::HumanVSAI) {
        game = new TwoPlayersOneComputerGame(&b, playersType, printer);
        game->run();
        delete game;
        delete printer;
        return 0;
    }
    try {
        game = new RemoteGame(&b, "ServerIPAndPort.txt", printer);
    } catch (const char *msg) {
        printer->errorConnectingToServerAndExitMsg(msg);
        delete printer;
        return 0;
    }
    try {
        game->run();
    } catch (const char *msg) {
        printer->errorConnectingToServerAndExitMsg(msg);
        delete game;
    }
    delete printer;
    return 0;
}