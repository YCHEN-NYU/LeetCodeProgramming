#include <iostream>
#include <vector>
using namepspace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    if(matrix.size() == 0) return res;
    
    int ROWS = matrix.size(), COLUMNS = matrix[0].size();
    int leftCol = 0, rightCol = COLUMNS - 1;
    int topRow = 0, botRow = ROWS - 1;
    cout << "topRow = " << topRow << endl;
    while(topRow <= botRow && leftCol <= rightCol){
        // left to right
        if(leftCol <= rightCol && topRow <= botRow){
            for(int col = leftCol; col <= rightCol; col++)
                res.push_back(matrix[topRow][col]);
            ++topRow;
        }
        
        
        if(leftCol <= rightCol && topRow <= botRow){
            for(int row = topRow; row <= botRow; row++)
                res.push_back(matrix[row][rightCol]);
        }
        --rightCol;
        
        if(leftCol <= rightCol && topRow <= botRow){
            for(int col = rightCol; col >= leftCol; col--)
                res.push_back(matrix[botRow][col]);
        }
        
        --botRow;
        
        if(leftCol <= rightCol && topRow <= botRow){
            for(int row = botRow; row >= topRow; row--)
                res.push_back(matrix[row][leftCol]);
        }
        
        ++leftCol;
    }
    return res;
}
    
    
int main(){
    
    return 0;
}
