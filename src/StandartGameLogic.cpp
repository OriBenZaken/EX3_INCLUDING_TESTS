//
// Created by ori on 24/10/17.
// ID: 311492110
//
#include <iostream>
#include "StandartGameLogic.h"
using namespace std;

vector< pair<int, int> > StandartGameLogic::possibleMoves(Board::Cell player, Board::Cell opponent) {
    vector< pair<int, int> > moves;
    int size = board->getSize();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // checks for every Empty cell if it is a possible move for the player.
            if (this->board->getCell(i, j) == Board::Empty) {
                bool ans = checkCell(i, j, player, opponent);
                // cell is a possible move
                if (ans) {
                    // adds cell indices to moves array.
                    moves.push_back(make_pair(i, j));
                }
            }
        }
    }
    return moves;
}

bool StandartGameLogic::checkCell(int row, int col,Board::Cell player,
                                  Board::Cell opponent) {
    int size = board->getSize();
    // empty cell has an opponent neighbor, up left direction
    if (row - 1 >= 0 && col -1 >=0 &&
            this->board->getCell(row - 1, col - 1) == opponent) {
        if (scanDirection(row - 1, col - 1, -1, -1, player)) {
            return true;

        }
    }
    // empty cell has an opponent neighbor, up direction
    if (row - 1 >= 0 && this->board->getCell(row - 1, col) == opponent) {
        if (scanDirection(row - 1, col, -1, 0, player)) {
            return true;
        }
    }
    // empty cell has an opponent neighbor, up right direction
    if (row - 1 >= 0 && col + 1 <= size - 1 &&
        this->board->getCell(row - 1, col + 1) == opponent) {
        if (scanDirection(row - 1, col + 1, -1, 1, player)) {
            return true;
        }
    }
    // empty cell has an opponent neighbor, left direction
    if (col - 1 >= 0 && this->board->getCell(row, col - 1) == opponent) {
        if (scanDirection(row, col - 1, 0, -1, player)) {
            return true;
        }
    }
    // empty cell has an opponent neighbor, right direction
    if (col + 1 <= size - 1 && this->board->getCell(row, col + 1) == opponent) {
        if (scanDirection(row, col + 1, 0, 1, player)) {
            return true;
        }
    }
    // empty cell has an opponent neighbor, down left right direction
    if (row + 1 <= size - 1 && col - 1 >= 0 &&
        this->board->getCell(row + 1, col - 1) == opponent) {
        if (scanDirection(row + 1, col - 1, 1, -1, player)) {
            return true;
        }
    }
    // empty cell has an opponent neighbor, down direction
    if (row + 1 <= size - 1 && this->board->getCell(row + 1, col) == opponent) {
        if (scanDirection(row + 1, col, 1, 0, player)) {
            return true;
        }
    }
    // empty cell has an opponent neighbor, down right direction
    if (row + 1 <= size - 1 && col + 1 <= size - 1 &&
        this->board->getCell(row + 1, col + 1) == opponent) {
        if (scanDirection(row + 1, col + 1, 1, 1, player)) {
            return true;
        }
    }
    return false;
}

bool StandartGameLogic::scanDirection(int row, int col, int rowDirection,
                                      int colDirection, Board::Cell player) {
    // a player's cell
    if (this->board->isIndexInBoard(row + rowDirection, col + colDirection) &&
        this->board->getCell(row + rowDirection, col + colDirection) == player) {
        return true;
    }
    // empty cell
    if (this->board->isIndexInBoard(row + rowDirection, col + colDirection) &&
        this->board->getCell(row + rowDirection, col + colDirection) == Board::Empty) {
        return false;
    }
    // an opponent's cell - keep checking recursively
    if (this->board->isIndexInBoard(row + rowDirection, col + colDirection)) {
        return scanDirection(row + rowDirection, col + colDirection, rowDirection, colDirection, player);
    }
    return false;
}

bool StandartGameLogic::makeMove(int row, int col, Board::Cell player, Board::Cell opponent) {
    if (this->board->getCell(row, col) != Board::Empty) {
        return false;
    }
    /* checks all 8 directions around the cell and if the direction is possible for move
     * flip all opponent's cells. */
    if (checkCell(row, col, player, opponent)) {
        this->board->setCell(row, col, player);
        // up left
        if (scanDirection(row - 1, col - 1, -1, -1, player)) {
            flipCells(row - 1, col - 1, -1, -1, opponent);
        }
        // up
        if (scanDirection(row - 1, col, -1, 0, player)) {
            flipCells(row - 1, col, -1, 0, opponent);
        }
        // up right
        if (scanDirection(row - 1, col + 1, -1, 1, player)) {
            flipCells(row - 1, col + 1, -1, 1, opponent);
        }
        // left
        if (scanDirection(row, col - 1, 0, -1, player)) {
            flipCells(row, col - 1, 0, -1, opponent);
        }
        // right
        if (scanDirection(row, col + 1, 0, 1, player)) {
            flipCells(row, col + 1, 0, 1, opponent);
        }
        // down left
        if (scanDirection(row + 1, col - 1, 1, -1, player)) {
            flipCells(row + 1, col - 1, 1, -1, opponent);
        }
        // down
        if (scanDirection(row + 1, col, 1, 0, player)) {
            flipCells(row + 1, col, 1, 0, opponent);
        }
        // down right
        if (scanDirection(row + 1, col + 1, 1, 1, player)) {
            flipCells(row + 1, col + 1, 1, 1, opponent);
        }
        return true;
    }
    return false;
}

void StandartGameLogic::flipCells(int row, int col, int rowDorection, int colDirection,
                                  Board::Cell opponent) {
    while (this->board->isIndexInBoard(row, col)) {
        if (this->board->getCell(row, col) == opponent) {
            this->board->flipCell(row, col);
        } else {
            return;
        }
        row += rowDorection;
        col += colDirection;
    }
}

Board * StandartGameLogic::getBoard() const {
    return (*this).board;
}

void StandartGameLogic::setBoard(Board *board) {
    (*this).board = board;
}
int StandartGameLogic::getScores(Board::Cell current, Board::Cell opponent) {
    int currentCunter = 0;
    int opponentCounter = 0;
    for (int i = 0; i < (*this).board->getSize(); i++) {
        for (int j = 0; j < (*this).board->getSize(); j++) {
            if ((*this).board->getCell(i, j) == current) {
                currentCunter++;
            } else if ((*this).board->getCell(i, j) == opponent) {
                opponentCounter++;
            }
        }
    }
    return (currentCunter-opponentCounter);
}