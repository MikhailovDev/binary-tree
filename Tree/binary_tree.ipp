#include "binary_tree.h"

namespace BinaryTree {
template <typename T>
BTree<T>::BTree() : root_(nullptr), size_() {}

template <typename T>
BTree<T>::~BTree() {
	this->clear();
}

template <typename T>
void BTree<T>::insert(const T& data) {
    if (!root_) {
        addNode(data, root_);
        return;
    }

    insertHelper(data, root_);
}

template <typename T>
void BTree<T>::insertHelper(const T& data, Node<T>*& parent) {
    if (data <= parent->data) {
        if (!parent->left) {
            addNode(data, parent->left);
            return;
        }

        insertHelper(data, parent->left);
		return;
    } else {
        if (!parent->right) {
            addNode(data, parent->right);
            return;
        }

		insertHelper(data, parent->right);
    }
}

template <typename T>
void BTree<T>::addNode(const T& data, Node<T>*& parent) {
    auto tmp = new Node<T>(data);
    parent = tmp;

    ++size_;
}

template <typename T>
void BTree<T>::clear() {}
} // namespace BinaryTree