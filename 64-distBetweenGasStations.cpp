#include <iostream>
#include <vector>
#include <cmath>

int numberOfGasStationsRequired(long double dist, std::vector<int> &arr){
    int cnt = 0;
    for (size_t i = 1; i < arr.size(); i++)
    {
        int numberInBetween = (arr[i] - arr[i - 1] / dist);
        cnt += floor((arr[i] - arr[i-1]) / dist);
    }
    return cnt;
}

long double minimizeMaxDistanceBS(std::vector<int> &arr, int k){
    long double low = 0, high = 0;
    for (size_t i = 0; i < arr.size()-1; i++)
    {
        high = max(high,(long double)(arr[i+1] - arr[i]));
    }
    
    long double diff = 1e - 6;
    while (high - low > diff)
    {
        long double mid = (low + (high - low)) / (2.0);
        int cnt = numberOfGasStationsRequired(mid, arr);
        (cnt > k) ? low = mid : high = mid;
    }
    return high;
}

int main(){
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cin >> arr[i];
    }
    
    int k;
    std::cin >> k;

    int ans = minimizeMaxDistanceBS(arr, k);
    std::cout << ans << std::endl;
}