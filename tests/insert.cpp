#include "btree_fixture.h"

TEST_F(BTreeTest, EmptyInsert) {
	EXPECT_EQ(empty.getSize(), 0);
	empty.insert(1);
	EXPECT_EQ(empty.getSize(), 1);
	EXPECT_EQ(*empty.lookUp(1), 1);
}

TEST_F(BTreeTest, ThreeItemsInsert) {
	EXPECT_EQ(threeItems.getSize(), 3);

	threeItems.insert(1);
	EXPECT_EQ(threeItems.getSize(), 4);
	EXPECT_EQ(*threeItems.lookUp(1), 1);

	threeItems.insert(5);
	EXPECT_EQ(threeItems.getSize(), 5);
	EXPECT_EQ(*threeItems.lookUp(5), 5);
}