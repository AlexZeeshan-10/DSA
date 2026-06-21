#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>

// To find max in the array
int findMax(std::vector<int> &arr){
    int maxi = INT_MIN;
    for(auto it:arr){
        maxi = std::max(maxi, it);
    }
    return maxi;
}

// To perform the division and return the summation
int checkDivisor(std::vector<int> &arr, int i){
    int count = 0;
    for(auto it:arr){
        count += std::ceil((double)it / double(i));
    }
    return count;
}

// Main function to determine the smallest divisor in the array 
int smallestDivisorBrute(std::vector<int> &arr, int t){
    for(size_t i = 1; i < findMax(arr); ++i){
        if(checkDivisor(arr, i) <= t) 
          return i;
    }
    return -1;
}

int smallestDivisorBS(std::vector<int> &arr, int t){
    int low = 1, high = findMax(arr);
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(checkDivisor(arr, mid) <= t)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}


int main(){
  int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (size_t i = 0; i < arr.size(); ++i)
    {
        std::cin >> arr[i];
    }
    int threshold;
    std::cin >> threshold;
    int ans = smallestDivisorBS(arr, threshold);
    std::cout << ans << std::endl;
}