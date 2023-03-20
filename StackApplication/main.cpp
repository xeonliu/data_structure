#include "seqStack.h"
#include "listStack.h"
#include "calc.cpp"
#include <iostream>
int main(){
    char a[10]="1+2*3+5";
    clac c(a);
    c.convert();
}