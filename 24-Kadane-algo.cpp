#include <bits/stdc++.h>
using namespace std;

// brute force approach to find max sum of subarray
int maxSum_subarray(vector<int> &arr)
{
    int sum = 0, maxi = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            maxi = max(maxi, sum);
        }
    }
    return maxi;
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
}