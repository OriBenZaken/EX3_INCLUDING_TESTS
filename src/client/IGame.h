
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
    /** Runs a Reversi game until game is over : Win/Lose or a Tie.
     *
     */
    IGame()  {}
    //IGame(Player* currPlayer, Player* otherPlayer) : currPlayer(currPlayer), otherPlayer(otherPlayer) {}
    virtual void run() = 0;
    /**
     * virtual default ctor.
     */
    virtual ~IGame()  {}
    //todo: add javadoc
    static IGame::Status checkWinner(Board* board);

};
#endif //EX2_IGAME_H
