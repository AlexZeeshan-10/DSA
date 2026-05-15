#include <bits/stdc++.h>
using namespace std;

int maxProductBrute(vector<int> &arr)
{
    int maxi = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        int product = 1;
        for (int j = i; j < arr.size(); j++)
        {
            product *= arr[j];
            maxi = max(maxi, product);
        }
    }
    return maxi;
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
    int ans = maxProductBrute(arr);
    cout << ans << " ";
}