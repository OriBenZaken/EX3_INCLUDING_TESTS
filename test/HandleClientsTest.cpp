//
// Created by liz on 28/12/17.
//

#include <gtest/gtest.h>
#include "HandleClientsTest.h"
#include "../src/server/HandleClients.h"

TEST_F(HandleClientsTest, CorrectSwap) {

    int client1 = 4;
    int client2 = 5;
    HandleClients::swapClients(&client1,&client2);

    EXPECT_TRUE((*this).isValidSwap(client1, client2));

}



TEST_F(HandleClientsTest, CorrectSplit) {

    int client1 = 4;
    int client2 = 5;

    vector<string> splitted = HandleClients::splitCommand("join <liz>");

    EXPECT_TRUE((*this).isValidSplit(splitted));

}



bool HandleClientsTest::isValidSwap(int client1, int client2) {
    return client1==5 &&client2 ==4;
}


bool HandleClientsTest::isValidSplit(vector<string> splitted) {
    return ((splitted[0].compare("join")==0) && splitted[1].compare("liz")==0);

}