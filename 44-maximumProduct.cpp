#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
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

int maxProduct(vector<int> &arr)
{
    int maxi = arr[0];
    int prefix = 1;
    int suffix = 1;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (prefix == 0)
            prefix = 1;
        if (suffix == 0)
            suffix = 1;
        prefix *= arr[i];
        suffix *= arr[n - i - 1];
        maxi = max(maxi, max(prefix, suffix));
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
    int ans = maxProduct(arr);
    cout << ans << " ";
}