

#include "HumanPlayer.h"


pair<int, int> HumanPlayer::getInput(vector< pair<int,int> > options, const Board* board,
                        Board::Cell currentCellType, Board::Cell opponentCellType) {
    this->printer->printPossibleMoves(options);
    string move;
    int row = 0, col = 0;
    while (true) {
        this->printer->enterYourMove();
        getline(cin,move);
        try {
            unsigned long index = move.find(',');
            if (index == -1) {
                throw std::invalid_argument("Bad argument");
            }
            istringstream(move.substr(0, (int)index)) >> row;
            istringstream(move.substr((int)index + 1 , move.size() - 2)) >> col;
        } catch (...) {
            this->printer->illegalMoveInputFormat();
            continue;
        }
        row--, col--;
        if (isValidMove(options, row, col)) {
            break;
        } else {
            this->printer->illegalMoveInput();
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