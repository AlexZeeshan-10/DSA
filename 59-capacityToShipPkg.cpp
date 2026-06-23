#include <iostream>
#include <vector>

// Find the max in the array to provide an initial iteration point
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

// Provides the sum of all elements to define a constraint for iteration
int sumOfArr(std::vector<int> &arr)
{
    int sum = 0;
    for (int it : arr)
    {
        sum += it;
    }
    return sum;
}

// Helps calculating number of days each capacity of the ship would take
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

// Brute approach to find the max capacity of the ship that would help shipping the packages within the given days... It throws a Time Limit Exceeded case in large inputs so it's better to use Binary Search approach
int shipWithinDaysBrute(std::vector<int> &arr, int days)
{
    for (int capacity = findMax(arr); capacity <= sumOfArr(arr); capacity++)
    {
        if (shippingDays(arr, capacity) <= days)
            return capacity;
    }
    return -1;
}

// Binary search approach to find the max capacity of the ship that would help shipping the packages within the given days...
int shipWithinDaysBS(std::vector<int> &arr, int days){
    int low = findMax(arr), high = sumOfArr(arr);
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if(shippingDays(arr, mid) <= days)
            high = mid - 1;
        else 
            low = mid + 1;
        }
    return low;
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
    int ans = shipWithinDaysBS(arr, days);
    std::cout << ans << std::endl;
}