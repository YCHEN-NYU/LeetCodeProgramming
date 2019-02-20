/*
 59. Spiral Matrix II
 Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 
 Example:
 Input: 3
 Output:
 [
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
 ]
 */
#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> generateMatrix(int n) {
    int leftCol = 0, rightCol = n - 1;
    int topRow = 0, botRow = n - 1;
    int i = 1; // i = 1 -> n*n
    vector<vector<int>> res(n, vector<int> (n, 0));
    while(i <= n*n){
        // left to right
        if(leftCol <= rightCol && topRow <= botRow){
            for(int col = leftCol; col <= rightCol; col++){
                res[topRow][col] = i;
                i++;
            }
        }
        topRow++;
        
        // top to bot
        if(leftCol <= rightCol && topRow <= botRow){
            for(int row = topRow; row <= botRow; row++){
                res[row][rightCol] = i;
                i++;
            }
        }
        rightCol--;
        
        // right to left
        if(leftCol <= rightCol && topRow <= botRow){
            for(int col = rightCol; col >= leftCol; col--){
                res[botRow][col] = i;
                i++;
            }
        }
        botRow--;
        
        // bot to top
        if(leftCol <= rightCol && topRow <= botRow){
            for(int row = botRow; row >= topRow; row--){
                res[row][leftCol] = i;
                i++;
            }
        }
        leftCol++;
    }
    return res;
}


int main(){
    
}
