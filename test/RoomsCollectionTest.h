/**
 * RoomsCollectionTest class.
 * include tests for rooms collection.
 */
#ifndef REVERSITESTS_ROOMSCOLLECTIONTEST_H
#define REVERSITESTS_ROOMSCOLLECTIONTEST_H
#define FIRST 0
#define SECOND 1

#include <gtest/gtest.h>
#include "../src/server/Room.h"

class RoomsCollectionTest: public testing::Test {
public:
/**
 * isValidRoomsNames function.
 * @param rooms - vector of rooms.
 * @return true if valid, false otherwise
 */
    bool isValidRoomsNames(vector<Room> rooms);
    /**
     * isValidRoomsStatus function.
     * @param rooms - vector of rooms.
     * @return true if valid, false otherwise
     */
    bool isValidRoomsStatus(vector<Room> rooms);

};


#endif //REVERSITESTS_ROOMSCOLLECTIONTEST_H
