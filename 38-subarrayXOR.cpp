#include <bits/stdc++.h>
using namespace std;

int subXORbtr(vector<int> &arr, int k)
{
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int XOR = 0;
        for (int j = i; j < arr.size(); j++)
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

int subXORopt(vector<int> &arr, int k)
{
}

int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    vector<int> arr(n, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }

    int ans = subXORopt(arr, k);
    cout << ans << " ";
}