/**
 * Printer class
 */
#ifndef REVERSITESTS_PRINTER_H
#define REVERSITESTS_PRINTER_H

#include "Board.h"
#include "Player.h"

class Printer {
public:
    /**
     * constructor.
     */
    Printer() {}
    /**
     * printCurrentBoard function.
     */
    virtual void printCurrentBoard() = 0;
    /**
     * printBoard function.
     * @param board - game board
     */
    virtual void printBoard(Board *board) = 0;
    /**
     * noPossibleMovesForBothPlayers function.
     */
    virtual void noPossibleMovesForBothPlayers() = 0;
    /**
     * noPossibleMovesForCurrentPlayer function.
     */
    virtual void noPossibleMovesForCurrentPlayer() = 0;
    /**
     * waitForOtherPlayerMove function.
     */
    virtual void waitForOtherPlayerMove() = 0;
    /**
     * announceWinner function
     * @param board - board of game
     * @param myType - black or white
     */
    virtual void announceWinner(Board* board, Board::Cell myType) = 0;
    /**
     * announceWhoPlayNow function.
     * @param currPlayer - curr player type
     */
    virtual void announceWhoPlayNow(Player* currPlayer) = 0;
    /**
     * announceWhoMadeAMove function
     * @param row - row in board
     * @param col - col in board
     * @param opponentType - black or white
     */
    virtual void announceWhoMadeAMove(int row, int col, Board::Cell opponentType) = 0;
    /**
     * printPossibleMoves function
     * @param options - optional moves
     */
    virtual void printPossibleMoves(vector<pair<int, int> > options) = 0;
    /**
     * enterYourMove function
     */
    virtual void enterYourMove() = 0;
    /**
     * illegalMoveInput function
     */
    virtual void illegalMoveInput() = 0;
    /**
     * illegalMoveInputFormat function
     */
    virtual void illegalMoveInputFormat() = 0;
    /**
    * mainMenu function
    * @return
    */
    virtual string mainMenu() = 0;
    /**
     * invalidInputMainMenu function.
     */
    virtual void invalidInputMainMenu() = 0;
    /**
     * errorConnectingToServerAndExitMsg function.
     * @param msg - message
     */
    virtual void errorConnectingToServerAndExitMsg(const char *msg) = 0;
    /**
     * remoteGameWelcomeMsg function
     */
    virtual void remoteGameWelcomeMsg() = 0;
    /**
     * remoteGameMainMenu function
     * @return remote game main menu
     */
    virtual string remoteGameMainMenu() = 0;
    /**
     * enterNameForNewRoom function
     * @return name of room
     */
    virtual string enterNameForNewRoom() = 0;
    /**
     * newRoomWasCreated function
     * @param name of room
     */
    virtual void newRoomWasCreated(string name) = 0;
    /**
     * requestWasRejectedByServer function
     */
    virtual void requestWasRejectedByServer() = 0;
    /**
     * noExistingRooms function
     */
    virtual void noExistingRooms() = 0;
    /**
     * printJoinGameRooms function
     * @param rooms of game
     * @return string
     */
    virtual string printJoinGameRooms(vector<string> rooms) = 0;
    /**
     * joinedToRoom function
     * @param name of room
     */
    virtual void joinedToRoom(string name) = 0;
    /**
     * printGameRooms function
     * @param rooms - vector of rooms
     */
    virtual void printGameRooms(vector<string> rooms) = 0;
    /**
     * connectedToServer function
     */
    virtual void connectedToServer() = 0;
    /**
     * destructor
     */
    virtual ~Printer() {}
};



#endif //REVERSITESTS_PRINTER_H
