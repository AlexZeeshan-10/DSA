#include <iostream>
#include <vector>

int findKthNum(std::vector<int> &arr, int k){
    
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

    int ans = findKthNum(arr, k);
    std::cout << ans << std::endl;
}