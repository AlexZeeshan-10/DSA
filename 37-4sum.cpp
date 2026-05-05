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
            set<long long> hashset;
            for (int k = j + 1; k < n; i++)
            {
                long long sum = arr[i] + arr[j];
                sum += arr[k];
                long long fourth = target - (sum);
                if (hashset.find(fourth) != hashset.end())
                {
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[fourth]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// Optimal function to returing quad that sums up to the target value
vector<vector<int>> fourSumOpt(vector<int> &arr, int target)
{
    
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