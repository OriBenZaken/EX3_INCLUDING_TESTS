//
// Created by ori on 27/10/17.
// ID: 311492110
//
#include <iostream>
#include <stdexcept>
#include "TwoPlayersOneComputerGame.h"
using namespace std;

void TwoPlayersOneComputerGame::run() {
    cout << "Current board:" << endl;
    this ->board->print();
    while (this->status != GameOver) {
        announceWhoPlayNow();
        vector< pair<int, int> > moves = gameLogic->possibleMoves(currPlayer->getType(), otherPlayer->getType());
        if (moves.empty()) {
            // No possible moves for both players. TwoPlayersOneComputerGame Over.
            if (this->status == NoPossibleMoves) {
                cout << "No Possible for both players." << endl;
                this->status = GameOver;
                break;
            }
            cout << "No possible moves. Play passes back to the other player. ";
            cout << "Press any key to continue." << endl;
            char keyToContinue;
            cin >> keyToContinue;
            switchCurrPlayer();
            this->status = NoPossibleMoves;
            continue;
        } else {
            this->status = Playing;
            pair <int, int> chosenMove = currPlayer->getInput(moves, this->board, currPlayer->getType(), otherPlayer->getType());
            //this->gameLogic->setBoard(board);
            this->gameLogic->makeMove(chosenMove.first, chosenMove.second, currPlayer->getType(), otherPlayer->getType());
            announceWhoMadeAMove(chosenMove.first, chosenMove.second);
            switchCurrPlayer();
            cout << "Current board:" << endl;
            this ->board->print();
            if (this->board->getNumOfEmptyCells() == 0) {
                this->status = GameOver;
            }
        }
    }
    announceWinner();
}

//todo: check if this is working, appearntly not
void TwoPlayersOneComputerGame::switchCurrPlayer() {
    Player* temp = currPlayer;
    currPlayer = otherPlayer;
    otherPlayer = temp;
}

void TwoPlayersOneComputerGame::announceWinner() {
    int numOfWhites = 0;
    int numOfBlacks = 0;
    int size = this->board->getSize();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (this->board->getCell(i, j) == Board::Black) {
                numOfBlacks++;
            } else if (this->board->getCell(i, j) == Board::White) {
                numOfWhites++;
            }
        }
    }
    if (numOfBlacks > numOfWhites) {
        cout << "Congratulations X! You Won!." << endl;
    } else if (numOfWhites > numOfBlacks) {
        cout << "Congratulations O! You Won!." << endl;
    } else {
        cout << "It's a tie." << endl;
    }
}
void TwoPlayersOneComputerGame::announceWhoPlayNow() {
    if (this->currPlayer->getType() == Board::Black) {
        cout << "X: It's your move." << endl;

    } else {
        cout << "O: It's your move." << endl;
    }
}

void TwoPlayersOneComputerGame::announceWhoMadeAMove(int row, int col) {
    if (currPlayer->getType() ==  Board::Black) {
        cout << "X played (" << row + 1 << "," << col + 1 << ")" << endl;
    } else {
        cout << "O played (" << row + 1 << "," << col + 1 << ")" << endl;
    }
}

TwoPlayersOneComputerGame::~TwoPlayersOneComputerGame() {
    delete this->gameLogic;
    delete (*this).currPlayer;
    delete (*this).otherPlayer;
}