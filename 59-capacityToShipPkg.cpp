#include <iostream>
#include <vector>

int shipWithinDays(std::vector<int> &arr, int days){
    
}

int main(){
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