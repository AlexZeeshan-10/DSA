#include <iostream>
#include <vector>
#include <climits>

int timesArrRot(std::vector<int> &arr)
{
    int low = 0, high = arr.size() - 1, ans = INT_MAX, index = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[low] <= arr[high])
        {
            if (arr[low] < ans){
                index = low;
                ans = arr[low];
            }
            break;
        }
        if (arr[low] <= arr[mid])
        {
            if (arr[low] < ans){
                index = low;
                ans = arr[low];
            }
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
            if (arr[mid] < ans){
                index = mid;
                ans = arr[mid];
            }
        }
    }
    return index;
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
    int ans = timesArrRot(arr);
    std::cout << ans;
}