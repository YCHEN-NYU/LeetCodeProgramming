/*
 74. Search a 2D Matrix
 Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 
 Integers in each row are sorted from left to right.
 The first integer of each row is greater than the last integer of the previous row.
 Example 1:
 
 Input:
 matrix = [
 [1,   3,  5,  7],
 [10, 11, 16, 20],
 [23, 30, 34, 50]
 ]
 target = 3
 Output: true
 Example 2:
 
 Input:
 matrix = [
 [1,   3,  5,  7],
 [10, 11, 16, 20],
 [23, 30, 34, 50]
 ]
 target = 13
 Output: false
 */

#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(matrix.size() == 0)    return false;
    int ROWS = matrix.size(), COLUMNS = matrix[0].size();
    int low = 0, high = ROWS*COLUMNS - 1;
    
    while(low <= high){
        int mid = (low + high)/2;
        int midRow = mid/COLUMNS, midCol = mid%COLUMNS;
        if(target == matrix[midRow][midCol])
            return true;
        else{
            if(target < matrix[midRow][midCol])
                high = mid - 1;
            else
                low = mid + 1;
        }
    }
    return false;
}


int main(){
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    int target = 3;
    
    cout << searchMatrix(matrix, target) << endl;
}
