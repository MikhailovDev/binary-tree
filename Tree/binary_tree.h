#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <cstddef>
#include <initializer_list>
#include <iostream>

#include "node.h"

namespace BinaryTree {
template <typename T>
class BTree {
   private:
    Node<T>* root_;
    std::size_t size_;

    const Node<T>* getNode(const Node<T>* root, const T& data) const;
    const T* lookUpHelper(const Node<T>* root, const T& data) const;

    void insertHelper(const T& data, Node<T>* root);
    void clearHelper(Node<T>*& root);

    void printInorderHelper(const Node<T>* root) const;
    void printPreorderHelper(const Node<T>* root) const;
    void printPostorderHelper(const Node<T>* root) const;
    void printHelper(std::ostream& os, const Node<T>* root, std::size_t number = 0) const;

    void addNode(const T& data, Node<T>*& root);

    Node<T>* removeHelper(Node<T>* root, const T& data);

    int getHeight(const Node<T>* data) const;

    int depthHelper(const Node<T>* root, const T& data, int depth = 0) const;
    std::size_t maxDepthHelper(const Node<T>* root, int& maxDepth, int depth = -1) const;
    int minDepthHelper(const Node<T>* root, int& minDepth, int depth = -1) const;
    int getFirstDepth(const Node<T>* root, int depth = -1) const;

    T* maxHelper(Node<T>* root) const;
    T* minHelper(Node<T>* root) const;

	bool isBalancedHelper(const Node<T>* root) const;
	bool isLeaf(const Node<T>* root) const;

   public:
    BTree();
    BTree(const std::initializer_list<T>& initList);
    ~BTree();

    const T* lookUp(const T& data) const;
    void insert(const T& data);
    void remove(const T& data);
    void clear();

    std::size_t getSize() const;
	int getHeight(const T& data) const;
	int getHeight() const;

    int getDepth(const T& data) const;
    std::size_t getMaxDepth() const;
    int getMinDepth() const;

    T* getMax() const;
    T* getMin() const;

    bool isBalanced() const;

    void printInorder() const;
    void printPreorder() const;
    void printPostorder() const;

    friend std::ostream& operator<<(std::ostream& os, const BTree<T>& tree) {
        tree.printHelper(os, tree.root_);
		return os;
    }
};
} // namespace BinaryTree

#include "binary_tree.ipp"

#endif // BINARY_TREE_H