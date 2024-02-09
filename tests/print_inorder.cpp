#include "btree_fixture.h"

TEST_F(BTreeTest, PrintInorderEmpty) {
    testing::internal::CaptureStdout();
    empty.printInorder();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output.size(), 0);
}

TEST_F(BTreeTest, PrintInorderOneItemTree) {
    testing::internal::CaptureStdout();
    oneItem.printInorder();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1 \n");
}

TEST_F(BTreeTest, PrintInorderThreeItemTree) {
    testing::internal::CaptureStdout();
    threeItems.printInorder();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "0 1 2 \n");

    threeItems.insert(-1);

    testing::internal::CaptureStdout();
    threeItems.printInorder();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "-1 0 1 2 \n");
}

TEST_F(BTreeTest, PrintInorderSixItemTree) {
    testing::internal::CaptureStdout();
    balancedTree.printInorder();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "-2 0 1 2 5 \n");

    balancedTree.insert(3);

    testing::internal::CaptureStdout();
    balancedTree.printInorder();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "-2 0 1 2 3 5 \n");
}