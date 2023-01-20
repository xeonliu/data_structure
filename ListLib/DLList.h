//
// Created by SJTU on 2023/1/20.
//

#ifndef NEW_DATASTRUCTURE_DLLIST_H
#define NEW_DATASTRUCTURE_DLLIST_H

#include <iostream>
#include "list.h"
template<class elemType>
class DLList : public list<elemType>{
private:
    struct node{
        elemType data;
        node* prev;
        node* next;

        node(const elemType &x,node* p= nullptr, node* n= nullptr){
            data =x;
            prev = p;
            next = n;
        }

        node():prev(nullptr),next(nullptr){}
        ~node()= default;
    };

    node *head,*tail;
    int currentLength;

    node* move(int i) const;

public:
    DLList();
    ~DLList(){
        clear();
        delete head;
        delete tail;
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
int DLList<elemType>::search(const elemType &x) const {
    node *p = head->next;
    int i=0;
    while(p!=tail){
        if(p->data==x){
            return i;
        }
        p=p->next;
        ++i;
    }
    return -1;
}

/**Return the address of node i
 * Must be able to access the head and the tail*/
template<class elemType>
typename DLList<elemType>::node *DLList<elemType>::move(int i) const {
    node *p = head;
    for(int j=0;j<=i;++j){
        p=p->next;
    }
    return p;
}

template<class elemType>
DLList<elemType>::DLList() {
    head = new node;
    tail = new node;
    head->next = tail;
    tail->prev = head;
    currentLength = 0;
}

template<class elemType>
void DLList<elemType>::clear() {
    node *p = head->next;
    node *q;
    head->next = tail;
    tail->prev = head;
    while(p!=tail){
        q = p->next;
        delete p;
        p = q;
    }
}

template<class elemType>
int DLList<elemType>::length() const {
    return currentLength;
}

template<class elemType>
void DLList<elemType>::insert(int i, const elemType &x) {
    node *p = move(i-1);
    node *q = new node(x,p,p->next);
    p->next = q;
    q->next->prev = q;
    ++currentLength;
}

template<class elemType>
void DLList<elemType>::remove(int i) {
    node *p = move(i-1);
    node *q = p->next;
    p->next = q->next;
    q->next->prev = p;
    delete q;
    --currentLength;
}


template<class elemType>
elemType DLList<elemType>::visit(int i) const {
    return move(i)->data;
}

template<class elemType>
void DLList<elemType>::traverse() const {
    node *p = head->next;
    while(p!=tail){
        std::cout << p->data << ' ';
        p=p->next;
    }
}

#endif //NEW_DATASTRUCTURE_DLLIST_H
