//
// Created by SJTU on 2023/3/14.
//

#ifndef NEW_DATASTRUCTURE_QUEUE_H
#define NEW_DATASTRUCTURE_QUEUE_H

template<class elemType>
class queue {
public:
    virtual bool isEmpty() const =0;
    virtual void enQueue(const elemType &x) =0;
    virtual elemType deQueue() =0;
    virtual elemType getHead() const =0;
    virtual ~queue(){ };
};


#endif //NEW_DATASTRUCTURE_QUEUE_H
