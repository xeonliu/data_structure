//
// Created by SJTU on 2023/3/26.
//

#include "doctest.h"
#include "bTree.h"

TEST_CASE("a"){
    binaryTree<char> tree;
    tree.createTree('@');
    tree.preOrder();
    tree.midOrder();
    tree.postOrder();
    tree.levelOrder();
}