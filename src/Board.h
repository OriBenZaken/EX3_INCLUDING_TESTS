//
// Created by Ori Ben Zaken on 23/10/17.
// ID: 311492110
//
#ifndef EX1_BOARD_H
#define EX1_BOARD_H
#include <iostream>
using namespace std;

/**
 * Describse a Reversi game board.
 * @author Ori Ben Zaken.
 */
class Board {
public:
    enum Cell {Black, White, Empty};
    /**
     * Board constructor.
     * creates a string sizeXsize matrix.
     */
    Board(int size);
    /**
     * copy constructor.
     * @param board - board to copy from.
     */
    Board(const Board& board);
    /**
     * intializes the game board to the start mode.
     * @param size size of the board (sizeXsize)
     */
    void initialize();
    /**
     * prints the game board to the console.
     */
    void print() const;
    /**
     * returns the value in a given position in the board.
     * @param row Row index
     * @param col Column index
     * @return Cell enum - value of the the board in the given index.
     */
    Cell getCell(int row, int col) const;
    /**
     * change White to Black or Black to White in given index.
     * @param row
     * @param col
     */
    void flipCell(int row, int col);
    /**
     * return board size.
     * @return size - int.
     */
    int getSize();
    /**
     * set Cell to a given value.
     * @param row row
     * @param col col
     * @param player White / Black
     */
    void setCell(int row, int col, Cell player);
    /**
     * returns true if a given index exists in the borders of the board.
     * @param row row
     * @param col col
     * @return true - legal index. false - else.
     */
    bool isIndexInBoard(int row, int col);
    /**
     * Returns number of empty cells in the board.
     * @return Returns number of empty cells in the board.
     */
    int getNumOfEmptyCells() const;
    /**
     * Board distractor.
     */
    ~Board();
private:
    Cell** board;
    int size ;
};
#endif //ex1_BOARD_H
