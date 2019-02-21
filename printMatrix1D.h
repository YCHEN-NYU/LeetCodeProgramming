#ifndef PRINTMATRIX2D_H
#define PRINTMATRIX2D_H

#include <iostream>
#include <vector>
using namespace std;

template<class T>
void printMatrix1D(vector<T> &matrix){
    cout << "[";
    for (int col = 0; col < matrix.size(); col++) {
        cout << matrix[col];
        if(col != matrix.size() - 1)   cout << ", ";
    } cout << "]" << endl;
}

#endif
