//
// Created by SJTU on 2023/3/20.
//

#ifndef NEW_DATASTRUCTURE_BTREE_H
#define NEW_DATASTRUCTURE_BTREE_H
#include "iostream"
#include "linkedQueue.h"
#include "listStack.h"
template <class T>
class binaryTree {
    //friend void printTree(const binaryTree &t, T flag);
private:
    struct node{
        node *left,*right;
        T data;

        node():left(nullptr), right(nullptr){}  //No use?
        node(T item, node *l= nullptr,node *r= nullptr):data(item), left(l),right(r){ }
        ~node(){ }
    };

    node* root;
    //note: *&r
    void clear(node* &r){
        if(r== nullptr){
            return;
        }
        clear(r->left);
        clear(r->right);
        delete r;
        r = nullptr;
    }
    //前序遍历 native structure
    void preOrder(node* t) const{
        if(t== nullptr){
            return;
        }
        std::cout << t->data;
        preOrder(t->left);
        preOrder(t->right);
    }

    void postOrder(node *t) const{
        if(t== nullptr){
            return;
        }
        postOrder(t->left);
        postOrder(t->right);
        std::cout << t->data;
    }
    void midOrder(node *t) const{
        if(t== nullptr){
            return;
        }
        midOrder(t->left);
        std::cout << t->data;
        midOrder(t->right);
    }
    node* find(T x,node *t) const {
        if(t->data==x){
            return t;
        }
        if(t== nullptr){
            return nullptr;
        }
        node* temp = find(x,t->left);
        if(temp != nullptr){
            return temp;
        }
        return find(x,t->right);
    }

    int size(node* t){
        if(t== nullptr) return 0;
        return 1+size(t->left)+size(t->right);
    }

    int height(node* t){
        if(t== nullptr){
            return 0;
        }
        int l = height(t->left);
        int r = height(t->right);
        return 1+ ((l>r)?l:r);
    }
public:
    binaryTree():root(nullptr){}
    binaryTree(T x){
        root = new node(x);
    }
    ~binaryTree(){
        //删除所有元素并置为null。前序遍历？
        //调用native recursive function clear()
        clear(root);
    }
    bool isEmpty() const{
        return root == nullptr;
    }

    void preOrder(){
        std::cout << "前序遍历：";
        preOrder(root);
    }

    void preOrder_iter(){
        std::cout << "前序遍历的迭代实现：";
        LStack<node*> s;
        s.push(root);
        node* temp;
        while(!s.isEmpty()){
            temp = s.pop();
            std::cout << temp->data;
            if(temp->right)
                s.push(temp->right);
            if(temp->left)
                s.push(temp->left);
        }
    }


    void midOrder(){
        std::cout << "中序遍历：";
        midOrder(root);
    }

    struct stnode{
        node* n;
        int times;
        stnode(node* nd= nullptr):n(nd),times(0){}
    };
    void midOrder_iter(){
        std::cout << "中序遍历循环实现";
        LStack<stnode> s;
        stnode temp(root);
        s.push(temp);
        while(!s.isEmpty()){
            temp = s.pop();
            //第一次访问
            if(temp.times==0){
                ++temp.times;
                s.push(temp);
                if(temp.n->left){
                    s.push(stnode(temp.n->left));
                }
            }
            //第二次访问
            else if(temp.times==1){
                std:: cout << temp.n->data;
                if(temp.n->right){
                    s.push(stnode(temp.n->right));
                }
            }
        }
    }

    void postOrder(){
        std::cout << "后序遍历：";
        postOrder(root);
    }

    void postOrder_iter(){
        std::cout << "后序遍历递归实现";
        LStack<stnode> s;
        stnode temp(root);
        s.push(temp);
        while(!s.isEmpty()){
            temp = s.pop();
            if(temp.times==0){
                ++temp.times;
                s.push(temp);
                if(temp.n->left){
                    s.push(stnode(temp.n->left));
                }
            }else if(temp.times==1){
                ++temp.times;
                s.push(temp);
                if(temp.n->right){
                    s.push(stnode(temp.n->right));
                }
            }else if(temp.times==2){
                std::cout << temp.n->data;
            }
        }

    }
    void levelOrder(){
        std::cout << "层序遍历";
        linkedQueue<node*> que;
        que.enQueue(root);
        while(!que.isEmpty()){
            node* temp = que.deQueue();
            std::cout << temp->data;
            if(temp->left)
                que.enQueue(temp->left);
            if(temp->right)
                que.enQueue(temp->right);
        }
    }

    void delLeft(T x){
        node* temp = find(x,root);
        if(temp){
            clear(temp->left);
        }
    }
    void delRight(T x){
        node* temp = find(x,root);
        if(temp){
            clear(temp->right);
        }
    }

    T lchild(T x,T flag){
        node* temp = find(x,root);
        if(temp!= nullptr&&temp->left!= nullptr){
            return temp->left->data;
        }
        //return flag? Why not nullptr?(why return type T?)
        return flag;
    }

    void createTree(T flag){
        linkedQueue<node*> que;
        //按照前序遍历方法，先读入根节点。
        T x;
        std::cin >> x;
        root = new node(x);
        que.enQueue(root);
        node* temp;
        T l,r;
        while(!que.isEmpty()){
            temp = que.deQueue();
            std::cin >> l >> r;
            if(l!=flag){
                temp->left = new node(l);
                que.enQueue(temp->left);
            }
            if(r!=flag){
                temp->right = new node(r);
                que.enQueue(temp->right);
            }
        }


    }

    int size(){
        return size(root);
    }

    int height(){
        return height(root);
    }




};
#endif //NEW_DATASTRUCTURE_BTREE_H
