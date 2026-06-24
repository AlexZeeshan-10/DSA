#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

bool canWePlace(std::vector<int> &arr, int distance, int cows)
{
    int cntCows = 1, last = arr[0];
    for (size_t i = 1; i < arr.size(); i++)
    {
        if (arr[i] - last >= distance)
        {
            cntCows++;
            last = arr[i];
        }
    }
    if (cntCows >= cows)
        return true;
    else
        return false;
}

int maxDistanceBrute(std::vector<int> &arr, int cows)
{
    std::sort(arr.begin(), arr.end());
    for (int i = 1; i < std::pow(10, 9); i++)
    {
        if (canWePlace(arr, i, cows) == true)
            continue;
        else
            return (i - 1);
    }
    return -1;
}

int maxDistanceBS(std::vector<int> &arr, int cows)
{
    std::sort(arr.begin(), arr.end());
    int low = 0, high = arr[arr.size() - 1] - arr[0];
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (canWePlace(arr, mid, cows) == true)
            low = mid + 2;
        else
            high = mid - 1;
    }
    return high;
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

    int cows;
    std::cin >> cows;
    int ans = maxDistanceBrute(arr, cows);
    std::cout << ans << std::endl;
}