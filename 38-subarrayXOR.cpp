#include <bits/stdc++.h>
using namespace std;

int subXORbtr(vector<int> &arr, int k)
{
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int XOR = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            XOR = XOR ^ arr[j];
            if (XOR == k)
            {
                count++;
            }
        }
    }
    return count;
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

    int ans = subXORbtr(arr, k);
    cout << ans << " ";
}