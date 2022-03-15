#include <iostream>
#include "mat.hpp"
using namespace ariel;

using namespace std;

int main() {
        // string str = ariel :: mat(3, 1, '2', '\n');
        // std::cout << str << endl;  
    int columns, rows;
    char char_a, char_b;
    bool valid = true, stop;
    do {
        do{
            std::cout << "please enter an odd and a greater than zero number for columns" << endl;
            cin >> columns;
            if(columns%2==0 || columns < 1) {valid = false;}
            else {valid = true;}
        } while(!valid);
        do{
            std::cout << "please enter an odd and a greater than zero number for rows" << endl;
            cin >> rows;
            if(rows%2==0 || rows < 1) {valid = false;}
            else {valid = true;}
        } while(!valid);
         do{
            std::cout << "please enter the first char" << endl;
            cin >> char_a;
            if(char_a > '~' || char_a < '!') {valid = false;}
            else {valid = true;}
        } while(!valid);
         do{
            std::cout << "please enter the second char" << endl;
            cin >> char_b;
            if(char_b > '~' || char_b < '!') {valid = false;}
            else {valid = true;}
        } while(!valid);
        string str = ariel :: mat(columns, rows, char_a, char_b);
        std::cout << str << endl;               
        std::cout << "enter 0 to stop or 1 to continue" << endl;
        cin >> stop;  
    } while(stop);
 }