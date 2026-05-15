#include <bits/stdc++.h>
using namespace std;

int countPair(vector<int> &arr)
{
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] > 2 * arr[j])
                ans++;
        }
    }
    return ans;
}

// Main function
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}