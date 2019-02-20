/*
 54. Spiral Matrix
 Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 
 Example 1:
 Input:
 [
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
 ]
 Output: [1,2,3,6,9,8,7,4,5]
 Example 2:
 
 Input:
 [
 [1, 2, 3, 4],
 [5, 6, 7, 8],
 [9,10,11,12]
 ]
 Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 */

#include <iostream>
#include <vector>
using namepspace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    if(matrix.size() == 0)  return vector<int>();
    int topRow = 0, botRow = matrix.size() - 1, leftCol = 0, rightCol = matrix[0].size() - 1;
    
    while(topRow <= botRow && leftCol <= rightCol){
        // left to right
        for(int col = leftCol; col <= rightCol; col++){
            res.push_back(matrix[topRow][col]);
        }
        topRow++;
        
        if(topRow <= botRow && leftCol <= rightCol){
            for(int row = topRow; row <= botRow; row++)
                res.push_back(matrix[row][rightCol]);
        }
        rightCol--;
        
        if(topRow <= botRow && leftCol <= rightCol){
            for(int col = rightCol; col >= leftCol; col--){
                res.push_back(matrix[botRow][col]);
            }
        }
        botRow--;
        
        if(topRow <= botRow && leftCol <= rightCol){
            for(int row = botRow; row >= topRow; row--){
                res.push_back(matrix[row][leftCol]);
            }
        }
        leftCol++;
    }
    return res;
}
    
    
int main(){
    
    return 0;
}
