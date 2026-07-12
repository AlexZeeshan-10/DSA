#include <iostream>
#include <vector>
#include <climits>

double medianBrute(std::vector<int> &arr1, std::vector<int> &arr2)
{
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
    return (n % 2 == 1) ? ans[n / 2] : (double)((double)(ans[n / 2]) + (double)(ans[n / 2 - 1])) / 2.0;
}

// Better brute-force approach using O(1) space
double medianBetter(std::vector<int> &arr1, std::vector<int> &arr2)
{
    int n1 = arr1.size(), n2 = arr2.size();
    int n = n1 + n2;
    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int cnt = 0;
    int el1 = -1, el2 = -1;

    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        int current_el;
        if (arr1[i] < arr2[j]) {
            current_el = arr1[i++];
        } else {
            current_el = arr2[j++];
        }
        if (cnt == ind1)
            el1 = current_el;
        if (cnt == ind2)
            el2 = current_el;
        cnt++;
    }
    // If arr2 is exhausted, continue with arr1
    while (i < n1)
    {
        int current_el = arr1[i++];
        if (cnt == ind1) el1 = current_el;
        if (cnt == ind2) el2 = current_el;
        cnt++;
    }
    // If arr1 is exhausted, continue with arr2
    while (j < n2)
    {
        int current_el = arr2[j++];
        if (cnt == ind1) el1 = current_el;
        if (cnt == ind2) el2 = current_el;
        cnt++;
    }

    if (n % 2 == 1)
        return el2;
    return (double)(el1 + el2) / 2.0;
}

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
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        r1 = (mid1 < arr1.size()) ? arr1[mid1] : r1;
        r2 = (mid2 < arr2.size()) ? arr2[mid2] : r2;
        l1 = (mid1 - 1 >= 0) ? arr1[mid1 - 1] : l1;
        l2 = (mid2 - 1 >= 0) ? arr2[mid2 - 1] : l2;
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