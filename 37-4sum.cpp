#include <bits/stdc++.h>
using namespace std;

// better function to returing quad that sums up to the target value
vector<vector<int>> fourSumbtr(vector<int> &arr, int target)
{
    int n = arr.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}