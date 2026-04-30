#include<bits/stdc++.h>
using namespace std;


//Optimal approach to rotate matrix by clockwise 90 Degrees
void rotateMat(vector<vector <int>> &mat){
    int row = mat.size();
    int col = mat[0].size();

    // Step 1: Transpose the matrix (swap rows with columns)
    for (int i = 0; i < row-1; i++)
    {
        for (int j = i+1; j < col; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
        
    }
    
    // Step 2: Reverse each row individually to complete the clockwise rotation
    for (int i = 0; i < row; i++)
    {
        reverse(mat[i].begin(), mat[i].end());
    }
    
}


int main(){
    int m, n;
    cin >> m;
    cin >> n;
    vector<vector <int>> matrix(m, vector<int> (n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
        
    }
    
    rotateMat(matrix);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
}