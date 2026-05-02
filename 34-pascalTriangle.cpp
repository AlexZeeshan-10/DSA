#include<bits/stdc++.h>
using namespace std;

// generating pascal triangle row
vector<long long> TriangleRow(int row){
    long long ans = 1;
    vector<long long> ansRow;
    ansRow.push_back(1);

    for(int col = 1; col < row; col++){
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }

    return ansRow;
}

vector<vector<long long>> generateTriangle(int n){
    vector<vector<long long>> ans;

    for(int i = 1; i <= n; i++){
        ans.push_back(TriangleRow(i));
    }

    return ans;
}

int main(){
    int n;
    cin >> n;

    vector<vector<long long>> res = generateTriangle(n);

    // print triangle
    for(auto row : res){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}