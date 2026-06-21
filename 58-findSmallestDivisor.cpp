#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>



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