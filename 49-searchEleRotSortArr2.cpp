#include <iostream>
#include <vector>

int searchRotatedArray(std::vector<int> &arr, int target)
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
    int target;
    std::cin >> target;
    bool ans = searchRotArr(arr, target);
}