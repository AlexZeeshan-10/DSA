#include <bits/stdc++.h>
using namespace std;

// counting majority element in an array
int major_ele(vector<int> &arr)
{
    map<int, int> mpp;

    // occupies more lines of code
    /*int maxi = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        mpp[arr[i]]++;
    }
    for(auto it : mpp){
        maxi = max(maxi, it.second);
    }
    for (auto i=mpp.begin(); i != mpp.end(); i++)
    {
        if(i -> second==maxi){
            return i->first;
        }
    } */

    // occupies less lines and easy to understand
    for (auto x : arr)
        mpp[x]++;

    int maxi = 0, ans = 0;
    for (auto it : mpp)
    {
        if (maxi < it.second)
        {
            maxi = it.second;
            ans = it.first;
        }
    }
    return ans;
}

// Moore's Voting algorithm for Majority element
int moore_algo(vector<int> &arr)
{
    int ele = 0, count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (count == 0)
        {
            ele = arr[i];
            count++;
        }
        else if (count > 0 && arr[i] != ele)
        {
            count--;
        }
        else
        {
            count++;
        }
    }
    int count1 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == ele)
            count1++;
    }
    if (count1 > (arr.size() / 2))
        return ele;
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
    int x = moore_algo(arr);
    cout << x;
}