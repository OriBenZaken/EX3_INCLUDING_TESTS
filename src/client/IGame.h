
#ifndef EX2_IGAME_H
#define EX2_IGAME_H
#include "Player.h"
/**
 * Reversi Game interface.
 */
class IGame {
public:
    enum Status {Playing, NoPossibleMoves, GameOver, BlackWins, WhiteWins, Tie};
    enum PlayersType {Humans, HumanVSAI, RemoteMode};
    /**
     * constructor
     */
    IGame()  {}
    /**
     * run function
     * runs the game
     */
    virtual void run() = 0;
    /**
     * virtual default ctor.
     */
    virtual ~IGame()  {}
    /**
     * checkWinner function
     * @param board  - game of board
     * @return status
     */
    static IGame::Status checkWinner(Board* board);

};
#endif //EX2_IGAME_H
