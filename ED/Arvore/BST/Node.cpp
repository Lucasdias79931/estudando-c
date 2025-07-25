// Node.cpp
#include "Node.h"

Node::Node(int value) : value(value) {}
Node::Node() : value(0) {}

void Node::set_value(int value) {
    this->value = value;
}

void Node::insert_left(Node* left) {
    this->left = left;
}

void Node::insert_right(Node* right) {
    this->right = right;
}

Node* Node::get_left() {
    return left;
}

Node* Node::get_right() {
    return right;
}

int Node::get_value() {
    return value;
}
