#include <iostream>
#include "Tree.h"

int main(){

    Tree btree;    
    for(int i = 0, j = -25; i < 25 && j < 0; i++, j++){
        btree.insert(i);
        btree.insert(j);
    }
    btree.inorder(btree.get_root());
    return 0;
}