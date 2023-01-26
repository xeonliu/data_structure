//
// Created by SJTU on 2023/1/20.
//

#ifndef NEW_DATASTRUCTURE_STACK_H
#define NEW_DATASTRUCTURE_STACK_H
template<class elemType>
class stack{
public:
    virtual bool isEmpty() const =0;
    virtual void push(const elemType &x)=0;
    virtual elemType pop()=0;
    virtual elemType top() const =0;
    virtual ~stack()=0;
};

template<class elemType>
stack<elemType>::~stack() = default;
#endif //NEW_DATASTRUCTURE_STACK_H
