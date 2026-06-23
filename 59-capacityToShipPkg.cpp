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

int sumOfArr(std::vector<int> &arr)
{
    int sum = 0;
    for (int it : arr)
    {
        sum += it;
    }
    return sum;
}

int shippingDays(std::vector<int> &arr, int capacity)
{
    int days = 1;
    int load = 0;

    for (int weight : arr)
    {
        if (load + weight > capacity)
        {
            days++;
            load = weight;
        }
        else
        {
            load += weight;
        }
    }
    return days;
}

int shipWithinDays(std::vector<int> &arr, int days)
{
    for (int capacity = findMax(arr); capacity <= sumOfArr(arr); capacity++)
    {
        if (shippingDays(arr, capacity) <= days)
            return capacity;
    }
    return -1;
}

int shipWithinDaysBS(std::vector<int> &arr, int days){
    int low = findMax(arr), high = sumOfArr(arr);
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        
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