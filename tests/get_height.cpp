#include "btree_fixture.h"

TEST_F(BTreeTest, GetHeightEmpty) {
	EXPECT_EQ(empty.getHeight(0), -1);
}

TEST_F(BTreeTest, GetHeightOneItem) {
	EXPECT_EQ(oneItem.getHeight(0), -1);
	EXPECT_EQ(oneItem.getHeight(1), 0);
}

TEST_F(BTreeTest, GetHeightNormalTree) {
	EXPECT_EQ(balancedTree.getHeight(1), 2);
	EXPECT_EQ(balancedTree.getHeight(0), 1);
	EXPECT_EQ(balancedTree.getHeight(-2), 0);
	EXPECT_EQ(balancedTree.getHeight(5), 0);
	EXPECT_EQ(balancedTree.getHeight(*balancedTree.getMax()), 0);
	EXPECT_EQ(balancedTree.getHeight(-1), -1);

	balancedTree.insert(5);
	balancedTree.insert(5);
	balancedTree.insert(5);
	EXPECT_EQ(balancedTree.getHeight(), 5);
}