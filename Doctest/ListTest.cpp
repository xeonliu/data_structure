//
// Created by SJTU on 2023/1/20.
//
//
// Created by SJTU on 2023/1/19.
//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "seqList.h"
#include "SLList.h"

TEST_CASE("Sequence List") {
    seqList<int> a;
    a.insert(0,1);
    a.insert(1,2);
    a.insert(2,3);
    a.insert(3,4);
    SUBCASE("length"){
        CHECK(a.length()==4);
        a.insert(0,0);
        CHECK(a.length()==5);
    }
    SUBCASE("insert"){
        a.insert(3,5);
        CHECK(a.visit(3)==5);
        CHECK(a.visit(4)==4);
    }
    SUBCASE("remove"){
        a.remove(2);
        CHECK(a.visit(2)==4);
    }
    SUBCASE("search"){
        CHECK(a.search(3)==2);
    }
}

TEST_CASE("SLList") {
    SLList<int> a;
    a.insert(0,1);
    a.insert(1,2);
    a.insert(2,3);
    a.insert(3,4);
    SUBCASE("length"){
        CHECK(a.length()==4);
        a.insert(0,0);
        CHECK(a.length()==5);
    }
    SUBCASE("insert"){
        a.insert(0,5);
        CHECK(a.visit(0)==5);
    }
    SUBCASE("remove"){
        a.remove(2);
        CHECK(a.visit(2)==4);
    }
    SUBCASE("search"){
        CHECK(a.search(3)==2);
    }
}
