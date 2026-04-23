#include <bits/stdc++.h>
using namespace std;

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
    

}