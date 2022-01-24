#include <iostream>
#include "BinaryTree.h"

template<class T>
void insertNode(T currData, BinaryNode<T> *&currRoot)
{
    if(currRoot == nullptr)
    {
        currRoot = new BinaryNode<T> (currData);
        
    }
    else if(currData < currRoot->data)
    {
        insertNode(currData, currRoot->left);
    }
    else if(currData > currRoot->data)
    {
        insertNode(currData, currRoot->right);
    }
    else
    {
        ; //Do nothing, are not adding duplicates
        //if we were adding duplicates, then we would have 
        //to decide on what to do with the duplicates
        //we could either add them to the left by checking
        //if currData <= currRoot->data, OR
        // we could add right by checking if
        //currData >= currRoot->data
    }
    
}

template<class T>
void BinaryTree<T>::insert(T item)
{
    insertNode(item,root);
    size++;
}

template<class T>
BinaryNode<T> *findNode(T currData, BinaryNode<T> *&root)
{
    if(root == nullptr) //empty tree
    {
        //std::cout << "Node not found" << std::endl;
        return nullptr;
    }
    else if(currData < root->data) //go left
    {
        return findNode(currData, root->left);
    }
    else if(currData > root->data)  //go right
    {
        return findNode(currData, root->right);
    }
    else
    {
        //std::cout << "The node containing '" << root->data << "' was found" << std::endl;
        return root;
    }
}


template<class T>
bool BinaryTree<T>::find(T data)
{
    
    return findNode(data, root); 
}

template<class T>
BinaryNode<T> *findMin(BinaryNode<T> *root)
{
    if(root == nullptr)
    {
        return nullptr;
    }
    else if(root->left == nullptr)
    {
        return root;
    }

    return findMin(root->left);
}

template<class T>
BinaryNode<T> *findMax(BinaryNode<T> *root)
{
    if(root == nullptr)
    {
        return nullptr;
    }
    else if(root->right == nullptr)
    {
        return root;
    }

    return findMax(root->right);
}

template<class T>
void removeNode(T currData, BinaryNode<T> *&currRoot)
{
    if(currRoot == nullptr)
    {
        return; //item not found do nothing
    }
    if(currData < currRoot->data) //go left
    {
        removeNode(currData, currRoot->left);
    }
    else if(currData > currRoot->data) //go right
    {
        removeNode(currData, currRoot->right);
    }
    else //work on removing the found node
    {
        BinaryNode<T> *oldNode;
        if(currRoot->left == nullptr)  //has a right child or no children
        {
            oldNode = currRoot;
            currRoot = currRoot->right;
            delete oldNode;
            return;
        }
        else if(currRoot->right == nullptr) //has a left child 
        {
            oldNode = currRoot;
            currRoot = currRoot->left;
            delete oldNode;
            return;
        }
        else //has 2 children
        {
            oldNode = findMin(currRoot->right);
            currRoot->data = oldNode->data;
            removeNode(currRoot->data, currRoot->right);
        }

    }

}

template<class T>
void BinaryTree<T>::remove(T data)
{
    removeNode(data, root);
}

template<class T>
void BinaryTree<T>::inOrder(BinaryNode<T> *root)
{
    if(root == nullptr)
    {
        return;
    }
    inOrder(root->left);
    std::cout << root->data << " ";
    inOrder(root->right);
}

template<class T>
void BinaryTree<T>::printInOrder()
{
    inOrder(root);
    std::cout << std::endl;
}

