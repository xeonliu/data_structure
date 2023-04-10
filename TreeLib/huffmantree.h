//
// Created by SJTU on 2023/4/2.
//
/*
 * 感觉到huffman树元素就是一个大集合，在对集合进行处理并且得到一棵树*/
#ifndef NEW_DATASTRUCTURE_HUFFMANTREE_H
#define NEW_DATASTRUCTURE_HUFFMANTREE_H

#include <iostream>

template <class T>
class HuffmanTree{
private:
    //node的成员：父，子，权重，元素
    struct node{
        int father;
        int lchild;
        int rchild;
        int weight;
        T elem;
//        //构造函数（子节点应默认为-1,便于构造叶）（在构造非叶时，elem怎么处理？不初始化？）
//        node(T e,int w):elem(e),father(-1),lchild(-1),rchild(-1),weight(w){}
//        //适用于非叶的构造函数（关注子和权重）
//        node(int l,int r,int w):father(-1),lchild(l),rchild(r),weight(w){}
        node():father(-1),lchild(-1),rchild(-1){}
    };
    //一个储存树的数组
    node* huff;
    //叶的个数
    int size;
public:
    //构造函数（通过标准输入流构造huffman树）
    HuffmanTree(int n):size(n){
            //这里生成数组时已经调用了默认构造函数！
            huff = new node[2*n-1];
            //输入n个数
            int w;
            T e;
            for(int i=n-1;i<2*n-1;++i){
                std::cin >> e;
                std::cin >> w;
                huff[i].elem = e;
                huff[i].weight = w;
            }
            //构造整棵树
            for(int lpointer=n-1;lpointer>0;--lpointer){
                //权重最小值
                //只能初始化为最大整数，否则后患无穷！！！
                int min1 = 32767;
                int min2 = 32767;
                //权重最小元素位置
                int min1p = lpointer;
                int min2p = lpointer;
                //找出所有无父元素中权重最小的两个
                //不同元素权值相同如何处理？？？？？？？
                for(int i=lpointer;i<2*n-1;++i){
                    if(huff[i].father==-1){
                        if(huff[i].weight<min1){
                            //关键！必须交换位置
                            min2 = min1;
                            min2p = min1p;
                            min1 = huff[i].weight;
                            min1p = i;
                        }else if(huff[i].weight<min2){
                            min2 = huff[i].weight;
                            min2p = i;
                        }
                    }
                }
                //创树
                huff[lpointer-1].lchild = min1p;
                huff[lpointer-1].rchild = min2p;
                huff[lpointer-1].weight = min1+min2;
                //添父
                huff[min1p].father = lpointer-1;
                huff[min2p].father = lpointer-1;
            }
    }
    //编码（给定元素）（标准输出流输出）
    void encode(T data){
        //当前节点是上一个节点的左节点还是右节点？？从下向上找，还得逆序输出……是在生成时储存，还是在输出时使用栈或者递归呢？
        //首先查找到元素的位置！
        int position = size-1;
        for(;position<2*size-1;++position){
            if(huff[position].elem==data){
                break;
            }
        }
        while(position!=0){
            int father_pos = huff[position].father;
            if(huff[father_pos].lchild==position){
                //说明是左子
                std::cout << '0';
            }else{
                std::cout << '1';
            }
            position = father_pos;
        }

    }
    //解码（给定一段编码）

};
#endif //NEW_DATASTRUCTURE_HUFFMANTREE_H
