//
// Created by ori on 23/12/17.
//

#include "ConsolePrinter.h"
#include <iostream>

void ConsolePrinter::printCurrentBoard() {
    cout << "Current board:" << endl;
}

void ConsolePrinter::printBoard(Board *board) {
    int size = board->getSize();
    cout << " |";
    for (int i = 0 ; i <  size; i++) {
        if (i < 9) {
            cout << " ";
        }
        cout << i + 1 << " |";
    }
    cout << endl;
    for (int i = 0 ; i <  2 + 4 * size ; i++) {
        cout << "-";
    }
    for (int i = 0 ; i <  size ; i++) {
        cout << endl << i + 1 << "|";
        for (int j = 0; j < size; j++) {
            cout << " ";
            switch(board->getCell(i,j)) {
                case Board::Empty:
                    cout << " ";
                    break;
                case Board::White:
                    cout << "O";
                    break;
                case Board::Black:
                    cout << "X";
                    break;
            }
            cout << " |";
        }
        cout << endl;
        for (int k = 0 ; k <  2 + 4 * size ; k++) {
            cout << "-";
        }
    }
    cout << endl;
}

void ConsolePrinter::noPossibleMovesForBothPlayers() {
    cout << "No Possible for both players." << endl;
}

void ConsolePrinter::noPossibleMovesForCurrentPlayer() {
    cout << "No possible moves. Play passes back to the other player. ";
    cout << "Press any key to continue." << endl;
    string keyToContinue;
    getline(cin, keyToContinue);
}

void ConsolePrinter::waitForOtherPlayerMove() {
    cout <<"Waiting to other player's move..."<< endl;
}

void ConsolePrinter::announceWinner(Board* board, Board::Cell myType) {
    int numOfWhites = 0;
    int numOfBlacks = 0;
    int size = board->getSize();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board->getCell(i, j) == Board::Black) {
                numOfBlacks++;
            } else if (board->getCell(i, j) == Board::White) {
                numOfWhites++;
            }
        }
    }
    if (numOfBlacks > numOfWhites) {
        if (myType == Board::Black) {
            cout << "Congratulations X! You Won!." << endl;
        } else {
            cout << "O you're such a LOSER!." << endl;

        }
    } else if (numOfWhites > numOfBlacks) {
        if (myType == Board::White) {
            cout << "Congratulations O! You Won!." << endl;
        } else {
            cout << "X you're such a LOSER!." << endl;
        }
    } else {
        cout << "It's a tie." << endl;
    }
}

void ConsolePrinter::announceWhoPlayNow(Player* currPlayer) {
    if (currPlayer->getType() == Board::Black) {
        cout << "X: It's your move." << endl;

    } else {
        cout << "O: It's your move." << endl;
    }
}

void ConsolePrinter::announceWhoMadeAMove(int row, int col, Board::Cell opponentType) {
    if (opponentType ==  Board::Black) {
        cout << "X played (" << row + 1 << "," << col + 1 << ")" << endl;
    } else {
        cout << "O played (" << row + 1 << "," << col + 1 << ")" << endl;
    }
}

void ConsolePrinter::printPossibleMoves(vector<pair<int, int> > options) {
    int i = 0;
    cout << "Your possible moves: ";
    cout << "(" << options[i].first + 1 << "," << options[i].second + 1 << ")";
    while (i + 1 < options.size()) {
        i++;
        cout << ",(" << options[i].first + 1 << "," << options[i].second + 1 << ")";
    }
}

void ConsolePrinter::enterYourMove() {
    cout << endl << "Please enter your move row,col:" << endl;
}

void ConsolePrinter::illegalMoveInput() {
    cout << "The move you chose is illegal. Try again." << endl;
}

void ConsolePrinter::illegalMoveInputFormat() {
    cout << "Wrong input format. Should be 'row,col'. Let's try again." << endl;
}

ConsolePrinter::~ConsolePrinter() {
}