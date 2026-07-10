#include <iostream>
#include <vector>
#include <cmath>



long double minimizeMaxDistanceBS(std::vector<int> &arr, int k){
    
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