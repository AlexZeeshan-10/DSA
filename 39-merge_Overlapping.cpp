#include <bits/stdc++.h>
using namespace std;


// merge overlapping intervals in 2D array
vector<vector <int>> mergeOver(vector<vector <int>> &arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector <int>> ans;
    for (int i = 0; i < n; i++)
    {
        if(ans.empty() || arr[i][0] > ans.back()[1]){
            ans.push_back(arr[i]);
        }
        else{
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cin >> arr[i][j];
        }
    }
     
}