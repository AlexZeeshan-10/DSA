#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>

int sqrtBS(int x){
    int low = 0, high = x;
    while (low <= high){
        long long mid = low + (high - low) / 2;
        long long val = mid * mid;
        if(val <= x)
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return high;
}

int main(){
    int x;
    std::cin >> x;
    int ans = sqrtBS(x);
}