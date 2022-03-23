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



//Assuming every empty place is written with '_'.
TEST_CASE("Good input for write") {
    // Good input with the string "hello".
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
    //Edge cases.
    CHECK_NOTHROW(nt.read(0,0,99,Direction:: Horizontal,1)); // last place starting from 0.
    CHECK_NOTHROW(nt.erase(0,0,99,Direction:: Horizontal,1)); // last place starting from 0.
    CHECK_NOTHROW(nt.read(0,0,0,Direction:: Horizontal,100)); // first place starting from 0.
    CHECK_NOTHROW(nt.erase(0,0,0,Direction:: Horizontal,100));// first place starting from 0.
    CHECK_NOTHROW(nt.erase(0,0,99,Direction:: Vertical,100));// Vertical dosent matter
    CHECK_NOTHROW(nt.erase(0,0,0,Direction:: Vertical,100));// Vertical dosent matter
}


TEST_CASE("Page, colum or row are negativ(write,read ,erase)") {
    // While one of them is zero.
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
    CHECK_THROWS(nt.write(-4,-1,0,Direction:: Horizontal,"hi"));// While two of them are zero.
    CHECK_THROWS(nt.write(-4,3,-2,Direction:: Horizontal,"hjk"));// While two of them are zero.
    CHECK_THROWS(nt.write(4,-3,-2,Direction:: Horizontal,"hey"));// While two of them are zero.
    CHECK_THROWS(nt.write(-44,-3,-2,Direction:: Horizontal,"msg"));// While three of them are zero.
    CHECK_THROWS(nt.read(-4,-1,0,Direction:: Horizontal,3));// While two of them are zero.
    CHECK_THROWS(nt.read(-4,3,-2,Direction:: Horizontal,5));// While two of them are zero.
    CHECK_THROWS(nt.read(4,-3,-2,Direction:: Horizontal,2));// While two of them are zero.
    CHECK_THROWS(nt.read(-44,-3,-2,Direction:: Horizontal,7));// While three of them are zero.
    CHECK_THROWS(nt.erase(-4,-1,0,Direction:: Horizontal,3));// While two of them are zero.
    CHECK_THROWS(nt.erase(-4,3,-2,Direction:: Horizontal,5));// While two of them are zero.
    CHECK_THROWS(nt.erase(4,-3,-2,Direction:: Horizontal,2));// While two of them are zero.
    CHECK_THROWS(nt.erase(-44,-3,-2,Direction:: Horizontal,7));// While three of them are zero.
}

TEST_CASE("Bad stringLen input") {
    // A string that is 101 long.
    srand(time(NULL));
    Direction dir;
    Notebook nt;
    string s;
    for(int i = 0 ; i < 101; ++i){
        s+='s';
    }
    CHECK_THROWS(nt.write(5,4,1,Direction:: Horizontal,s));
    // Starting from a random place Horizontal and getting a wrong 120 word + starting column length.
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


//Assuming every empty place is written with '_'.
// TEST_CASE("Invalid input or invali place to write") {
//     Notebook nt;
//     CHECK_THROWS(nt.write(0,0,0,Direction:: Horizontal , "hel~lo" ));
//     CHECK_THROWS(nt.write(0,0,6,Direction:: Vertical , "~" ));
//     nt.write(1,1,5,Direction:: Horizontal , "hello" );
//     CHECK_THROWS(nt.write(1,1,4,Direction:: Horizontal , "a" ));
// }






