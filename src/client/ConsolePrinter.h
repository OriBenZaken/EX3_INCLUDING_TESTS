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
    ~ConsolePrinter();
};


#endif //REVERSITESTS_CONSOLEPRINTER_H
