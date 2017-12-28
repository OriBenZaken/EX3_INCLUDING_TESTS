//
// Created by liz on 28/12/17.
//

#include "ClientTest.h"
#include "../src/client/Client.h"

TEST_F(ClientTest, CorrectSplit) {
    char* rooms = "liz,ori";
    vector<string> splited = Client::getGameListFromString(rooms);
    EXPECT_TRUE(isSplitValid(splited));

}

bool ClientTest::isSplitValid(vector<string> splitted) {
    return (splitted[FIRST].compare("liz")==0) && (splitted[SECOND].compare("ori") ==0);
}
