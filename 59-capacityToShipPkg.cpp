#include <iostream>
#include <vector>

int findMax(std::vector<int> &arr)
{
    int maxi = 0;
    for (int it : arr)
    {
        if (it > maxi)
            maxi = it;
    }
    return maxi;
}

int sumOfArr(std::vector<int> &arr){
    int sum = 0;
    for(int it:arr){
        sum += it;
    }
    return sum;
}

int shipWithinDays(std::vector<int> &arr, int days)
{
    for (int i = findMax(arr); i < sumOfArr(arr); i++)
    {
        if (shippingDays(arr, i) <= days)
            return i;
    }
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (size_t i = 0; i < arr.size(); ++i)
    {
        std::cin >> arr[i];
    }
    int days;
    std::cin >> days;
    int ans = shipWithinDays(arr, days);
    std::cout << ans << std::endl;
}