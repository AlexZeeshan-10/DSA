#include <iostream>
#include <vector>

int bruteFindEle(std::vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return arr[0];
    if (arr[0] != arr[1])
        return arr[0];
    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];
    for (size_t i = 1; i < n - 1; i++)
    {
        if (arr[i - 1] != arr[i] && arr[i + 1] != arr[i])
            return arr[i];
    }
    return -1;
}

int optFindEle(std::vector<int> &arr){
    
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
    int ans = bruteFindEle(arr);
    std::cout << ans;
}