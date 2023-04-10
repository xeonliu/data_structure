//
// Created by SJTU on 2023/3/26.
//

//#include "bTree.h"
//
//int main(){
//    binaryTree<char> tree;
//    tree.createTree('@');
//    tree.preOrder();
//    tree.preOrder_iter();
//    tree.midOrder();
//    tree.midOrder_iter();
//    tree.postOrder();
//    tree.postOrder_iter();
//    tree.levelOrder();
//    std::cout << tree.size();
//    std::cout << tree.height();
//}

#include "huffmantree.h"
int main(){
    HuffmanTree<char> a(7);
    a.encode('a');

}