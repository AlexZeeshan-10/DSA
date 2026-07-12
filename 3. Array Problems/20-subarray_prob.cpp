#include <bits/stdc++.h>
using namespace std;

int longest_subarray(vector<int> &arr, int k)
{
    int left = 0, right = 0;
    long long sum = arr[0];
     int maxLen = 0;
     int n = arr.size();
     while (right < n)
     {
        while (left < right && sum > k)
        {
            sum -= arr[left];
            left++;
        }
        if(sum == k)        {
            maxLen = max(maxLen, right-left+1);
        }
        right++;
        if(right < n) sum += arr[right];
     }
     return maxLen;
}

int main()
{
    int n, k;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }

    cin >> k;
    int s = longest_subarray(arr, k);
    cout << s << " ";
}