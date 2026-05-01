#include <bits/stdc++.h>
using namespace std;

// Better solution for Subarray sum that is equal to k
int subArraySum(vector<int> &arr, int k)
{
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0; // Reset sum for each new starting index
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            if (sum == k)
                count++;
        }
    }
    return count;
}


// Better solution for Subarray sum that is equal to k
int subArraySumOpt(vector<int> &arr, int k){
    map<int, int> mpp;
    mpp[0] = 1;
    int preSum = 0, cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        preSum += arr[i];
        int remove = preSum - k;
        cnt += mpp[remove];
        mpp[preSum] += 1;
    }
    return cnt;
}

int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    vector<int> arr(n, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }

    int ans = subArraySumOpt(arr, k);
    cout << ans << " ";
}