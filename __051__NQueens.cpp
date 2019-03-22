/*
 51. N-Queens
 The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:

Input: 4
Output: [
         [".Q..",  // Solution 1
          "...Q",
          "Q...",
          "..Q."],
         
         ["..Q.",  // Solution 2
          "Q...",
          "...Q",
          ".Q.."]
         ]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
*/

#include <iostream>
#include <vector>
#include "printMatrix1D.h"
#include "printMatrix2D.h"
using namespace std;

// check matrix[row][col - 1] to 0, return false if 'Q' is found, else return true
bool isValidRow(int n, int row, int col, vector<string> &matrix){
    int c = col - 1;
    while(c >= 0){
        if(matrix[row][c] == 'Q') return false;
        c--;
    }
    return true;
}

// check
bool isValidCol(int n, int row, int col, vector<string> &matrix){
    int r = row - 1;
    while(r >= 0){
        if(matrix[r][col] == 'Q') return false;
        r--;
    }
    return true;
}

bool isValidDiagonal(int n, int row, int col, vector<string> &matrix){
    int r = row - 1, c = col - 1;
    // 135 degree: matrix[row - k][col - k], while r = row - k >= 0 && c = col - k >= 0
    while(r >= 0 && c >= 0){
        if(matrix[r][c] == 'Q') return false;
        r--; c--;
    }
    // 45 degree: matrix[row - k][col + k], while row-k >= 0 && col + k < n
    r = row - 1, c = col + 1;
    while(r >= 0 && c < n){
        if(matrix[r][c] == 'Q') return false;
        r--; c++;
    }
    return true;
}

// look back to check validity of the matrix
bool isValid(int n, int row, int col, vector<string> &matrix){
    // check row, col and diagonal positions
    // see if the current matrix is valid (queens not attaching each other)
    return isValidRow(n, row, col, matrix)
    && isValidCol(n, row, col, matrix)
    && isValidDiagonal(n, row, col, matrix);
}

// use dfs to solve N-Queens problem by backtracking
void dfs(int n, int row, vector<string> &matrix, vector<vector<string>> &solutions){
    
    if(row == n){
        // attach matrix to solutions
        solutions.push_back(matrix);
        return;
    }
    else{
        // traverse current row (col = 0 to n), check if current matrix is valid, then undo the choice
        for(int col = 0; col < n; col++){
            // set current position matrix[row][col] to 'Q'
            matrix[row][col] = 'Q';
            // check if it's valid by using a helper function isValid
            if(isValid(n, row, col, matrix)){
                // move on to the next row
                dfs(n, row + 1, matrix, solutions);
            }
            // undo the choice for next backtracking
            matrix[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n){
    // n x n square matrix
    vector<vector<string>> solutions;
    vector<string> matrix(vector<string>(n, string(n, '.')));
    dfs(n, 0, matrix, solutions);
    return solutions;
}

int main(){
    vector<vector<string>> matrix = solveNQueens(4);
    cout << matrix.size() << endl;
    for(int i = 0; i < matrix.size(); i++){
        printMatrix1D(matrix[i]);
    }
}
