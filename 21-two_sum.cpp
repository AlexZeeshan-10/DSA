#include <bits/stdc++.h>
using namespace std;

//two sum returning string in the main function
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

//optimised version of two sum
vector<int> OPtwoSum(vector<int> &nums, int target)
{
    // This map will act as our memory. 
    // It stores previously seen numbers as 'keys', and their array indices as 'values'.
    map<int, int> mpp;
    int n = nums.size();

    // We iterate through the array one element at a time.
    for (int i = 0; i < n; i++)
    {
        // 'num' is the current array element we are looking at.
        int num = nums[i];

        // 'moreNeeded' is the exact number required to reach the target sum.
        int moreNeeded = target - num;

        // We check our 'memory' (the map) to see if we have already encountered 'moreNeeded'
        // during a previous loop iteration.
        if (mpp.find(moreNeeded) != mpp.end())
        {
            // If we found it, success! The current 'num' and previously seen 'moreNeeded' add up to the target.
            // mpp[moreNeeded] gives us the index of the previously seen number.
            // i is the index of our current number.
            return {mpp[moreNeeded], i};
        }
        // If we didn't find 'moreNeeded' in the map, we save the current 'num' and its index 'i' 
        // into the map. This way, future elements in the loop can check back and use this number!
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