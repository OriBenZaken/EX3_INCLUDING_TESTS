//
// Created by liz on 28/12/17.
//

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "RoomTest.h"
TEST_F(RoomTest, CorrectRoomName) {
Room room;
    room.setRoomName("Aliza");
    EXPECT_TRUE(isValidRoomName(room));

}


TEST_F(RoomTest, CorrectRoomStatus) {
    Room room;
    room.setRoomStatus(Room::WaittingToOtherPlayer);
    EXPECT_TRUE(isValidRoomStatus(room));

}

bool RoomTest::isValidRoomName(Room room) {
    return (room.getRoomName().compare("Aliza") ==0);

}


bool RoomTest::isValidRoomStatus(Room room) {
    return (room.getRoomStatus() == Room::WaittingToOtherPlayer);
}





