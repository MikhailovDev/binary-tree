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
const Node<T>* BTree<T>::lookUp(const T& data) const {
    if (!root_) {
        return nullptr;
    }

    return lookUpHelper(data, root_);
}

template <typename T>
const Node<T>* BTree<T>::lookUpHelper(const T& data,
                                      const Node<T>* root) const {
    if (!root) {
        return nullptr;
    }

    if (data == root->data) {
        return root;
    } else if (data < root->data) {
        return lookUpHelper(data, root->left);
    } else {
        return lookUpHelper(data, root->right);
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

template <typename T>
void BTree<T>::remove(const T& data) {
    root_ = removeHelper(root_, data);
}

template <typename T>
Node<T>* BTree<T>::removeHelper(Node<T>* root, const T& data) {
    if (!root_) {
        return nullptr;
    }

    if (data < root->data) {
        root->left = removeHelper(root->left, data);
        return root;
    } else if (data > root->data) {
        root->right = removeHelper(root->right, data);
        return root;
    }

    if (!root->left) {
        Node<T>* tmp = root->right;
        delete root;
        --size_;
        return tmp;
    } else if (!root->right) {
        Node<T>* tmp = root->left;
        delete root;
        --size_;
        return tmp;
    } else {
        Node<T>* succesorParent = root;
        Node<T>* succesor = root->right;
        while (succesor->left) {
            succesorParent = succesor;
            succesor = succesor->left;
        }

        succesor->left = root->left;
        succesor->right =
            succesorParent != root ? root->right : succesor->right;
        succesorParent->left = nullptr;

        delete root;
        --size_;
        return succesor;
    }
}

template <typename T>
inline int BTree<T>::getDepth(const T& data) const {
    return depthHelper(root_, data);
}

template <typename T>
int BTree<T>::depthHelper(const Node<T>* root, const T& data, int depth) const {
    if (!root) {
        return -1;
    }

    if (root->data > data) {
        return depthHelper(root->left, data, depth + 1);
    } else if (root->data < data) {
        return depthHelper(root->right, data, depth + 1);
    }

    return depth;
}

template <typename T>
inline std::size_t BTree<T>::getMaxDepth() const {
    int max {};
    return maxDepthHelper(root_, max);
}

template <typename T>
std::size_t BTree<T>::maxDepthHelper(const Node<T>* root, int& maxDepth,
                           int depth) const {
    if (!root) {
        return (maxDepth = maxDepth < depth ? depth : maxDepth);
    }

    maxDepthHelper(root->left, maxDepth, depth + 1);
    maxDepthHelper(root->right, maxDepth, depth + 1);
}

template <typename T>
void BTree<T>::printHelper(std::ostream& os, const Node<T>* root,
                           std::size_t number) const {
    if (!root) {
        return;
    }

    printHelper(os, root->left, number + 1);
    for (std::size_t i {}; i < number; ++i) {
        os << "  ";
    }
    os << root->data << std::endl;
    printHelper(os, root->right, number + 1);
}
} // namespace BinaryTree