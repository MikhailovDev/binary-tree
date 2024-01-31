#include "btree_fixture.h"

TEST_F(BTreeTest, GetMinDepthEmpty) {
	EXPECT_EQ(empty.getMinDepth(), -1);
}

TEST_F(BTreeTest, GetMinDepthOfExistingItems) {
	EXPECT_EQ(oneItem.getMinDepth(), 0);
	EXPECT_EQ(threeItems.getMinDepth(), 1);
	EXPECT_EQ(balancedTree.getMinDepth(), 2);
	EXPECT_EQ(tree1.getMinDepth(), 2);

	tree1.insert(-1);
	EXPECT_EQ(tree1.getMinDepth(), 2);
}