#include "binary_tree.h"

namespace BinaryTree {
template <typename T>
BTree<T>::BTree() : root_(nullptr), size_() {}

template <typename T>
BTree<T>::~BTree() {
	this->clear();
}

template <typename T>
void BTree<T>::clear() {}
} // namespace BinaryTree