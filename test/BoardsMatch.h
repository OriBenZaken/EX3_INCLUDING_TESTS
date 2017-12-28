/**
 * BoardsMatch class.
 * include tests for board
 */
#ifndef REVERSITESTS_MATRIXASSERTION_H
#define REVERSITESTS_MATRIXASSERTION_H
#include <gtest/gtest.h>

/**
 * returns success- if expected board has the same values in the same cells of actual board
 * @param expected Board
 * @param actual Board
 * @param size size of the board
 * @return Suceess / failure.
 */
::testing::AssertionResult BoardsMatch(const Board &expected, const Board &actual, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (expected.getCell(i, j) != actual.getCell(i, j)){
                return ::testing::AssertionFailure() << " actual array[" << i << "][" << j << "] != expected array[" <<
                                                     i << "][" << j << "]";
            }
        }
    }
    return ::testing::AssertionSuccess();
}
#endif //REVERSITESTS_MATRIXASSERTION_H
