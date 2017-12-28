//
// Created by liz on 28/12/17.
//

#include "RoomsCollection.h"
vector<Room> &RoomsCollection::getRooms()  {
    return rooms;
}

void RoomsCollection::setRooms(const vector<Room> &rooms) {
    RoomsCollection::rooms = rooms;
}
 pthread_mutex_t &RoomsCollection::getCount_mutex()  {
    return count_mutex;
}

void RoomsCollection::setCount_mutex(const pthread_mutex_t &count_mutex) {
    RoomsCollection::count_mutex = count_mutex;
}
