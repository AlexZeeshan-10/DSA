#include <bits/stdc++.h>
using namespace std;

int longest_subarray(vector<int> &arr, int k)
{
}

int main()
{
    int n, k;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }

    cin >> k;
    int s = longest_subarray(arr, k);
    cout << s << " ";
}