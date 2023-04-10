//
// Created by SJTU on 2023/3/26.
//

#include "bTree.h"

int main(){
binaryTree<char> tree;
tree.createTree('@');
tree.preOrder();
tree.midOrder();
tree.postOrder();
tree.levelOrder();
std::cout << tree.size();
std::cout << tree.height();
}