/*
 48. Rotate Image
 You are given an n x n 2D matrix representing an image.
 Rotate the image by 90 degrees (clockwise).
  Note:
 
 You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
 
 Example 1:
 
 Given input matrix =
 [
 [1,2,3],
 [4,5,6],
 [7,8,9]
 ],
 
 rotate the input matrix in-place such that it becomes:
 [
 [7,4,1],
 [8,5,2],
 [9,6,3]
 ]
 Example 2:
 
 Given input matrix =
 [
 [ 5, 1, 9,11],
 [ 2, 4, 8,10],
 [13, 3, 6, 7],
 [15,14,12,16]
 ],
 
 rotate the input matrix in-place such that it becomes:
 [
 [15,13, 2, 5],
 [14, 3, 4, 1],
 [12, 6, 8, 9],
 [16, 7,10,11]
 ]
 */


#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int N = matrix.size();
    int temp;
    for(int row = 0; row < N/2; row++){
        for(int col = row; col < N - 1 - row; col++){
            temp = matrix[row][col];
            matrix[row][col] = matrix[N - 1 - col][row];
            matrix[N - 1 - col][row] = matrix[N - 1 - row][N - 1 - col];
            matrix[N - 1 - row][N - 1 - col] = matrix[col][N - 1 - row];
            matrix[col][N - 1 - row] = temp;
        }
    }
}

void printMatrix(vector<vector<int>> &matrix){
    cout << "[" << endl;
    for (int row = 0; row < matrix.size(); row++) {
        cout << "[";
        for (int col = 0; col < matrix[0].size(); col++) {
            cout << matrix[row][col];
            if(col != matrix[0].size() - 1) cout << ", ";
            else    cout << "]" << endl;
        }
    }
    cout << "]" << endl;
}

int main(){
//    vector<vector<int>> matrix = {
//        {1,2,3},
//        {4,5,6},
//        {7,8,9}
//    };
    
    vector<vector<int>> matrix = {
        {5, 1, 9,11},
        {2, 4, 8,10},
        {13, 3, 6,7},
        {15,14,12,16}
    };
    
    printMatrix(matrix);
    rotate(matrix);
    printMatrix(matrix);
    
    
}


