#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <cstddef>
#include <initializer_list>

template <typename T>
struct Node;

namespace BinaryTree {
template <typename T>
class BTree {
   private:
    Node<T>* root_;
	std::size_t size_;

   public:
    BTree();
    BTree(const std::initializer_list<T>& initList);
    ~BTree();

    Node<T>* lookUp(const T& key) const;
    void insert(T data);
    void remove(const T& key);
    void clear();

    std::size_t getSize() const;
    std::size_t getHeight() const;

    std::size_t getMaxDepth() const;
    std::size_t getMinDepth() const;

    T getMax() const;
    T getMin() const;

    bool isBalanced();

    void printInorder() const;
    void printPreorder() const;
    void printPostorder() const;
};
} // namespace BinaryTree

#include "binary_tree.ipp"

#endif // BINARY_TREE_H