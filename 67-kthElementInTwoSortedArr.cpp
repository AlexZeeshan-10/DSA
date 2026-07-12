#include <iostream>
#include <vector>

int kthElement(std::vector<int> &arr1, std::vector<int> &arr2, int k){
    
}

int main(){
    int n1;
    std::cin >> n1;
    std::vector<int> arr1(n1);
    for (size_t i = 0; i < n1; i++)
    {
        std::cin >> arr1[i];
    }

    int n2;
    std::cin >> n2;

    std::vector<int> arr2(n2);
    for (size_t i = 0; i < n2; i++)
    {
        std::cin >> arr2[i];
    }
    
    int k;
    std::cin >> k;

    int ans = kthElement(arr1, arr2, k);
    std::cout << ans << std::endl;
}