#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>

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

int main()
{
    int x;
    std::cin >> x;
    int ans = sqrtLinear(x);
}