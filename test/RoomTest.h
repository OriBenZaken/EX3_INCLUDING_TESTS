/**
 * RoomTest class.
 * includes tests for Room class
 */

#ifndef REVERSITESTS_ROOMTEST_H
#define REVERSITESTS_ROOMTEST_H


#include "../src/server/Room.h"
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

class RoomTest : public testing::Test{
public:
    /**
     * isValidRoomStatus func.
     * @param room - Room obj
     * @return true if valid, false otherwise
     */
    bool isValidRoomStatus(Room room);
    /**
    * isValidRoomName func.
    * @param room - Room obj
    * @return true if valid, false otherwise
    */
    bool isValidRoomName(Room room);
};


#endif //REVERSITESTS_ROOMTEST_H
