#ifndef BINARYTREE_
#define BINARYTREE_

#include "BinaryNode.h"

template<class T>
class BinaryTree
{
private:
    BinaryNode<T> *root;
    int size;

public:
    BinaryTree() {
        size = 0;
        root = nullptr;
    }

    ~BinaryTree() 
    {
        clear(root);
    }

    void insert(T item);
    bool find(T data);
    void remove(T currData);
    void inOrder(BinaryNode<T> *currRoot); //inOrder traversal
    void preOrder(BinaryNode<T> *currRoot); //preorder traversal
    void postOrder(BinaryNode<T> *currRoot); //postOrder traversal
    void printInOrder();
    void printPreOrder();
    void printPostOrder();


    
    void clear(BinaryNode<T> *root)
    {
        if(root == nullptr)
        {
            return;
        }
        else
        {
            clear(root->left);
            clear(root->right);
            delete root;

        }
    }

    int getSize()
    {
      return size;
    }

    
};
#endif