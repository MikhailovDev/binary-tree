#include "btree_fixture.h"

TEST_F(BTreeTest, getMaxEmpty) {
	EXPECT_EQ(empty.getMax(), nullptr);
}

TEST_F(BTreeTest, getMaxOfExistingItems) {
	EXPECT_EQ(*threeItems.getMax(), 2);
	EXPECT_EQ(*balancedTree.getMax(), 5);
	EXPECT_EQ(*tree1.getMax(), 7);

	threeItems.insert(5);
	EXPECT_EQ(*threeItems.getMax(), 5);
	threeItems.remove(5);
	EXPECT_EQ(*threeItems.getMax(), 2);
	threeItems.clear();
	EXPECT_EQ(threeItems.getMax(), nullptr);
}