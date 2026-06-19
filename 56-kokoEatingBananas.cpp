#include <iostream>
#include <vector>

int main(){
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (size_t i = 0; i++ < arr.size();)
    {
        std::cin >> arr[i];
    }
    int deadLine;
    std::cin >> deadLine;
    int ans(arr, deadLine);
    std::cout << ans << std::endl;
}