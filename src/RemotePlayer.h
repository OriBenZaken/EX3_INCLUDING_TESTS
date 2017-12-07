
#ifndef REVERSITESTS_REMOTEPLAYER_H
#define REVERSITESTS_REMOTEPLAYER_H
#include "Player.h"
#include "HumanPlayer.h"
#include "client/Client.h"

//RemotePlayer class.
class RemotePlayer : public Player{

public:
    /**
   * RemotePlayer c'tor
   * @param type Board::Cell (Black/White)
   */
    RemotePlayer(Board::Cell type) : Player(type), humanPlayer(type) {}
    /**
     * RemotePlayer ctor.
     * @param type Board::Cell (White/Black)
     */
    RemotePlayer(Client* client) : humanPlayer(type) {
        (*this).client =client;
    }
    /**
     * display to the human player all his possible moves and gets an input of a wished move.
     * @param options vector of possible moves.
     * @param board Board
     * @param currentCellType Board::Cell (White/Black)
     * @param opponentCellType Board::Cell (White/Black)
     * @return pair<int, int> of cell in the board - the desired move of the player.
     */
    pair<int, int> getInput(vector< pair<int,int> > options, const Board* board,
                            Board::Cell currentCellType, Board::Cell opponentCellType);

private:
    //members
    HumanPlayer humanPlayer;
    Client* client;

};


#endif //REVERSITESTS_REMOTEPLAYER_H
