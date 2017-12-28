//
// Created by ori on 23/12/17.
//

#ifndef REVERSITESTS_PRINTER_H
#define REVERSITESTS_PRINTER_H

#include "Board.h"
#include "Player.h"

class Printer {
public:
    Printer() {}
    virtual void printCurrentBoard() = 0;
    virtual void printBoard(Board *board) = 0;
    virtual void noPossibleMovesForBothPlayers() = 0;
    virtual void noPossibleMovesForCurrentPlayer() = 0;
    virtual void waitForOtherPlayerMove() = 0;
    virtual void announceWinner(Board* board, Board::Cell myType) = 0;
    virtual void announceWhoPlayNow(Player* currPlayer) = 0;
    virtual void announceWhoMadeAMove(int row, int col, Board::Cell opponentType) = 0;
    virtual void printPossibleMoves(vector<pair<int, int> > options) = 0;
    virtual void enterYourMove() = 0;
    virtual void illegalMoveInput() = 0;
    virtual void illegalMoveInputFormat() = 0;
    virtual string mainMenu() = 0;
    virtual void invalidInputMainMenu() = 0;
    virtual void errorConnectingToServerAndExitMsg(const char *msg) = 0;
    virtual void remoteGameWelcomeMsg() = 0;
    virtual string remoteGameMainMenu() = 0;
    virtual string enterNameForNewRoom() = 0;
    virtual void newRoomWasCreated(string name) = 0;
    virtual void requestWasRejectedByServer() = 0;
    virtual void noExistingRooms() = 0;
    virtual string printJoinGameRooms(vector<string> rooms) = 0;
    virtual void joinedToRoom(string name) = 0;
    virtual void printGameRooms(vector<string> rooms) = 0;
    virtual void connectedToServer() = 0;
    virtual ~Printer() {}
};



#endif //REVERSITESTS_PRINTER_H
