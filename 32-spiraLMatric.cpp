#include<bits/stdc++.h>
using namespace std;




int main(){
    int m, n;
    cin >> m;
    cin >> n;

    vector<vector <int>> matrix(m ,vector<int> (n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }


}