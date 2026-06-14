#include <iostream>
#include <vector>

int findPeakElement(std::vector<int> &arr)
{
    
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
    int ans = findPeakElement(arr);
    std::cout << ans << std::endl;
}