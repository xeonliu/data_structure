//
// Created by SJTU on 2023/1/20.
//
#include "doctest.h"
#include "stack.h"
#include "seqStack.h"
#include "listStack.h"

TEST_CASE("sequence stack") {
    seqStack<int> a;
    REQUIRE(a.isEmpty());
    SUBCASE("push"){
        a.push(1);
        CHECK(a.top()==1);
    }
    SUBCASE("pop"){
        a.push(1);
        a.push(2);
        a.pop();
        CHECK(a.top()==1);
    }
}

TEST_CASE("list stack") {
    LStack<int> a;
    REQUIRE(a.isEmpty());
    SUBCASE("push"){
        a.push(1);
        CHECK(a.top()==1);
    }
    SUBCASE("pop"){
        a.push(1);
        a.push(2);
        a.pop();
        CHECK(a.top()==1);
    }
}