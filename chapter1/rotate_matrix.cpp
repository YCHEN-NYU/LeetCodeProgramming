/*
 1.7 Rotate matrix. Give an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees. Do it in place.
 */

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// rotate clockwise by 90 degrees
void rotate_matrix_90(vector<vector<int>> &matrix){
    int ROWS = matrix.size(), COLUMNS = matrix[0].size();
    // check if the matrix is square
    if(ROWS == COLUMNS){
        int N = ROWS;
        for (int row = 0; row < N; row++) {
            for(int col = row; col < N - 1 - row; col++){
                int temp = matrix[N - 1 - col][row];
                matrix[N - 1 - col][row] = matrix[N - 1 - row][N - 1 - col];
                matrix[N - 1 - row][N - 1 - col] = matrix[col][N - 1 - row];
                matrix[col][N - 1 - row] = matrix[row][col];
                matrix[row][col] = temp;
            }
        }
    }
}

// rotate counter-clockwise by 90 degrees
void rotate_matrix_270(vector<vector<int>> &matrix){
    int ROWS = matrix.size(), COLUMNS = matrix[0].size();
    // check if the matrix is square
    if(ROWS == COLUMNS){
        int N = ROWS;
        for (int row = 0; row < N; row++) {
            for(int col = row; col < N - 1 - row; col++){
                int temp = matrix[N - 1 - col][row];
                matrix[N - 1 - col][row] = matrix[row][col];
                matrix[row][col] = matrix[col][N - 1 - row];
                matrix[col][N - 1 - row] = matrix[N - 1 - row][N - 1 - col];
                matrix[N - 1 - row][N - 1 - col] = temp;
            }
        }
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

int main(){
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    print_matrix(matrix);
    rotate_matrix_270(matrix);
    print_matrix(matrix);
    
    return 0;
}
