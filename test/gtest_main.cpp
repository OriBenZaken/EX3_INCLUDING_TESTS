#include <gtest/gtest.h>

using namespace testing;
/**
 * main func.
 * @param argc - number of arguments from command line.
 * @param argv - arguments from command line.
 * @return 0;
 */

int main(int argc, char *argv[]) {
    InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}
