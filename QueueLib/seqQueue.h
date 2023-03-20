//
// Created by SJTU on 2023/3/14.
//

#ifndef NEW_DATASTRUCTURE_SEQQUEUE_H
#define NEW_DATASTRUCTURE_SEQQUEUE_H
#include "queue.h"
template <class elemType>
class seqQueue: public queue<elemType>{
private:
    elemType* elem;
    int maxSize;
    int front,rear;
    void doubleSpace();

public:
    bool isEmpty() const;
    seqQueue(int initSize=10);
    ~seqQueue(){
        delete []elem;
    }
    void enQueue(const elemType &x);
    elemType deQueue();
    elemType getHead() const;
};

template<class elemType>
elemType seqQueue<elemType>::getHead() const {
    return elem[(front+1)%maxSize];
}

template<class elemType>
elemType seqQueue<elemType>::deQueue() {

    //ATTENTION: front does not point at the first value!
    front = (front+1)%maxSize;
    return elem[front];

}

template<class elemType>
void seqQueue<elemType>::enQueue(const elemType &x) {
    if((rear+1)%maxSize==front){
        doubleSpace();
    }
    rear = (rear+1)%maxSize;
    elem[rear] = x;
}

template<class elemType>
seqQueue<elemType>::seqQueue(int initSize) {
    elem = new elemType[initSize];
    maxSize = initSize;
    front = 0;
    rear = 0;
}

template<class elemType>
void seqQueue<elemType>::doubleSpace() {
    elemType* temp = elem;
    elem = new elemType[maxSize*2];
    //TODO: Copy the elements.
    for(int i=1;i<maxSize;++i){
        elem[i] = temp[(front+i)%maxSize];
    }
    delete []temp;
    front = 0;
    rear = maxSize-1;
    maxSize*=2;
}

template<class elemType>
bool seqQueue<elemType>::isEmpty() const {
    return front==rear;
}

#endif //NEW_DATASTRUCTURE_SEQQUEUE_H
