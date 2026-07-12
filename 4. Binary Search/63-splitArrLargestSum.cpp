#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

// Helper function: Counts subarrays needed for a given max sum limit.
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

// Brute-force: Linearly checks every possible max sum from low to high.
int splitArrayBrute(std::vector<int> &arr, int k)
{
    if (arr.size() < k)
        return -1;

    int low = *std::max_element(arr.begin(), arr.end());
    int high = std::accumulate(arr.begin(), arr.end(), 0);
    for (int i = low; i <= high; i++)
    {
        int sumNeeded = requiredSubarrays(arr, i);
        if (sumNeeded <= k)
            return i;
    }
    return -1;
}

// Optimal: Uses binary search to find the minimum largest subarray sum.
int splitArrayBS(std::vector<int> &nums, int k)
{
    if (nums.size() < k)
        return -1;

    // The answer must lie between the largest element and the sum of all elements.
    int low = *std::max_element(nums.begin(), nums.end());
    int high = std::accumulate(nums.begin(), nums.end(), 0);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        // If 'mid' is a possible answer, try for an even smaller sum.
        if (requiredSubarrays(nums, mid) <= k)
            high = mid - 1;
        // If 'mid' is too small, we need to allow a larger sum.
        else
            low = mid + 1;
    }
    // 'low' will be the minimum possible largest sum.
    return low;
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