#include <iostream>
#include <vector>

int findKthNumBS(std::vector<int> &arr, int k)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int missing = arr[mid] - (mid + 1);
        if (missing < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return arr[high] + k - (arr[high] - high - 1);
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

    int ans = findKthNumBS(arr, k);
    std::cout << ans << std::endl;
}