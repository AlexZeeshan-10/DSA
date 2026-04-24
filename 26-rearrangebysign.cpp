#include <bits/stdc++.h>
using namespace std;

vector<int> rearrange(vector<int> &arr)
{
    vector<int> ans(arr.size(), 0);
    int posIndex = 0, negIndex = 1;
    for (int nums : arr)
    {
        if (nums < 0)
        {
            ans[negIndex] = nums;
            negIndex += 2;
        }
        else
        {
            ans[posIndex] = nums;
            posIndex += 2;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
    vector<int> ans(arr.size(), 0);
    ans = rearrange(arr);
    for (int it : ans)
    {
        cout << it << " ";
    }
}