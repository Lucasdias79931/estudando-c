#include <iostream>
#include "Tree.h"
#include "Node.h"

Tree::Tree(int value) {
    this->root = new Node(value);
}

Tree::Tree() {
    this->root = nullptr;
}

void Tree::insert(int value) {
    Node* node = new Node(value);

    if (root == nullptr) {
        root = node;
        return;
    }

    Node* current = root;
    Node* parent = nullptr;

    while (true) {
        parent = current;

        if (value < parent->get_value()) {
            current = parent->get_left();
            if (current == nullptr) {
                parent->insert_left(node);
                return;
            }
        } else {
            current = parent->get_right();
            if (current == nullptr) {
                parent->insert_right(node);
                return;
            }
        }
    }
}

void Tree::inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->get_left());
        std::cout << root->get_value() << " ";
        inorder(root->get_right());
    }
}

Node* Tree::get_root() {
    return root;
}
