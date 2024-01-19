#include "node.h"

namespace BinaryTree {
template <typename T>
Node<T>::Node() : data(T()), left(nullptr), right(nullptr) {}

template <typename T>
Node<T>::Node(const T& data) : left(nullptr), right(nullptr) {
    this->data = data;
}

template <typename T>
const Node<T>& Node<T>::operator>(const Node<T>& other) const {
    return other.data > this->data ? other : *this;
}
} // namespace BinaryTree