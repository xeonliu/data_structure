//
// Created by SJTU on 2023/3/14.
//

#ifndef NEW_DATASTRUCTURE_LINKEDQUEUE_H
#define NEW_DATASTRUCTURE_LINKEDQUEUE_H
#include "queue.h"
template <class elemType>
class linkedQueue : public queue<elemType>{
private:
    struct node{
        elemType item;
        node* next;
        node(elemType i,node* n= nullptr):item(i),next(n){};
        ~node()= default;
    };

    node* rear;
public:
    bool isEmpty() const;
    void enQueue(const elemType &x);
    elemType deQueue();
    elemType getHead() const;
    linkedQueue(){
        rear = nullptr;
    };
    ~linkedQueue(){
        if(isEmpty()){
            return;
        }
        node* temp_head = rear->next;
        rear->next = nullptr;
        node * temp;
        while(temp_head!= nullptr){
            temp = temp_head;
            temp_head = temp_head->next;
            delete temp;
        }

    };
};

template<class elemType>
elemType linkedQueue<elemType>::getHead() const {
    if(!isEmpty()){
        return rear->next->item;
    }
}

template<class elemType>
elemType linkedQueue<elemType>::deQueue() {
    node* temp = rear->next;
    elemType ans = temp->item;
    //出入时都要考虑队伍为空的情况！！！
    if(temp==rear){
        rear = nullptr;
    }else {
        rear->next = temp->next;
    }
    delete temp;
    return ans;
}

template<class elemType>
void linkedQueue<elemType>::enQueue(const elemType &x) {
    if(isEmpty()){
        rear = new node(x);
        rear->next = rear;
    }else {
        rear->next = new node(x, rear->next);
        rear = rear->next;
    }
}

template<class elemType>
bool linkedQueue<elemType>::isEmpty() const {
    return rear== nullptr;
}

#endif //NEW_DATASTRUCTURE_LINKEDQUEUE_H
