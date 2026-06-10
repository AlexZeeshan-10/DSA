#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int search(std::vector<int> arr)
{
    int low = 0, high = arr.size()-1, ans = INT_MAX;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if(arr[low] <= arr[mid]){
            ans = std::min(ans, arr[low]);
            low = mid + 1;
        }
        else {
            ans = std::min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
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
    
    int ans = search(arr);
}