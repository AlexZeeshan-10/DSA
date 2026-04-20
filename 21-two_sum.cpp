#include <bits/stdc++.h>
using namespace std;

string two_sum(vector<int> &arr, int s)
{
    int left = 0, right = arr.size() - 1;
    ;
    sort(arr.begin(), arr.end());
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == s)
            return "YES";
        else if (sum < s)
            left++;
        else
            right--;
    }
    return "NO";
}

vector<int> OPtwoSum(vector<int> &nums, int target)
{
    map<int, int> mpp;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int num = nums[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end())
        {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return {-1, -1};
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
    int s = 0;
    cin >> s;
    vector<int> ans;
    ans = OPtwoSum(arr, s);
    for (int num : ans)
    {
        cout << num << " ";
    }
    
}