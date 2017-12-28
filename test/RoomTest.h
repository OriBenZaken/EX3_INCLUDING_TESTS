//
// Created by liz on 28/12/17.
//

#ifndef REVERSITESTS_ROOMTEST_H
#define REVERSITESTS_ROOMTEST_H


#include "../src/server/Room.h"

class RoomTest : public testing::Test{
public:
    bool isValidRoomStatus(Room room);
    bool isValidRoomName(Room room);
};


#endif //REVERSITESTS_ROOMTEST_H
