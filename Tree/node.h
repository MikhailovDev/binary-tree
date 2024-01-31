#ifndef NODE_H
#define NODE_H

namespace BinaryTree {
template <typename T>
struct Node {
	Node();
	Node(const T& data);

    T data;
    Node<T>* left;
    Node<T>* right;

	const Node<T>& operator> (const Node<T>& other) const;
};
} // namespace BinaryTree

#include "node.ipp"

#endif // NODE_H