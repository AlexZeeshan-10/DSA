#include <iostream>
#include <vector>
#include <climits>

double medianBS(std::vector<int> &arr1, std::vector<int> &arr2)
{
    if (arr1.size() > arr2.size())
        return medianBS(arr2, arr1);
    int low = 0, high = arr1.size();
    int left = (arr1.size() + arr2.size() + 1) / 2;
    int n = arr1.size() + arr2.size();
    while (low <= high)
    {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        int l1 = INT_MAX, l2 = INT_MAX;
        int r1 = INT_MAX, r2 = INT_MAX;
        r1 = (mid1 < arr1.size()) ? arr1[mid1] : r1;
        r2 = (mid2 < arr2.size()) ? arr2[mid2] : r1;
        l1 = (mid1 - 1 >= 0) ? arr1[mid1 - 1] : l1;
        l2 = (mid2 - 1 >= 0) ? arr2[mid2 - 1] : l1;
        if (l1 <= r2 && l2 <= r1)
        {
            if (n % 2 == 1)
                return std::max(l1, l2);
            return ((double)(std::max(l1, l2) + std::min(r1, r2))) / 2.0;
        }
        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return 0;
}

int main()
{
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

    double ans = medianBS(arr1, arr2);
    std::cout << ans << std::endl;
}