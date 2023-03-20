//
// Created by SJTU on 2023/1/20.
//
//
// Created by SJTU on 2023/1/19.
//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "seqQueue.h"
#include "linkedQueue.h"

TEST_CASE("Sequence Queue") {
    seqQueue<int> a;
    SUBCASE("length"){
        CHECK(a.isEmpty());
    }
    SUBCASE("clear"){
        for(int i=0;i<100;++i){
            a.enQueue(i);
        }
        CHECK_EQ(a.getHead(),0);
    }
    SUBCASE("insert"){
        for(int i=0;i<100;++i){
            a.deQueue();
        }
        CHECK(a.isEmpty());
    }
}
TEST_CASE("Linked Queue") {
    linkedQueue<int> a;
    SUBCASE("length"){
        CHECK(a.isEmpty());
    }
    SUBCASE("clear"){
        for(int i=0;i<100;++i){
            a.enQueue(i);
        }
        CHECK_EQ(a.getHead(),0);
        for(int i=0;i<100;++i){
            a.deQueue();
        }
        CHECK(a.isEmpty());
    }
}
