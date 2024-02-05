#ifndef BTREE_FIXTURE_H
#define BTREE_FIXTURE_H

#include <gtest/gtest.h>
#include "../Tree/binary_tree.h"

namespace {
using BinaryTree::BTree;
}

class BTreeTest : public testing::Test {
	protected:
    BTreeTest() {}

	BTree<int> empty;
	BTree<int> oneItem{1};
	BTree<int> threeItems{1, 0, 2};
	BTree<int> tree1{1, 0, 2, -2, 2, 5, 6, 7, 3, -1}; // size: 10
	BTree<int> balancedTree {1, 0, 2, -2, 2, 5};
};

#endif // BTREE_FIXTURE_H