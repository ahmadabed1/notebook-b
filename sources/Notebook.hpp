#include <iostream>
#include <stdexcept>
#include "Direction.hpp"
#include <map>
#include <vector>
const int char_size=100;

using namespace std;

namespace ariel{
    class Notebook{

       
       


        public:
        map< int, map<int, char[char_size]> > notebook;
        int  min_row, min_col,min_pages,max_pages, max_row, max_col;
        Notebook(){}
        ~Notebook(){}
        void show(int page);
        string read(int page, int row,int col, Direction direction, int text_length);
        void erase(int page, int row,int col, Direction direction, int text_length);
        void write(int page, int row, int col, Direction direction, string word);
        
    };
    
}