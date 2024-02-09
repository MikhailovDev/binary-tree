#include "btree_fixture.h"

TEST_F(BTreeTest, ClearEmpty) {
	EXPECT_EQ(empty.getSize(), 0);
	empty.clear();
	EXPECT_EQ(empty.getSize(), 0);
}

TEST_F(BTreeTest, ClearOneItem) {
	EXPECT_EQ(oneItem.getSize(), 1);
	oneItem.clear();
	EXPECT_EQ(oneItem.getSize(), 0);
	EXPECT_EQ(oneItem.lookUp(1), nullptr);
}

TEST_F(BTreeTest, ClearNormalTree) {
	EXPECT_EQ(balancedTree.getSize(), 5);
	balancedTree.clear();
	EXPECT_EQ(balancedTree.getSize(), 0);
	EXPECT_EQ(balancedTree.lookUp(1), nullptr);
	EXPECT_EQ(balancedTree.lookUp(0), nullptr);
	EXPECT_EQ(balancedTree.lookUp(2), nullptr);
	EXPECT_EQ(balancedTree.lookUp(-2), nullptr);
	EXPECT_EQ(balancedTree.lookUp(5), nullptr);
}