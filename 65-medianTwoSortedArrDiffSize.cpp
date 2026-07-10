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

// Better brute-force approach using O(1) space
double medianBetter(std::vector<int> &arr1, std::vector<int> &arr2){
    int n1 = arr1.size(), n2 = arr2.size();
    int n = n1 + n2;
    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int cnt = 0;
    int el1 = -1, el2 = -1;

    int i = 0, j = 0;
    while(i < n1 && j < n2){
        int current_el = (arr1[i] < arr2[j]) ? arr1[i++] : arr2[j++];
        if(cnt == ind1) el1 = current_el;
        if(cnt == ind2) el2 = current_el;
        cnt++;
    }
    while(i < n1) { /* handle remaining elements */ }
    while(j < n2) { /* handle remaining elements */ }

    if(n % 2 == 1) return el2;
    return (double)(el1 + el2) / 2.0;
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