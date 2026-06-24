#include <iostream>
#include <vector>

int maxDistanceBrute(std::vector<int> &arr, int cows){
    
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cin >> arr[i];
    }
    
    int cows;
    std::cin >> cows;
    int ans = maxDistanceBrute(arr, cows);
    std::cout << ans << std::endl;
}