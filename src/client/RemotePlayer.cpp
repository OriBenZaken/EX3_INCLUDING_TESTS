
#include "RemotePlayer.h"

pair<int, int> RemotePlayer:: getInput(vector< pair<int,int> > options, const Board* board,
                                       Board::Cell currentCellType, Board::Cell opponentCellType) {
    //inform opponent by server that client is choosing move
    pair<int,int> selectedMove = this->humanPlayer.getInput(options, board, currentCellType, opponentCellType);
    //inform server that this player has chosen this option
    client->sendPlayCommand(selectedMove.first,selectedMove.second);
    return selectedMove;

}