#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

int findMax(std::vector<int> &arr){
  int maxi = INT_MAX;
  for(auto it : arr){
    maxi = std::max(maxi, it);
  }
  return maxi;
}

int calculateTotalHours(std::vector<int> &arr, int hourly){
  int totalH = 0;
  for(size_t i = 0; i < arr.size(); ++i){
    totalH += std::ceil((double) arr[i] / (double) hourly);
  }
  return totalH;
}

int kokoEatBanana(std::vector<int> &arr, int deadLine){
  int low = 1, high = findMax(arr);
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    int totatH = calculateTotalHours(arr, mid);
    if (totatH <= deadLine)
    {
      high = mid - 1;
    }
    else 
      low = mid + 1;
  }
  return low;
}

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
  int ans = kokoEatBanana(arr, deadLine);
  std::cout << ans << std::endl;
}