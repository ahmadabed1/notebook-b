/*

By:Ahmad Abed 

*/
#include <iostream>
#include <stdexcept>
#include "Direction.hpp"
#include "Notebook.hpp"
using namespace std;
using namespace ariel;
const int num0 = 0;
const int num32 = 32;
const int num99 = 99;
const int num100 = 100;
const int num126 = 126;
const int num127 = 127;
 void Notebook::erase(int page,  int row,  int col, Direction direction,  int text_length)
    {
        if(col > num99)
        {
            throw runtime_error("max of col is 99");
        }

        if(col + text_length > num100&& direction == Direction::Horizontal)
        {
            throw runtime_error("limit is 100 letters for row");
        }
        if(page < num0 || row < num0 || col < num0 || text_length < num0)
        {
            throw runtime_error("only positive numbers page");
        }
         if(direction == Direction::Vertical){
            for(int i=0; i<text_length; i++){
                this->notebook[page][row+i][col] = '~';
            }
        }
        if(direction == Direction::Horizontal){
            for(int i=0; i<text_length; i++){
                this->notebook[page][row][col+i] = '~';
            }
        }
        if(direction != Direction::Horizontal){}
        
    }
    void Notebook::write(int page,  int row,  int col, Direction direction, string word)
    {

        if(page < num0 || col < num0 || row < num0 || word.length() < num0 || col > num99)
        {
            throw runtime_error("error");
        }
        if( col + (int)word.length() > num100  && direction == Direction::Horizontal)
        {
            throw runtime_error("100 row");
        }
        for(unsigned int i = 0; i < word.length(); i++){
            if(word[i] < num32 || word[i] > num126){
                throw runtime_error("uncorrect symbol appears in text");
            }
        }

        if(direction == Direction::Horizontal){
            for(int i=0; i<word.length(); i++){
                char char1 = this->notebook[page][row][col+i];
                char char2 = word[(unsigned int)i];

                if (char1 != '_' && char1 < num127 && char1 > num32){
                    throw runtime_error("cant write on  text");
                }
                if (char2 == '~'){
                    throw runtime_error("cant write '~' ");
                }
                    this->notebook[page][row][col+i] = char2;
                
            }
        }
        if(direction == Direction::Vertical){
            for(int i=0; i<word.length(); i++){
                char char1 = this->notebook[page][row+i][col];
                char char2 = word[(unsigned int)i];
                if (char2 == '~'){
                    throw runtime_error("You can't write '~' ");
                }
                if(char1 != '_' && char1 > num32 && char1 < num127){
                    throw runtime_error("you can't write on text");
                }
                this->notebook[page][row+i][col] = char2;
            }
        }
        if(direction != Direction::Vertical){cout << 0;}

    }

    void Notebook::show(int page){
        if(page < 0){
            throw runtime_error("only positive numbers");
        }
            for(int i = 0; i<num126; i++){
            cout<<i<<':'<<" ";
            for(int j = 0; j < num100; j++){
                char char1 = this->notebook[page][i][j];
                if(char1 > num126 ||char1 < num32 ){
                    cout<<'_';
                }
                else if(char1 < num126 ||char1 > num32){
                    cout<<char1;
                }
            }
            cout<<"\n";
        }
        
        
    }



    string Notebook::read(int page,  int row,  int col, Direction direction,  int text_length)
    {

        string show;
        if(col > num99)
        {
            throw runtime_error("max of col is 99");
        }
        if(  direction == Direction::Horizontal&& col + text_length > num100)
        {
            throw runtime_error("limit is 100 letters for row");
        }
        if(page < num0 ||col < num0|| row < num0|| text_length < num0)
        {
            throw runtime_error("only positive numbers!!");
        }
        if(direction == Direction::Vertical){
            for(int i=0; i < text_length; i++){
                char char1 = this->notebook[page][row+i][col];
                if(char1 < num32 || char1 > num126){
                    show+='_';
                }
                else{
                    show += char1;
                }
                
            }
            
        }
        if(direction == Direction::Horizontal){
            for(int i=0; i<text_length; i++){
                char char1 = this->notebook[page][row][col+i];
                if(char1 < num32 || char1 > num127){
                    show+='_';
                }
                else{
                    show += char1;
                }
            }
        }
        
        return show;
    }


    
    
    

