#include "node.h"

namespace BinaryTree {
template <typename T>
Node<T>::Node() : data(T()), left(nullptr), right(nullptr) {}

template <typename T>
Node<T>::Node(const T& data) : left(nullptr), right(nullptr) {
    this->data = data;
}
} // namespace BinaryTree