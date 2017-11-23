//
// Created by ori on 14/11/17.
// ID: 311492110
//
#include "Player.h"

Board::Cell Player::getType() {
    return this->type;
}

void Player::setType(Board::Cell newType) {
    this->type = newType;
}

pair<int, int> Player::getInput(vector< pair<int,int> > options, const Board* board, Board::Cell currentCellType, Board::Cell opponentCellType){}