//g++ -o mat mat.cpp

// this program creats mat by this rules:
// 1.the rows and the columns are symetric.
// 2.for every row, in the odd columns will be the char_a, and in the even columns the char_b.
//   until the column which has the same index like the row,
//   from this index, the char will be like the last char.
#include <string>
#include "mat.hpp"
#include <iostream>

using namespace std;

namespace ariel{

string mat(int columns, int rows, char char_a, char char_b) {
    if(columns%2==0 || rows%2==0 || columns < 1 || rows < 1) {
        throw runtime_error("rows and columns must be even and greater than zero");
        }
    if(char_a > '~' || char_a < '!' || char_b > '~' || char_b < '!') {
        throw runtime_error("symbols must be chars");
        }
    string mat;
    int r = 1; 
    char lastChar = char_a; //the char in the 'not symetric' area
    bool start_row_symetric = false;
    while(r <= rows && r > 0) {
        if(r%2==0) {
            lastChar = char_b;
            } else {
                lastChar = char_a;
                }
        for(int c = 1; c <= columns; c++) {
            if(c <= r || c >= columns-r+1) { // columns-r+1 = where the symetric in the column starts
                if(c%2==0) {
                    mat += char_b;
                    } else {
                        mat += char_a;
                        }
            } else { 
                mat += lastChar;
            } 
        }
        mat += '\n';
        if(r == (rows-1)/2+1) { //(rows-1)/2+1 = where the symetric in the rows starts
            start_row_symetric = true;
            }
        if(!start_row_symetric) {r++;}
        else {r--;};
    }
    return mat;
}
}

