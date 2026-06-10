#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int search(std::vector<int> arr, int target)
{
    int low = 0, high = arr.size()-1, ans = INT_MAX;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if(arr[low] <= arr[mid]){
            ans = std::min(ans, arr[low]);
            low += 1;
        }
        else {
            
        }
    }
    
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
    int target;
    std::cin >> target;
    int ans = search(arr, target);
}