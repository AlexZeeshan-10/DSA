#include <iostream>
#include <algorithm>

long long mul(int i, int n, int m)
{
    long long ans = 1;
    for (int j = 1; j <= n; j++)
    {
        ans *= i;
        if (ans > m) return ans; // Break early to prevent integer overflow
    }
    return ans;
}

int rootBrute(int m, int n)
{
    for (int i = 1; i <= m; i++)
    {
        long long val = mul(i, n, m);
        if (val == m)
            return i;
        else if (val > m)
            break;
    }
    return -1;
}

int main()
{
    int m, n;
    std::cin >> m;
    std::cin >> n;
    int ans = rootBrute(m, n);
    std::cout << ans;
}