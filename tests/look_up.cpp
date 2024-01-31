#include "btree_fixture.h"

TEST_F(BTreeTest, LookUp) {
	EXPECT_EQ(empty.lookUp(-1), nullptr);

	EXPECT_EQ(oneItem.lookUp(-1), nullptr);
	EXPECT_EQ(*oneItem.lookUp(1), 1);

	EXPECT_EQ(*tree1.lookUp(7), 7);
	EXPECT_EQ(*tree1.lookUp(2), 2);
	EXPECT_EQ(tree1.lookUp(-10), nullptr);
}