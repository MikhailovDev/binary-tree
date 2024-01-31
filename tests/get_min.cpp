#include "btree_fixture.h"

TEST_F(BTreeTest, getMinEmpty) {
	EXPECT_EQ(empty.getMin(), nullptr);
}

TEST_F(BTreeTest, getMinOfExistingItems) {
	EXPECT_EQ(*threeItems.getMin(), 0);
	EXPECT_EQ(*balancedTree.getMin(), -2);
	EXPECT_EQ(*tree1.getMin(), -2);

	threeItems.insert(-5);
	EXPECT_EQ(*threeItems.getMin(), -5);
	threeItems.remove(-5);
	EXPECT_EQ(*threeItems.getMin(), 0);
	threeItems.clear();
	EXPECT_EQ(threeItems.getMin(), nullptr);
}