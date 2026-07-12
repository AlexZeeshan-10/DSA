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


// Optimal approach for Max sum of subarray
int Kadane_algo(vector<int> &arr)
{
    int sum = 0, maxi = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum > maxi)
        {
            maxi = sum;
        }

        if (sum < 0)
            sum = 0;
    }
    if (maxi < 0)
        return 0;
    else
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
     int c =Kadane_algo(arr);
     cout << c << " ";


}