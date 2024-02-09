#include "btree_fixture.h"

TEST_F(BTreeTest, RemoveEmpty) {
    EXPECT_EQ(empty.getSize(), 0);
    empty.remove(5);
    EXPECT_EQ(empty.getSize(), 0);
}

TEST_F(BTreeTest, RemoveNonExistingItems) {
    EXPECT_EQ(threeItems.getSize(), 3);

    threeItems.remove(5);
    threeItems.remove(4);
    EXPECT_EQ(threeItems.getSize(), 3);
    EXPECT_EQ(threeItems.lookUp(5), nullptr);
}

TEST_F(BTreeTest, RemoveLeaf) {
    threeItems.remove(2);
    EXPECT_EQ(threeItems.getSize(), 2);
    EXPECT_EQ(threeItems.lookUp(2), nullptr);

    threeItems.remove(1);
    EXPECT_EQ(threeItems.getSize(), 1);
    EXPECT_EQ(threeItems.lookUp(1), nullptr);
}

TEST_F(BTreeTest, RemoveItemWithOneChild) {
    tree1.remove(5);
    EXPECT_EQ(tree1.getSize(), 8);
    EXPECT_EQ(tree1.lookUp(5), nullptr);
    EXPECT_EQ(*tree1.lookUp(6), 6);
    EXPECT_EQ(*tree1.lookUp(7), 7);

    tree1.remove(0);
    EXPECT_EQ(tree1.getSize(), 7);
    EXPECT_EQ(tree1.lookUp(0), nullptr);
    EXPECT_EQ(*tree1.lookUp(-2), -2);
    EXPECT_EQ(*tree1.lookUp(-1), -1);
}

TEST_F(BTreeTest, RemoveItemWithTwoChilds) {
    tree1.remove(2);
    EXPECT_EQ(tree1.lookUp(2), nullptr);
    EXPECT_EQ(*tree1.lookUp(5), 5);
    EXPECT_EQ(tree1.getSize(), 8);

    tree1.remove(3);
    EXPECT_EQ(tree1.getSize(), 7);
    EXPECT_EQ(tree1.lookUp(3), nullptr);
    EXPECT_EQ(*tree1.lookUp(7), 7);
    EXPECT_EQ(*tree1.lookUp(6), 6);
    EXPECT_EQ(tree1.lookUp(9), nullptr);
}