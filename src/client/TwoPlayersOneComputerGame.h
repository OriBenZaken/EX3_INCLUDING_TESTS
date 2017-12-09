
#ifndef EX2_GAME_H
#define EX2_GAME_H
#include <iostream>
#include <sstream>
#include <cstdlib>
#include "Board.h"
#include "StandartGameLogic.h"
#include "GameLogic.h"
#include "IGame.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include <iostream>


using namespace std;
/**
 * Reversi game version:
 * two players on one machine.
 * players can be both humans or human against AIplayer.
 */
class TwoPlayersOneComputerGame : public IGame {
public:
    /**
     * TwoPlayersOneComputerGame ctor.
     * @param board Board (reference)
     */
    TwoPlayersOneComputerGame(Board* board, IGame::PlayersType playersType) : board(board) {
        gameLogic = new StandartGameLogic(board);
        switch (playersType) {
            case Humans:
                currPlayer = new HumanPlayer(Board::Black);
                otherPlayer = new HumanPlayer(Board::White);
                break;
            case HumanVSAI:
                currPlayer = new HumanPlayer(Board::Black);

                GameLogic *copyGameLogic = new StandartGameLogic(*gameLogic);

                otherPlayer = new AIPlayer(Board::White, copyGameLogic);
                break;
        }
        status = Playing;
    }
    /**
     * runs a Reversi Game.
     */
    void run();
    /**
     * TwoPlayersOneComputerGame d'tor.
     */
    ~TwoPlayersOneComputerGame();
private:
    //members
    GameLogic *gameLogic;
    Board* board;
    Player* currPlayer;
    Player* otherPlayer;
    Status status;
    /**
     * Swap between current player to other player.
     */
    void switchCurrPlayer();
    /**
     * Checks who is the winning player and prints a suitable message to the console.
     */
    void announceWinner();
    /**
     * Announces who's turn now: Black or White player.
     */
    void announceWhoPlayNow();
    /**
     * Announces who just made a move.
     * @param row row of the move cell.
     * @param col column of the move cell.
     */
    void announceWhoMadeAMove(int row, int col);
};
#endif //EX2_GAME_H