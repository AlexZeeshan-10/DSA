#include <bits/stdc++.h>
using namespace std;

// brute force method to find missing and repeating number in an array of size n
void missingAndRepeat(vector<int> &arr)
{
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
    missingAndRepeat(arr);
}