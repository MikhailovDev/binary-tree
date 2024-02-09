#include "btree_fixture.h"

TEST_F(BTreeTest, IsBalancedEmpty) {
	EXPECT_EQ(empty.isBalanced(), true);
}

TEST_F(BTreeTest, IsBalancedNormalCases) {
	EXPECT_EQ(oneItem.isBalanced(), true);
	EXPECT_EQ(threeItems.isBalanced(), true);
	EXPECT_EQ(balancedTree.isBalanced(), true);
	EXPECT_EQ(tree1.isBalanced(), false);

	balancedTree.insert(-3);
	EXPECT_EQ(balancedTree.isBalanced(), false);

	balancedTree.remove(-3);
	EXPECT_EQ(balancedTree.isBalanced(), true);
	balancedTree.insert(9);
	balancedTree.insert(10);
	EXPECT_EQ(balancedTree.isBalanced(), false);

	balancedTree.clear();
	EXPECT_EQ(balancedTree.isBalanced(), true);
}