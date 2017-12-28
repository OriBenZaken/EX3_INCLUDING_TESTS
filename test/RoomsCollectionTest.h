//
// Created by liz on 28/12/17.
//

#ifndef REVERSITESTS_ROOMSCOLLECTIONTEST_H
#define REVERSITESTS_ROOMSCOLLECTIONTEST_H
#define FIRST 0
#define SECOND 1

#include <gtest/gtest.h>
#include "../src/server/Room.h"

class RoomsCollectionTest: public testing::Test {
public:

    bool isValidRoomsNames(vector<Room> rooms);
    bool isValidRoomsStatus(vector<Room> rooms);

};


#endif //REVERSITESTS_ROOMSCOLLECTIONTEST_H
