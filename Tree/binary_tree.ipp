#include "binary_tree.h"

namespace BinaryTree {
template <typename T>
BTree<T>::BTree() : root_(nullptr), size_() {}

template <typename T>
BTree<T>::BTree(const std::initializer_list<T>& initList) : root_(nullptr), size_() {
	for (auto& item : initList) {
		insert(item);
	}
}

template <typename T>
BTree<T>::~BTree() {
    this->clear();
}

template <typename T>
const Node<T>* BTree<T>::lookUp(const T& key) const {
    if (!root_) {
        return nullptr;
    }

    return lookUpHelper(key, root_);
}

template <typename T>
const Node<T>* BTree<T>::lookUpHelper(const T& key,
                                      const Node<T>* parent) const {
    if (!parent) {
        return nullptr;
    }

    if (key == parent->data) {
        return parent;
    } else if (key < parent->data) {
        return lookUpHelper(key, parent->left);
    } else {
        return lookUpHelper(key, parent->right);
    }
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