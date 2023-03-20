//
// Created by SJTU on 2023/1/22.
//
#include "stack.h"
#ifndef NEW_DATASTRUCTURE_LISTSTACK_H
#define NEW_DATASTRUCTURE_LISTSTACK_H
template<class elemType>
class LStack: public stack<elemType>{
private:
    struct node{
        elemType data;
        node* next;
        node(const elemType &x, node* n = nullptr){
            data = x;
            next = n;
        }
        node():next(nullptr){};
        ~node()=default;
    };

    node* top_p;

public:
    LStack();
    ~LStack();
    bool isEmpty() const;
    void push(const elemType &x);
    elemType pop();
    elemType top() const;

};

template<class elemType>
LStack<elemType>::LStack() {
    //无需头结点
    top_p = nullptr;
}

template<class elemType>
LStack<elemType>::~LStack() {
    while(top_p!= nullptr){
        node* temp = top_p;
        top_p = top_p->next;
        delete temp;
    }
}

template<class elemType>
bool LStack<elemType>::isEmpty() const {
    return top_p == nullptr;
}

template<class elemType>
void LStack<elemType>::push(const elemType &x) {
    top_p = new node(x,top_p);
}

template<class elemType>
elemType LStack<elemType>::pop() {
    node* temp = top_p;
    elemType ans = top_p->data;
    top_p = top_p->next;
    delete temp;
    return ans;
}

template<class elemType>
elemType LStack<elemType>::top() const {
    return top_p->data;
}

#endif //NEW_DATASTRUCTURE_LISTSTACK_H
