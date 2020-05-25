#include <gtest/gtest.h>
#include "../BinFile.h"

TEST(BinFile, numericData)
{
    std::string fileName = "TestFile";
    std::vector<uint_fast8_t> writableData = {0, 25, 34, 5, 76, 34, 3, 3, 2, 1, 76, 90};
    write(fileName, writableData);
    auto readableData = read(fileName);
    ASSERT_EQ(writableData, readableData);
}

TEST(BinFile, symbolicData)
{
    std::string fileName = "TestFile";
    std::vector<uint_fast8_t> writableData = {'H', 'e', 'l', 'l', 'o', 'w', 'o', 'r', 'l', 'd', '!'};
    write(fileName, writableData);
    auto readableData = read(fileName);
    ASSERT_EQ(writableData, readableData);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
