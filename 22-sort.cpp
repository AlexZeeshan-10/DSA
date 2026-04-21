#include <bits/stdc++.h>
using namespace std;

// sort 0s, 1s and 2s normal approach
vector<int> sort(vector<int> &arr)
{
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
            cnt0++;
        if (arr[i] == 1)
            cnt1++;
        if (arr[i] == 2)
            cnt2++;
    }
    for (int i = 0; i < cnt0; i++)
    {
        arr[i] = 0;
    }
    for (int i = cnt0; i < cnt0 + cnt1; i++)
    {
        arr[i] = 1;
    }
    for (int i = cnt0 + cnt1; i < cnt0 + cnt1 + cnt2; i++)
    {
        arr[i] = 2;
    }

    return arr;
}

// sort 0s, 1s and 2s optimal approach
vector<int> OPsort(vector<int> &arr)
{
    int low = 0, mid = 0, high = arr.size() - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    return arr;
}

//main function
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }


    vector<int> ans;
    ans = OPsort(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}