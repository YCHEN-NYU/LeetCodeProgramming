#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void zero_matrix(vector<vector<int>> &matrix){
    // find out zero element indices [zeroRows][zeroColumns]
    vector<int> zeroRows, zeroColumns;
    int ROWS = matrix.size(), COLUMNS = matrix[0].size();
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLUMNS; col++) {
            if(matrix[row][col] == 0){
                zeroRows.push_back(row);
                zeroColumns.push_back(col);
            }
        }
    }
    
    for(int i = 0; i < zeroRows.size(); i++){
        for(int col = 0; col < COLUMNS; col++)
            matrix[zeroRows[i]][col] = 0;
    }
    for(int j = 0; j < zeroColumns.size(); j++){
        for(int row = 0; row < ROWS; row++)
            matrix[row][zeroColumns[j]] = 0;
    }
    
}

void print_matrix(vector<vector<int>> &matrix){
    int ROWS = matrix.size(), COLUMNS = matrix[0].size();
    cout << string(20, '-') << endl;
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLUMNS; col++) {
            cout << setw(4) << matrix[row][col];
        }   cout << endl;
    }
    cout << string(20, '-') << endl;
}

int main() {
    vector<vector<int>> matrix = {{0, 2, 3, 4}, {5, 6, 7, 8},
        {9, 10, 11, 12}, {13, 14, 15, 16}};
    print_matrix(matrix);
    zero_matrix(matrix);
    print_matrix(matrix);
    
    return 0;
}
