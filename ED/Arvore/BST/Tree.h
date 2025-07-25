#ifndef TREE_H
#define TREE_H

#include "Node.h"

class Tree {
private:
    Node* root = nullptr;

public:
    Tree(int value);
    Tree();

    void insert(int value);
    void inorder(Node* root);  
    Node* get_root();         
};

#endif
