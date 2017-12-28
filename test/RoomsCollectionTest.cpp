
#include "RoomsCollectionTest.h"


TEST_F(RoomsCollectionTest, CorrectRoomsNames) {
    Room room1;
    room1.setRoomName("Aliza");
    Room room2;
    room2.setRoomName("ori");
    vector<Room> rooms;
    rooms.push_back(room1);
    rooms.push_back(room2);
    EXPECT_TRUE(isValidRoomsNames(rooms));

}


TEST_F(RoomsCollectionTest, CorrectRoomsStatuses) {
    Room room1;
    room1.setRoomStatus(Room::Running);
    Room room2;
    room2.setRoomStatus(Room::Running);
    vector<Room> rooms;
    rooms.push_back(room1);
    rooms.push_back(room2);
    EXPECT_TRUE(isValidRoomsStatus(rooms));

}


bool RoomsCollectionTest::isValidRoomsNames(vector<Room> rooms) {
    bool ans1 = false;
    bool ans2 = false;

    for (int i =0; i< rooms.size(); i++) {
        if (i==FIRST) {
            if (rooms[i].getRoomName().compare("Aliza") ==0) {
                ans1 = true;
            }
        }
        if (i==SECOND) {
            if (rooms[i].getRoomName().compare("ori") ==0) {
                ans2 = true;
            }
        }
    }
    return ans1 && ans2;

}


bool RoomsCollectionTest::isValidRoomsStatus(vector<Room> rooms) {
    bool ans1 = false;
    bool ans2 = false;

    for (int i =0; i< rooms.size(); i++) {
        if (i==FIRST) {
            if (rooms[i].getRoomStatus() == Room::Running) {
                ans1 = true;
            }
        }
        if (i==SECOND) {
            if (rooms[i].getRoomStatus() == Room::Running) {
                ans2 = true;
            }
        }
    }
    return ans1 && ans2;

}
