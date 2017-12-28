//
// Created by ori on 23/12/17.
//

#ifndef REVERSITESTS_CONSOLEPRINTER_H
#define REVERSITESTS_CONSOLEPRINTER_H


#include "Printer.h"
using namespace std;

class ConsolePrinter : public Printer {
public:
    //todo: add comments
    ConsolePrinter() {}
    void printCurrentBoard();
    void printBoard(Board *board);
    void noPossibleMovesForBothPlayers();
    void noPossibleMovesForCurrentPlayer();
    void waitForOtherPlayerMove();
    void announceWinner(Board* board, Board::Cell myType);
    void announceWhoPlayNow(Player* currPlayer);
    void announceWhoMadeAMove(int row, int col, Board::Cell opponentType);
    void printPossibleMoves(vector<pair<int, int> > options);
    void enterYourMove();
    void illegalMoveInput();
    void illegalMoveInputFormat();
    string mainMenu();
    void invalidInputMainMenu();
    void errorConnectingToServerAndExitMsg(const char *msg);
    void remoteGameWelcomeMsg();
    string remoteGameMainMenu();
    string enterNameForNewRoom();
    void newRoomWasCreated(string name);
    void requestWasRejectedByServer();
    void noExistingRooms();
    string printJoinGameRooms(vector<string> rooms);
    void joinedToRoom(string name);
    void printGameRooms(vector<string> rooms);
    void connectedToServer();
    ~ConsolePrinter();
};


#endif //REVERSITESTS_CONSOLEPRINTER_H
