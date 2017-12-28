/**
 * ClientTest class.
 * include test for split method
 */
#include "../src/client/Client.h"

#ifndef REVERSITESTS_CLIENTTEST_H
#define REVERSITESTS_CLIENTTEST_H
using namespace std;
#include <gtest/gtest.h>
#define FIRST 0
#define SECOND 1
#define TEST_SIZE 6


class ClientTest: public testing::Test {

public:
    /**
     * isSplitValid func.
     * @param splitted - vector of splitted command
     * @return true if valid, false otherwise
     */
    bool isSplitValid(vector<string> splitted);
};


#endif //REVERSITESTS_CLIENTTEST_H
