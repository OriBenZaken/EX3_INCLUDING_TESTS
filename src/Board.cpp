//
// Created by Ori Ben Zaken on 23/10/17.
// ID: 311492110
//
#include "Board.h"
#include <cstdlib>
using namespace std;

Board::Board(int size) : size(size) {
    try {
        this->board = new Cell*[size];
        for (int i = 0; i < size; i++) {
            board[i] = new Cell[size];
        }
    } catch (std::bad_alloc&) {
        cout << "Board: Memory allocation failure. Program must end." << endl;
        exit(1);
    }
}

Board::Board(const Board& boardTocopy){
    (*this).size = boardTocopy.size;
    //memory allocation
    try {
        (*this).board = new Cell*[size];
        for (int i = 0; i < size; i++) {
            (*this).board[i] = new Cell[size];
        }
    } catch (std::bad_alloc&) {
        cout << "Board: Memory allocation failure. Program must end." << endl;
        exit(1);
    }
    //copy each element
    for (int i=0; i<boardTocopy.size; i++) {
        for (int j = 0; j<boardTocopy.size; j++){
            (*this).board[i][j] = boardTocopy.board[i][j];
        }
    }
}

void Board::initialize() {
    // initializes every cell with a space.
    for (int i = 0; i < size; i++) {
       for (int j = 0; j < size; j++) {
           this->board[i][j] = Empty;
       }
    }
    // initializes the start mode of the white player and black player.
    // O represents the white player and X represents the black player.
    int startPos = size / 2 - 1;
    this->board[startPos][startPos] = White;
    this->board[startPos][startPos + 1] = Black;
    this->board[startPos + 1][startPos] = Black;
    this->board[startPos + 1][startPos + 1] = White;
}

void Board::print() const {
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
            switch(board[i][j]) {
                case Empty:
                    cout << " ";
                    break;
                case White:
                    cout << "O";
                    break;
                case Black:
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

Board::Cell Board::getCell(int row, int col) const {
    //cout<<"getcell "<<row<<col<<endl;
    return this->board[row][col];
}

void Board::flipCell(int row, int col) {
    if (this->board[row][col] == Black) {
        this->board[row][col] = White;
    } else if (this->board[row][col] == White) {
        this->board[row][col] = Black;
    }
}

int Board::getSize() {
    return this->size;
}

void Board::setCell(int row, int col, Cell player) {
    this->board[row][col] = player;
}

bool Board::isIndexInBoard(int row, int col) {
    return row >= 0 && col >= 0 && row <= this->size - 1 && col <= this->size -1;
}


int Board::getNumOfEmptyCells() const {
    int counter = 0;
    for(int i=0; i<(*this).size;i++) {
        for(int j=0; j<(*this).size; j++) {
            if ((*this).board[i][j]==Empty) {
                counter++;
            }
        }
    }
    return counter;
}

Board::~Board() {
    for (int i = 0; i < size; i++) {
        delete[] board[i];
    }
    delete[] board;
}
