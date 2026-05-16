#include <bits/stdc++.h>
using namespace std;

int BS(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1, mid = NULL;
    while (low <= high)
    {
        mid = (low+high) / 2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) low = mid+1;
        else high = mid-1;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }

    int target;
    cin >> target;
    int ans = BS(arr, target);
    cout << ans+1 << " ";
}