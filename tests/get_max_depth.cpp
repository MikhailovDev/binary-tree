#include "btree_fixture.h"

TEST_F(BTreeTest, GetMaxDepthEmpty) {
	EXPECT_EQ(empty.getMaxDepth(), -1);
}

TEST_F(BTreeTest, GetMaxDepthOfExistingItems) {
	EXPECT_EQ(threeItems.getMaxDepth(), 1);
	EXPECT_EQ(balancedTree.getMaxDepth(), 2);
	EXPECT_EQ(tree1.getMaxDepth(), 4);

	threeItems.insert(5);
	EXPECT_EQ(threeItems.getMaxDepth(), 2);
}