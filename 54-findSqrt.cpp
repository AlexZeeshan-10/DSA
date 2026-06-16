#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>

int sqrtFunction(int x){
    if(x<1) return 0;
    return std::sqrt(x);
}

int main(){
    int x;
    std::cin >> x;
    int ans = sqrtBS(x);
}