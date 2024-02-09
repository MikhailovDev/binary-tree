#include "btree_fixture.h"

TEST_F(BTreeTest, PrintPreorderEmpty) {
    testing::internal::CaptureStdout();
    empty.printPreorder();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output.size(), 0);
}

TEST_F(BTreeTest, PrintPreorderOneItemTree) {
    testing::internal::CaptureStdout();
    oneItem.printPreorder();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1 \n");
}

TEST_F(BTreeTest, PrintPreorderThreeItemTree) {
    testing::internal::CaptureStdout();
    threeItems.printPreorder();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1 0 2 \n");

    threeItems.insert(-1);

    testing::internal::CaptureStdout();
    threeItems.printPreorder();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1 0 -1 2 \n");
}

TEST_F(BTreeTest, PrintPreorderSixItemTree) {
    testing::internal::CaptureStdout();
    balancedTree.printPreorder();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1 0 -2 2 5 \n");

    balancedTree.insert(3);

    testing::internal::CaptureStdout();
    balancedTree.printPreorder();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1 0 -2 2 5 3 \n");
}