#include "btree_fixture.h"

TEST_F(BTreeTest, PrintPostorderEmpty) {
    testing::internal::CaptureStdout();
    empty.printPostorder();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output.size(), 0);
}

TEST_F(BTreeTest, PrintPostorderOneItemTree) {
    testing::internal::CaptureStdout();
    oneItem.printPostorder();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1 \n");
}

TEST_F(BTreeTest, PrintPostorderThreeItemTree) {
    testing::internal::CaptureStdout();
    threeItems.printPostorder();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "0 2 1 \n");

    threeItems.insert(-1);

    testing::internal::CaptureStdout();
    threeItems.printPostorder();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "-1 0 2 1 \n");
}

TEST_F(BTreeTest, PrintPostorderSixItemTree) {
    testing::internal::CaptureStdout();
    balancedTree.printPostorder();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "-2 0 5 2 1 \n");

    balancedTree.insert(3);

    testing::internal::CaptureStdout();
    balancedTree.printPostorder();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "-2 0 3 5 2 1 \n");
}