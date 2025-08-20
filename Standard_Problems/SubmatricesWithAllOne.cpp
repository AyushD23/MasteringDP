#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

// Counts number of square submatrices with all ones
int countSquares(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int totalSquares = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
                totalSquares += dp[i][j];
            }
        }
    }
    return totalSquares;
}

int main() {
    vector<vector<int>> matrix1 = {
        {0,1,1,1},
        {1,1,1,1},
        {0,1,1,1}
    };
    cout << "Count squares for matrix 1: " << countSquares(matrix1) << endl; 
    vector<vector<int>> matrix2 = {
        {1,0,1},
        {1,1,0},
        {1,1,0}
    };
    cout << "Count squares for matrix 2: " << countSquares(matrix2) << endl; 
    return 0;
}
