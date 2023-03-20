//
// Created by SJTU on 2023/3/6.
//
#include "listStack.h"
#include "cstring"
#include "iostream"
class clac{
    char *expression;
    //按照优先级排序，优先级高的都在后边。
    //出现低级运算符时，高级运算符都可以弹出。先检查后弹出，截至到符号栈为空或者遇到左括号。
    //左括号在遇到右括号时弹出
    enum token{OPAREN, AND, SUB, MULTI, DIV, EXP, CPAREN, VALUE, EOL};
    LStack<int> nums;
    LStack<token> ops;
public:
    clac(char* s){
        expression = new char[strlen(s)+1];
        strcpy(expression,s);
    }
    //从expression中读取下一个字符并返回.
    //全部转化为token和数字。
    token getOP(int &val){
        //跳过空格！
        while(*expression==' '){
            ++expression;
        }
        switch (*expression) {
            case '(':
                ++expression;
                return OPAREN;
                break;
            case '+':
                ++expression;
                return AND;
            case '-':
                ++expression;
                return SUB;
            case '*':
                ++expression;
                return MULTI;
            case '/':
                    ++expression;
                    return DIV;
            case '^':
                    ++expression;
                    return EXP;
            case ')':
                    ++expression;
                    return CPAREN;
            case '\0':
                return EOL;
            default:
                //计算数字！
                val = 0;
                while((*expression)>='0'&&(*expression)<='9'){
                    val=*expression-'0'+val*10;
                    ++expression;
                }
                return VALUE;
        }
    }

    void convert(){
        token lastOp,topOP;
        int retVal;
        while((lastOp=getOP(retVal))!=EOL){
            switch (lastOp) {
                case CPAREN:
                    while((topOP=ops.pop())!=OPAREN){
                        std::cout << topOP;
                    }
                    break;
                case OPAREN:
                    ops.push(OPAREN);
                    break;
                case AND:
                case SUB:
                    while(!ops.isEmpty()&&ops.top()!=OPAREN){
                        std::cout << ops.pop();
                    }
                    ops.push(lastOp);
                    break;
                case MULTI:
                case DIV:
                    while(!ops.isEmpty()&&ops.top()>=MULTI){
                        std::cout << ops.pop();
                    }
                    ops.push(lastOp);
                    break;
                case EXP:
                    ops.push(lastOp);
                    break;
                case VALUE:
                    std::cout << retVal;
                    break;
                case EOL:
                    break;
            }
        }
        while(!ops.isEmpty()){
            std::cout << ops.pop();
        }
    }
};
