#include "btree_fixture.h"

TEST_F(BTreeTest, GetDepthEmpty) {
	EXPECT_EQ(empty.getDepth(25), -1);
}

TEST_F(BTreeTest, GetDepthOfExistingItem) {
	EXPECT_EQ(threeItems.getDepth(1), 0);
	EXPECT_EQ(threeItems.getDepth(0), 1);
	EXPECT_EQ(threeItems.getDepth(2), 1);

	EXPECT_EQ(balancedTree.getDepth(5), 2);
	EXPECT_EQ(balancedTree.getDepth(2), 1);
}