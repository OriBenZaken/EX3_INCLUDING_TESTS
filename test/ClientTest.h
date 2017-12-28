//
// Created by liz on 28/12/17.
//

#ifndef REVERSITESTS_CLIENTTEST_H
#define REVERSITESTS_CLIENTTEST_H
using namespace std;
#define TEST_SIZE 6
#include <gtest/gtest.h>
#define FIRST 0
#define SECOND 1

class ClientTest: public testing::Test {

public:
    bool isSplitValid(vector<string> splitted);
};


#endif //REVERSITESTS_CLIENTTEST_H
