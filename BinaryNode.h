#ifndef BINARYNODE_
#define BINARYNODE_

template<class T>
class BinaryNode {
    public:
        T data;
        BinaryNode<T> *left;
        BinaryNode<T> *right;

        BinaryNode(T item) {
            data = item;
            left = nullptr;
            right = nullptr;
        }

};
#endif