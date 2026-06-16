#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>

int sqrtFunction(int x)
{
    if (x < 1)
        return 0;
    return std::sqrt(x);
}

int sqrtLinear(int x)
{
    if (x < 1)
        return 0;

    int ans = 1;
    for (int i = 1; i <= x; i++)
    {
        if (1LL * i * i <= x)
            ans = i;
        else
            break;
    }
    return ans;
}

int sqrtBS(int x)
{
    int low = 0, high = x;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        long long val = mid * mid;
        if (val <= x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
}

int main()
{
    int x;
    std::cin >> x;
    int ans = sqrtBS(x);
    std::cout << ans << std::endl;
}