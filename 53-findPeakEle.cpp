#include <iostream>
#include <vector>
#include <algorithm>

// time complexity O(2n) ~ O(n) But this code is more readable and easy
int findPeakElementBrute1(std::vector<int> &arr)
{
    int maxi = arr[0];
    for (int i = 0; i < arr.size(); i++)
    {
        maxi = std::max(maxi, arr[i]);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == maxi)
            return i;
    }
    return -1;
}

// Less time complexity but the readablity is complex
int findPeakElementBrute2(std::vector<int> &arr)
{
    int n = arr.size();
    /* This solution would require just one iteration.
        The readability gets quite complex. */
    for (size_t i = 0; i < arr.size(); i++)
    {
        if ((i == 0 || arr[i - 1] < arr[i]) &&
            ((i == n - 1) || arr[i] > arr[i + 1]))
            return i;
    }
    return -1;
}

int findPeakElementOptimal(std::vector<int> &arr)
{
    if (arr[0] > arr[1])
        return 0;
    if (arr[arr.size() - 1] > arr[arr.size() - 2])
        return arr.size() - 1;
    int low = 1, high = arr.size() - 2;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            return mid;
        else if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return -1;
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
    int ans = findPeakElementOptimal(arr);
    std::cout << ans << std::endl;
}