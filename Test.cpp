#include "doctest.h"
#include "Notebook.hpp"

#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;
using namespace ariel;
using ariel::Direction;






TEST_CASE("Good input for write") {

    srand(time(NULL));
    Direction dir = Direction:: Horizontal;
    Notebook nt;

    for(int i = 0 ; i < 5; i++){
        int col = rand()% 94;
        int row = rand();
        int page = rand();
        string msg = "Hello";
        CHECK_NOTHROW(nt.write(page,row,col,dir,msg));
        
    }
    CHECK_NOTHROW(nt.write(0,0,99,Direction:: Horizontal,"a")); // last place starting from 0.
    CHECK_NOTHROW(nt.write(0,0,99,Direction:: Vertical,"aggergege"));// if it is vertical it dosent matter
}

TEST_CASE("Good input for read and erase") {

    srand(time(NULL));
    Direction dir;
    Notebook nt;

    for(int i = 0 ; i < 5; i++){
        int col = rand()% 100;
        int row = rand();
        int page = rand();
        int len = rand()%(100-col -1);
        if(i%2 == 0) {
            dir = Direction:: Horizontal;
        }else{
            dir = Direction::Vertical; 
        }
        CHECK_NOTHROW(nt.read(page,row,col,dir,len));
        CHECK_NOTHROW(nt.erase(page,row,col,dir,len));  
    }
    CHECK_NOTHROW(nt.read(0,0,99,Direction:: Horizontal,1)); // last place starting from 0.
    CHECK_NOTHROW(nt.erase(0,0,99,Direction:: Horizontal,1)); // last place starting from 0.
    CHECK_NOTHROW(nt.read(0,0,0,Direction:: Horizontal,100)); // first place starting from 0.
    CHECK_NOTHROW(nt.erase(0,0,0,Direction:: Horizontal,100));// first place starting from 0.
    CHECK_NOTHROW(nt.erase(0,0,99,Direction:: Vertical,100));// Vertical dosent matter
    CHECK_NOTHROW(nt.erase(0,0,0,Direction:: Vertical,100));// Vertical dosent matter
}


TEST_CASE("Page, colum or row are negativ(write,read ,erase)") {
    srand(time(NULL));
    Direction dir;
    Notebook nt;

    for(int i = 0 ; i < 20; i++){
        int col = rand()% 94;
        int row = rand();
        int page = rand();
        string msg = "Hello";
        int len = rand()%(94-col -1);
        if(i%2 == 0) {
            dir = Direction:: Horizontal;
        }else{
            dir = Direction::Vertical; 
        }
        int n = rand();
        if(n%3 == 0){
            col = col *-1;
        }else if(n%3 == 1){
            row = row *-1;
        }else{
            page = page * -1;
        }
        CHECK_THROWS(nt.write(page,row,col,dir,msg));
        CHECK_THROWS(nt.read(page,row,col,dir,len));
        CHECK_THROWS(nt.erase(page,row,col,dir,len)); 
    }
    CHECK_THROWS(nt.write(-4,-1,0,Direction:: Horizontal,"hi"));
    CHECK_THROWS(nt.write(-4,3,-2,Direction:: Horizontal,"hjk"));
    CHECK_THROWS(nt.write(4,-3,-2,Direction:: Horizontal,"hey"));
    CHECK_THROWS(nt.write(-44,-3,-2,Direction:: Horizontal,"msg"));
    CHECK_THROWS(nt.read(-4,-1,0,Direction:: Horizontal,3));
    CHECK_THROWS(nt.read(-4,3,-2,Direction:: Horizontal,5));
    CHECK_THROWS(nt.read(4,-3,-2,Direction:: Horizontal,2));
    CHECK_THROWS(nt.read(-44,-3,-2,Direction:: Horizontal,7));
    CHECK_THROWS(nt.erase(-4,-1,0,Direction:: Horizontal,3));
    CHECK_THROWS(nt.erase(-4,3,-2,Direction:: Horizontal,5));
    CHECK_THROWS(nt.erase(4,-3,-2,Direction:: Horizontal,2));
    CHECK_THROWS(nt.erase(-44,-3,-2,Direction:: Horizontal,7));
}

TEST_CASE("Bad stringLen input") {
    srand(time(NULL));
    Direction dir;
    Notebook nt;
    string s;
    for(int i = 0 ; i < 101; ++i){
        s+='s';
    }
    CHECK_THROWS(nt.write(5,4,1,Direction:: Horizontal,s));
    
    for(int j = 0; j < 5;++j){
        string sm ;
        int loc = rand()%100;
        int smLen = 120 - loc;
        for(int m = 0 ; m < smLen;++m){
            sm += 's';
        }
        CHECK_THROWS(nt.write(5,4,loc,Direction:: Horizontal,sm));
    }
}

TEST_CASE("wrong len to read or erase") {
    srand(time(NULL));
    Direction dir;
    Notebook nt;

    for(int i = 0 ; i < 5; ++i){
        int len = 3;
        int loc = rand();
        if(loc < 100){
            len = 150 - loc; 
        } 
        CHECK_THROWS(nt.read(0,4,loc,Direction:: Horizontal,len));
        CHECK_THROWS(nt.erase(0,4,loc,Direction:: Horizontal,len)); 
    }
        CHECK_THROWS(nt.read(0,0,0,Direction:: Horizontal,101));
        CHECK_THROWS(nt.erase(0,0,0,Direction:: Horizontal,101));
}

TEST_CASE("wrong column num (read, erase or write)") {
    Notebook nt;

    CHECK_THROWS(nt.write(0,0,124,Direction:: Horizontal , "hello" ));
    CHECK_THROWS(nt.write(0,0,100,Direction:: Vertical , "hello" ));
    CHECK_THROWS(nt.erase(0,0,100,Direction:: Horizontal , 7 ));
    CHECK_THROWS(nt.erase(0,0,1134,Direction:: Vertical , 4 ));
    CHECK_THROWS(nt.read(0,0,355,Direction:: Vertical , 9 ));
    CHECK_THROWS(nt.read(0,0,100,Direction:: Vertical , 18 ));
}










// TEST_CASE("Test write") {

    

//     Notebook nt;
//     Direction direction = Direction::Horizontal;
//     srand((unsigned)time(NULL));

//     // Testing if message that was posted last is the one to return 
//     for(uint i = 0; i < INPUTS.size(); i++) {
//         direction = i%2 == 0 ? Direction::Horizontal : Direction::Vertical;
//         CHECK_NOTHROW(nt.write(i, 0, direction, INPUTS.at(i)));

//         CHECK(INPUTS.at(i) == nt.read(i, 0, direction, INPUTS.at(i).size()));
//     }

//     string message = "zich";
//     CHECK_NOTHROW(board.post(0,0, direction, message));
//     CHECK(board.read(0,0, direction, message.size()) == message);

//     direction = Direction::Vertical;
//     CHECK_NOTHROW(board.post(0, message.size()-1, direction, "bbbb"));

//     direction = Direction::Horizontal;
//     CHECK(nt.read(0,0, direction, message.size()) != message);
//     CHECK(nt.read(0,0, direction, message.size()) == "aaab");
// }