
#include "Room.h"

const string &Room::getRoomName() const {
    return roomName;
}

void Room::setRoomName(const string &roomName) {
    Room::roomName = roomName;
}

int Room::getFirstClientSocket() const {
    return firstClientSocket;
}

void Room::setFirstClientSocket(int firstClientSocket) {
    Room::firstClientSocket = firstClientSocket;
}

int Room::getSecondClientSocket() const {
    return secondClientSocket;
}

void Room::setSecondClientSocket(int secondClientSocket) {
    Room::secondClientSocket = secondClientSocket;
}

Room::RoomStatus Room::getRoomStatus() const {
    return roomStatus;
}

void Room::setRoomStatus(Room::RoomStatus roomStatus) {
    Room::roomStatus = roomStatus;
}



