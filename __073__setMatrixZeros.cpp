/*
 73. Set Matrix Zeroes
 Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
 
 Example 1:
 Input:
 [
 [1,1,1],
 [1,0,1],
 [1,1,1]
 ]
 Output:
 [
 [1,0,1],
 [0,0,0],
 [1,0,1]
 ]
 
 Example 2:
 Input:
 [
 [0,1,2,0],
 [3,4,5,2],
 [1,3,1,5]
 ]
 Output:
 [
 [0,0,0,0],
 [0,4,5,0],
 [0,3,1,0]
 ]
 */

#include <iostream>
#include <vector>
using namespace std;


void setZeroes(vector<vector<int>>& matrix) {
    
    int ROWS = matrix.size(), COLUMNS = matrix[0].size();
    
    // use first row and first col to store zero information
    // check first row, set matrix[0][0] = 0 if there's zero values in row zero
    bool rowHasZero = false;
    for(int col = 0; col < COLUMNS; col++){
        if(matrix[0][col] == 0){
            rowHasZero = true;
            break;
        }
    }
    
    // check first column
    bool colHasZero = false;
    for(int row = 0; row < ROWS; row++){
        if(matrix[row][0] == 0){
            colHasZero = true;
            break;
        }
    }
    
    // check row: 1 to end, col: 1 to end
    for(int row = 1; row < ROWS; row++){
        for(int col = 1; col < COLUMNS; col++){
            if(matrix[row][col] == 0)
                matrix[0][col] = 0;
                matrix[row][0] = 0;
        }
    }
    
    
    for(int col = 1; col < COLUMNS; col++){
        if(matrix[0][col] == 0){
            for(int row = 1; row < ROWS; row++)
                matrix[row][col] = 0;
        }
    }
    
    for(int row = 1; row < ROWS; row++){
        if(matrix[row][0] == 0){
            for(int col = 1; col < COLUMNS; col++)
                matrix[row][col] = 0;
        }
    }
    
    if(rowHasZero){
        for(int col = 0; col < COLUMNS; col++)
            matrix[0][col] = 0;
    }
    
    if(colHasZero){
        for(int row = 0; row < ROWS; row++)
            matrix[row][0] = 0;
    }
}

void printMatrix2D(vector<vector<int>> &matrix){
    for (int row = 0; row < matrix.size(); row++) {
        cout << "[";
        for (int col = 0; col < matrix[0].size(); col++) {
            cout << matrix[row][col];
            if(col != matrix[0].size() - 1) cout << ", ";
            else    cout << "]";
        } cout << endl;
    }
}

int main(){
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    cout << "original matrix: " << endl;
    printMatrix2D(matrix);
    
    setZeroes(matrix);
    cout << "zero-ed matrix: " << endl;
    printMatrix2D(matrix);
    return 0;
}
