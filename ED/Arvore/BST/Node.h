#ifndef NODE_H
#define NODE_H

class Node {
private:
    int value;
    Node *left = nullptr;
    Node *right = nullptr;

public:
    Node(int value);    
    Node();           

    void set_value(int value);

    void insert_right(Node *right);
    void insert_left(Node *left);

    Node *get_left();
    Node *get_right();
    int get_value();
};

#endif
