/**
 * ConsolePrinter class.
 * prints messages to console
 */
#ifndef REVERSITESTS_CONSOLEPRINTER_H
#define REVERSITESTS_CONSOLEPRINTER_H


#include "Printer.h"
#include "IGame.h"
#include <iostream>
using namespace std;

class ConsolePrinter : public Printer {
public:
    /**
     * constructor.
     */
    ConsolePrinter() {}
    /**
     * printCurrentBoard function.
     */
    void printCurrentBoard();
    /**
     * printBoard function.
     * @param board - game board
     */
    void printBoard(Board *board);
    /**
     * noPossibleMovesForBothPlayers function.
     */
    void noPossibleMovesForBothPlayers();
    /**
     * noPossibleMovesForCurrentPlayer function.
     */
    void noPossibleMovesForCurrentPlayer();
    /**
     * waitForOtherPlayerMove function.
     */
    void waitForOtherPlayerMove();
    /**
     * announceWinner function
     * @param board - board of game
     * @param myType - black or white
     */
    void announceWinner(Board* board, Board::Cell myType);
    /**
     * announceWhoPlayNow function.
     * @param currPlayer - curr player type
     */
    void announceWhoPlayNow(Player* currPlayer);
    /**
     * announceWhoMadeAMove function
     * @param row - row in board
     * @param col - col in board
     * @param opponentType - black or white
     */
    void announceWhoMadeAMove(int row, int col, Board::Cell opponentType);
    /**
     * printPossibleMoves function
     * @param options - optional moves
     */
    void printPossibleMoves(vector<pair<int, int> > options);
    /**
     * enterYourMove function
     */
    void enterYourMove();
    /**
     * illegalMoveInput function
     */
    void illegalMoveInput();
    /**
     * illegalMoveInputFormat function
     */
    void illegalMoveInputFormat();
    /**
     * mainMenu function
     * @return
     */
    string mainMenu();
    /**
     * invalidInputMainMenu function.
     */
    void invalidInputMainMenu();
    /**
     * errorConnectingToServerAndExitMsg function.
     * @param msg - message
     */
    void errorConnectingToServerAndExitMsg(const char *msg);
    /**
     * remoteGameWelcomeMsg function
     */
    void remoteGameWelcomeMsg();
    /**
     * remoteGameMainMenu function
     * @return remote game main menu
     */
    string remoteGameMainMenu();
    /**
     * enterNameForNewRoom function
     * @return name of room
     */
    string enterNameForNewRoom();
    /**
     * newRoomWasCreated function
     * @param name of room
     */
    void newRoomWasCreated(string name);
    /**
     * requestWasRejectedByServer function
     */
    void requestWasRejectedByServer();
    /**
     * noExistingRooms function
     */
    void noExistingRooms();
    /**
     * printJoinGameRooms function
     * @param rooms of game
     * @return string
     */
    string printJoinGameRooms(vector<string> rooms);
    /**
     * joinedToRoom function
     * @param name of room
     */
    void joinedToRoom(string name);
    /**
     * printGameRooms function
     * @param rooms - vector of rooms
     */
    void printGameRooms(vector<string> rooms);
    /**
     * connectedToServer function
     */
    void connectedToServer();
    /**
     * destructor
     */
    ~ConsolePrinter();
};


#endif //REVERSITESTS_CONSOLEPRINTER_H
