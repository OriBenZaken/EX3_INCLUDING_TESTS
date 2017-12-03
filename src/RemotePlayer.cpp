//
// Created by liz on 03/12/17.
//

#include "RemotePlayer.h"

pair<int, int> RemotePlayer:: getInput(vector< pair<int,int> > options, const Board* board,
                        Board::Cell currentCellType, Board::Cell opponentCellType) {
    /*//inform opponent by server that client is choosing move
    //todo:*/
    pair<int,int> selectedMove = this->humanPlayer.getInput(options, board, currentCellType, opponentCellType);
    //inform server that this player chose this option
    client->sendMoveToServer(selectedMove.first,selectedMove.second);
    return selectedMove;



}
