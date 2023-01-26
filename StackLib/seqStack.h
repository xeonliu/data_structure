//
// Created by SJTU on 2023/1/20.
//

#ifndef NEW_DATASTRUCTURE_SEQSTACK_H
#define NEW_DATASTRUCTURE_SEQSTACK_H

#include "stack.h"

template<class elemType>
class seqStack : public stack<elemType>{
private:
    /**
     * 1. A pointer pointing at bottom
     * 2. Size of curr Array
     * 3. The position of the top of stack (top_p)
     * 4. doubleSpace()
     * */
     elemType *bottom;
     int maxSize;
     //-1 if empty
     int top_p;
     void doubleSpace();

public:
    /**
     * 1.constructor
     * 2.override functions
     * */
     explicit seqStack(int initSize=10){
         bottom = new elemType[initSize];
         maxSize = initSize;
         top_p = -1;
     }
     ~seqStack(){
         delete[] bottom;
     }
    bool isEmpty() const;
    void push(const elemType &x);
    elemType pop();
    elemType top() const;

};

template<class elemType>
void seqStack<elemType>::doubleSpace() {
    elemType *temp = bottom;
    maxSize*=2;
    bottom = new elemType[maxSize];
    for(int i=0;i<=top_p;++i){
        bottom[i]=temp[i];
    }
}

template<class elemType>
bool seqStack<elemType>::isEmpty() const {
    return top_p==-1;
}

template<class elemType>
void seqStack<elemType>::push(const elemType &x) {
    ++top_p;
    bottom[top_p]=x;
}

template<class elemType>
elemType seqStack<elemType>::pop() {
    return bottom[top_p--];
}

template<class elemType>
elemType seqStack<elemType>::top() const {
    return bottom[top_p];
}

#endif //NEW_DATASTRUCTURE_SEQSTACK_H
