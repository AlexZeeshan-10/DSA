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



// Main function to determine the smallest divisor in the array
int smallestDivisor(std::vector<int> &arr, int t){
    for(size_t i = 1; i < findMax(arr); ++i){
        if(checkDivisor(arr, i) < t) 
          return i;
    }
    return -1;
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
    int ans = smallestDivisor(arr, threshold);
    std::cout << ans << std::endl;
}