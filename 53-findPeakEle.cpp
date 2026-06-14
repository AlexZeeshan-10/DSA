#include <iostream>
#include <vector>
#include <algorithm>

int findPeakElementBrute1(std::vector<int>& arr) {
        
    }

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

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cin >> arr[i];
    }
    int ans = findPeakElementBrute1(arr);
    std::cout << ans << std::endl;
}