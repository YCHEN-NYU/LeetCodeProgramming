#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    vector<vector<int>> matrix;
    matrix = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
    int N = matrix.size();
    int sum = 0;
    for(int i = 0; i < 3; i++){
        cout << "matrix[i][i] = " << matrix[i][i] << endl;
        sum += matrix[i][i];
    }
    for(int j = 0; j < 3; j++){
        cout << "matrix[j][2 - j] = " << matrix[j][2 - j] << endl;
        sum += matrix[j][2 - j];
        // delete the repeated count: center element of the matrix
    }   sum -= matrix[N/2][N/2];
    
    cout << "sum = " << sum << endl;
    
}

