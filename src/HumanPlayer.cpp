//
// Created by ori on 14/11/17.
// ID: 311492110
//
#include <sstream>
#include "HumanPlayer.h"

pair<int, int> HumanPlayer::getInput(vector< pair<int,int> > options, const Board* board,
                        Board::Cell currentCellType, Board::Cell opponentCellType) {
    int i = 0;
    cout << "Your possible moves: ";
    cout << "(" << options[i].first + 1 << "," << options[i].second + 1 << ")";
    while (i + 1 < options.size()) {
        i++;
        cout << ",(" << options[i].first + 1 << "," << options[i].second + 1 << ")";
    }
    string move;
    int row = 0, col = 0;
    while (true) {
        cout << endl << "Please enter your move row,col:" << endl;
        getline(cin,move);
        try {
            unsigned long index = move.find(',');
            if (index == -1) {
                throw std::invalid_argument("Bad argument");
            }
            istringstream(move.substr(0, (int)index)) >> row;
            istringstream(move.substr((int)index + 1 , move.size() - 2)) >> col;
        } catch (...) {
            cout << "Wrong input format. Should be 'row,col'. Let's try again." << endl;
            continue;
        }
        row--, col--;
        if (isValidMove(options, row, col)) {
            break;
        } else {
            cout << "The move you chose is illegal. Try again." << endl;
        }
    }
    return make_pair(row, col);
}

bool HumanPlayer::isValidMove(vector<pair<int, int> > options, int row, int col) {
    for (int i = 0; i < options.size(); i++) {
        // user move exists in the options vector.
        if (options[i].first == row && options[i].second == col) {
            return true;
        }
    }
    return false;
}