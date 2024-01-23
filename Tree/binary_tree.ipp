#include "binary_tree.h"

namespace BinaryTree {
template <typename T>
BTree<T>::BTree() : root_(nullptr), size_() {}

template <typename T>
BTree<T>::BTree(const std::initializer_list<T>& initList) :
    root_(nullptr),
    size_() {
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
const Node<T>* BTree<T>::lookUpHelper(const T& key, const Node<T>* root) const {
    if (!root) {
        return nullptr;
    }

    if (key == root->data) {
        return root;
    } else if (key < root->data) {
        return lookUpHelper(key, root->left);
    } else {
        return lookUpHelper(key, root->right);
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
void BTree<T>::insertHelper(const T& data, Node<T>*& root) {
    if (data <= root->data) {
        if (!root->left) {
            addNode(data, root->left);
            return;
        }

        insertHelper(data, root->left);
        return;
    } else {
        if (!root->right) {
            addNode(data, root->right);
            return;
        }

        insertHelper(data, root->right);
    }
}

template <typename T>
void BTree<T>::addNode(const T& data, Node<T>*& root) {
    auto tmp = new Node<T>(data);
    root = tmp;

    ++size_;
}

template <typename T>
void BTree<T>::clear() {
    if (!root_) {
        return;
    }

    clearHelper(root_);
    root_ = nullptr;
}

template <typename T>
void BTree<T>::clearHelper(Node<T>*& root) {
    if (root->left) {
        clearHelper(root->left);
    }
    if (root->right) {
        clearHelper(root->right);
    }

    delete root;

    --size_;
}

template <typename T>
inline std::size_t BTree<T>::getSize() const {
    return size_;
}

template <typename T>
void BTree<T>::printInorder() const {
    printInorderHelper(root_);
    std::cout << std::endl;
}

template <typename T>
void BTree<T>::printInorderHelper(const Node<T>* root) const {
    if (root) {
        printInorderHelper(root->left);
        std::cout << root->data << " ";
        printInorderHelper(root->right);
    }
}

template <typename T>
void BTree<T>::printPostorder() const {
    printPostorderHelper(root_);
    std::cout << std::endl;
}

template <typename T>
void BTree<T>::printPostorderHelper(const Node<T>* root) const {
    if (root) {
        printPostorderHelper(root->left);
        printPostorderHelper(root->right);
        std::cout << root->data << " ";
    }
}

template <typename T>
void BTree<T>::printPreorder() const {
    printPreorderHelper(root_);
    std::cout << std::endl;
}

template <typename T>
void BTree<T>::printPreorderHelper(const Node<T>* root) const {
    if (root) {
        std::cout << root->data << " ";
        printPreorderHelper(root->left);
        printPreorderHelper(root->right);
    }
}
} // namespace BinaryTree