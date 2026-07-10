#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> // Required for std::max

// Helper function: How many new gas stations are needed for a given max distance 'dist'?
int numberOfGasStationsRequired(long double dist, std::vector<int> &arr){
    int cnt = 0;
    for (size_t i = 1; i < arr.size(); i++)
    {
        // Calculate how many stations can fit in the current section.
        double stationsInBetween = ((double)arr[i] - (double)arr[i-1]) / dist;
        cnt += stationsInBetween;
    }
    return cnt;
}

// Optimal: Finds the minimum maximized distance using Binary Search on the answer.
long double minimizeMaxDistanceBS(std::vector<int> &arr, int k){
    long double low = 0, high = 0;
    // The search space for the answer is from 0 to the largest existing gap.
    for (size_t i = 0; i < arr.size()-1; i++)
    {
        high = std::max(high,(long double)(arr[i+1] - arr[i]));
    }
    
    // We use a small difference for precision in our binary search with doubles.
    long double diff = 1e-6;
    while (high - low > diff)
    {
        long double mid = low + (high - low) / 2.0;
        int cnt = numberOfGasStationsRequired(mid, arr);
        // If we need more stations than we have, 'mid' is too small. Increase the distance.
        (cnt > k) ? low = mid : high = mid;
    }
    // 'high' (or 'low') will hold the minimized maximum distance.
    return high;
}

int main(){
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    // Corrected loop condition
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    
    int k;
    std::cin >> k;

    // The answer is a double, not an integer.
    long double ans = minimizeMaxDistanceBS(arr, k);
    std::cout << ans << std::endl;
}