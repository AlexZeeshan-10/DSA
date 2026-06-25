#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

// Returns the number of subarrays required if the maximum
// allowed subarray sum is maxAllowedSum.
int requiredSubarrays(std::vector<int> &nums, int maxAllowedSum)
{
    int subarrayCount = 1;
    long long currentSubarraySum = 0;

    for (int num : nums)
    {
        if (currentSubarraySum + num <= maxAllowedSum)
        {
            currentSubarraySum += num;
        }
        else
        {
            subarrayCount++;
            currentSubarraySum = num;
        }
    }

    return subarrayCount;
}

int splitArrayBrute(std::vector<int> &arr, int k) {
        if (arr.size() < k)
            return -1;

        int low = *std::max_element(arr.begin(), arr.end());
        int high = std::accumulate(arr.begin(), arr.end(), 0);
        for (int i = low; i <= high; i++) {
            int sumNeeded = requiredSubarrays(arr, i);
            if (sumNeeded <= k)
                return i;
        }
        return -1;
    }

int splitArrayBS(std::vector<int> &nums, int k)
{
    if (nums.size() < k)
        return -1;

    int low = *std::max_element(nums.begin(), nums.end());
    int high = std::accumulate(nums.begin(), nums.end(), 0);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (requiredSubarrays(nums, mid) <= k)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return high + 1;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);

    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cin >> arr[i];
    }

    int k;
    std::cin >> k;
    int ans = splitArrayBS(arr, k);
    std::cout << ans << std::endl;
}