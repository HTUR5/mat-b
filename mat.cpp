#include <string>
#include "mat.hpp"
#include <iostream>

using namespace std;

namespace ariel{
//g++ -o mat mat.cpp
string mat(int columns, int rows, char char_a, char char_b) {
    if(columns%2==0 || rows%2==0 || columns < 1 || rows < 1) {
        throw runtime_error("rows and columns must be even and greater than zero");
        }
    if(char_a > '~' || char_a < '!' || char_b > '~' || char_b < '!') {
        throw runtime_error("symbols must be chars");
        }
    string mat;
    int r = 1; 
    char lastChar = char_a;
    bool start_row_symetric = false;
    while(r <= rows && r > 0) {
        if(r%2==0) {lastChar = char_b;}
        else {lastChar = char_a;}
        for(int c = 1; c <= columns; c++) {
            if(c <= r || c >= columns-r+1) { // columns-r+1 = where the symetric starts
                if(c%2==0) {mat += char_b;}
                else {mat += char_a;}
            } else { 
                mat += lastChar;
            } 
        }
        if(r == (rows-1)/2+1) {start_row_symetric = true;}
        mat += '\n';
        if(!start_row_symetric) {r++;}
        else {r--;};
    }
    return mat;
}
}

// int main() {
//     int columns, rows;
//     char char_a, char_b;
//     bool  valid = true, stop;
//     do {
//         do{
//             std::cout << "please enter an odd and a greater than zero number for columns" << endl;
//             cin >> columns;
//             if(columns%2==0 || columns < 1) {valid = false;}
//             else {valid = true;}
//         } while(!valid);
//         do{
//             std::cout << "please enter an odd and a greater than zero number for rows" << endl;
//             cin >> rows;
//             if(rows%2==0 || rows < 1) {valid = false;}
//             else {valid = true;}
//         } while(!valid);
//          do{
//             std::cout << "please enter the first char" << endl;
//             cin >> char_a;
//             if(char_a > '~' || char_a < '!') {valid = false;}
//             else {valid = true;}
//         } while(!valid);
//          do{
//             std::cout << "please enter the second char" << endl;
//             cin >> char_b;
//             if(char_b > '~' || char_b < '!') {valid = false;}
//             else {valid = true;}
//         } while(!valid);
//         string str = ariel :: mat(columns, rows, char_a, char_b);
//         std::cout << str << endl;               
//         std::cout << "enter 0 to stop or 1 to continue" << endl;
//         cin >> stop;  
//     } while(stop);
//  }