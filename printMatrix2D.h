#ifndef PRINTMATRIX2D_H
#define PRINTMATRIX2D_H

#include <iostream>
#include <vector>
using namespace std;
template<class T>
void printMatrix2D(vector<vector<T>> &matrix){

    cout << "[" << endl;
        for (int row = 0; row < matrix.size(); row++) {
            cout << "[";
            for (int col = 0; col < matrix[row].size(); col++) {
                cout << matrix[row][col];
                if(col != matrix[row].size() - 1) cout << ", ";
                
            } cout << "]" << endl;
        }   cout << "]" << endl;
}

#endif
