#include "Notebook.hpp"

#include <exception>
#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

namespace ariel
{   
    // Default and minimal size for a message board
    const int DEFAULT_SIZE = 1000;
    const int MIN_SIZE = 1;
    

    // Constructor
    Notebook::Notebook(){   
    }
    
    // Destructor
    Notebook::~Notebook(){}

    
    void Notebook::write(int page, int row, int column,Direction dir , string word){
        int wLen = word.size();
        if(column >= 100){throw invalid_argument("Your massage is over the row limit.");}
        if(column + wLen > maxColLen && dir == Direction::Horizontal){ throw invalid_argument("Your massage is over the row limit.");}
        if(checkNegativity(page) || checkNegativity(row) || checkNegativity(column)){ throw invalid_argument("One of your params is negative.");}
        return;
    }

    // This method get row, column, direction and length of a message as parameters and returns the message in the 
    // appropriate location and diraction in this message board
    string Notebook::read( int page,int row,  int column, Direction dir, int len){
        if(column >= 100){throw invalid_argument("Your massage is over the row limit.");}
        if(column + len > maxColLen && dir == Direction::Horizontal ){ throw invalid_argument("Your massage is over the row limit.");}
        if(checkNegativity(page) || checkNegativity(row) || checkNegativity(column)){ throw invalid_argument("One of your params is negative.");}
        return " ";
    }

    void Notebook::erase( int page, int row,  int column, Direction dir,  int len){
        if(column >= 100){throw invalid_argument("Your massage is over the row limit.");}
        if(column +len > maxColLen && dir == Direction::Horizontal ){ throw invalid_argument("Your massage is over the row limit.");}
        if(checkNegativity(page) || checkNegativity(row) || checkNegativity(column)){ throw invalid_argument("One of your params is negative.");}
        return;
    }

    // This message will print out the entire message board
    void Notebook::show(int page){
    }


    bool Notebook::checkNegativity(int j){
        if(j < 0) 
        {
            return true;
         }
        return false;
        }
}