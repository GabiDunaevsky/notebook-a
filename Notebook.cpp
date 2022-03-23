#include "Notebook.hpp"

#include <exception>
#include <stdexcept>
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

namespace ariel
{   
    // Constructor
    Notebook::Notebook(){   
    }
    
    // Destructor
    Notebook::~Notebook(){}

    // write function throwing all the exceptions.
    void Notebook::write(int page, int row, int column,Direction dir , string const & word){
        int wLen = word.size();
        if (word.find('~') != string::npos){
        throw invalid_argument( "the char '~' can't be written" );
    }
    
        // string place=read(page, row, column, dir, word.length());
        // bool ans= true;
        // for (char c : place) {
        //     if(c !='_') {
        //     ans = false;
        //     }
        // }
        // if(!ans){
        //     throw invalid_argument( "This place is already writen" );
        // }


        if(column >= maxColLen){throw invalid_argument("Your massage is over the row limit.");}
        if(column + wLen > maxColLen && dir == Direction::Horizontal){ throw invalid_argument("Your massage is over the row limit.");}
        if(page < 0|| row < 0 || column < 0){ throw invalid_argument("One of your params is negative.");}
    }

    // read function throwing all the exceptions.
    string Notebook::read( int page,int row,  int column, Direction dir, int len){
        if(column >= maxColLen){throw invalid_argument("Your massage is over the row limit.");}
        if(column + len > maxColLen && dir == Direction::Horizontal ){ throw invalid_argument("Your massage is over the row limit.");}
        if(page < 0 || row < 0 || column < 0){ throw invalid_argument("One of your params is negative.");}
        return " ";
    }
// erase function throwing all the exceptions.
    void Notebook::erase( int page, int row,  int column, Direction dir,  int len){
        if(column >= maxColLen){throw invalid_argument("Your massage is over the row limit.");}
        if(column +len > maxColLen && dir == Direction::Horizontal ){ throw invalid_argument("Your massage is over the row limit.");}
        if(page < 0 || row < 0|| column < 0){ throw invalid_argument("One of your params is negative.");}
    }

    
    void Notebook::show(int page){
    }
}