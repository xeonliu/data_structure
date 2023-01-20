//
// Created by SJTU on 2023/1/19.
//

#ifndef DATASTRUCTURE_SLLIST_H
#define DATASTRUCTURE_SLLIST_H

#include <iostream>
#include "list.h"

template<class elemType>
class SLList:public list<elemType>{
private:
struct node{
    elemType data;
    node* next;

    node(const elemType &x,node* n= nullptr){
        data = x;
        next = n;
    }
    node():next(nullptr){}
    ~node()=default;
};

// Head node
node* head;

int currentLength;

// Return the address of the ith element.
node* move(int i) const;

public:
    SLList();
    ~SLList(){
        clear();
        delete head;
    }
    void clear();
    int length() const;
    void insert(int i, const elemType &x);
    void remove(int i);
    int search(const elemType &x) const;
    elemType visit(int i) const;
    void traverse() const;
};

template<class elemType>
SLList<elemType>::SLList() {
    head = new node;
    currentLength = 0;
}

/**删除头结点以外的所有节点
 * 让头结点指向nullptr
 * 将currentLength设置为0
 */
template<class elemType>
void SLList<elemType>::clear() {
    node *p = head->next;
    node *q;
    while(p!= nullptr){
        q=p->next;
        delete p;
        p=q;
    }
    currentLength = 0;
}

/** Return current length of SLList */
template<class elemType>
int SLList<elemType>::length() const {
    return currentLength;
}

template<class elemType>
void SLList<elemType>::insert(int i, const elemType &x) {
    //find i-1
    node *p = move(i-1);
    p->next = new node(x,p->next);
    ++currentLength;
}

template<class elemType>
void SLList<elemType>::remove(int i) {
    node *p = move(i-1);
    node *q = p->next;
    p->next = q->next;
    delete q;
    --currentLength;
}

template<class elemType>
int SLList<elemType>::search(const elemType &x) const {
    node *p = head->next;
    int i=0;
    while(p!= nullptr){
        if(p->data==x){
            break;
        }
        ++i;
        p=p->next;
    }
    if(p== nullptr) return -1;
    return i;
}

template<class elemType>
elemType SLList<elemType>::visit(int i) const {
    return move(i)->data;
}

template<class elemType>
void SLList<elemType>::traverse() const {
    node *p = head->next;
    while(p!= nullptr){
        std::cout << p->data << ' ';
        p=p->next;
    }
}

/** Return the address of the ith node (do not include head, start from 0) */
template<class elemType>
typename SLList<elemType>::node* SLList<elemType>::move(int i) const {
    node *p = head;
    for(int j=0;j<=i;++j){
        p = p->next;
    }
    return p;
}

#endif //DATASTRUCTURE_SLLIST_H
