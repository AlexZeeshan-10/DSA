#include<bits/stdc++.h>
using namespace std;

/*
The brute force solution takes almost n^3 time complexity so I'm skipping that for now for reference visit the video 30 once again. That was not that complicated you just need to run an iteration for looking out for zeros in the matrix and marking them as -1 to mark them you needed another funtion which occupied another time complexity. Finally you would run another iteration to mark all the -1 as 0 to completely replace all the ones as zeros in the adjacent column and row.
*/


// Brute for approach to set zeros in the matrix


int main(){
    int n, m;
    cin >> m;
    cin >> n;
    
    // Create a 2D vector (matrix) with 'm' rows and 'n' columns, initialized to 0
    vector<vector<int>> matrix(m, vector<int>(n, 0));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
       
}