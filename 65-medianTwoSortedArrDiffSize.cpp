#include <iostream>
#include <vector>

double medianBrute(std::vector<int> &arr1, std::vector<int> &arr2){
    int i = 0, j = 0;
    std::vector<int> ans;
    while (i < arr1.size() && j < arr2.size())
    {
        (arr1[i] < arr2[j]) ? ans.push_back(arr1[i++]) : ans.push_back(arr2[j++]);
    }
    while (i < arr1.size())
    {
        ans.push_back(arr1[i++]);
    }
    while (j < arr2.size())
    {
        ans.push_back(arr2[j++]);
    }
    int n = (arr1.size() + arr2.size());
    return (n%2 == 1) ? ans[n / 2] : (double)((double) (ans[n/2]) + (double) (ans[n/2 - 1])) / 2.0;
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
    
    double ans = medianBrute(arr1, arr2);
    std::cout << ans << std::endl;
}