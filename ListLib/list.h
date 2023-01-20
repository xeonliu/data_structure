//
// Created by SJTU on 2023/1/19.
//

#ifndef DATASTRUCTURE_LIST_H
#define DATASTRUCTURE_LIST_H

/** Class template of linear list */
template<class elemType>
class list {
public:
    virtual void clear() = 0; //声明纯虚函数，留待派生类中定义
    virtual int length() const = 0;

    virtual void insert(int i, const elemType &x) = 0;

    virtual void remove(int i) = 0;

    virtual int search(const elemType &x) const = 0;

    virtual elemType visit(int i) const = 0;

    virtual void traverse() const = 0;

    virtual ~list() = default;
};

#endif //DATASTRUCTURE_LIST_H
