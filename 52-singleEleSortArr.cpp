#include <iostream>
#include <vector>

int bruteFindEle(std::vector<int> &arr){
    int n = arr.size();
    
        return -1;
}

int main(){
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cin >> arr[i];
    }
    int ans = bruteFindEle(arr);
    std::cout << ans;
}