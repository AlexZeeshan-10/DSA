#include <bits/stdc++.h>
using namespace std;

// Find missing numbers
int missing_no(vector<int> &arr1)
{

    // Initialize the vector with zeros and enough size to prevent out-of-bounds access.
    vector<int> hash(arr1.size() + 2, 0);
    for (int i = 0; i < arr1.size(); i++)
    {
        hash[arr1[i]] = 1;
    }
    for (int i = 1; i < hash.size(); i++)
    {
        if (hash[i] == 0)
            return i;
    }
    return -1;
}

// Finding missing numbers optimal approach
int OPmissing_no(vector<int> &arr1)
{
    int n = arr1.size();
    int s1, s2 = 0;
    s1 = n * (n + 1) / 2;
    for (int i = 0; i < n; i++)
    {
        s2 += arr1[i];
    }
    return s1 - s2;
}

// Finding missing numbers optimal approach using XOR method
int XORmissing_no(vector<int> &arr1)
{
    int XOR1 = 0, XOR2 = 0;
    int n = arr1.size();
    for (int i = 0; i < n - 1; i++)
    {
        XOR2 = XOR2 ^ arr1[i];
        XOR1 = XOR1 ^ (i + 1);
    }
    XOR1 = XOR1 ^ n;
    return XOR1 ^ XOR2;
}

// Find maximum consecutive ones that appears in the array
int consecutive_ones(vector<int> &arr1)
{
    int count = 0, ans = 0;
    for (int num : arr1)
    {
        if (num == 1)
            count++;
        else
            count = 0;

        ans = max(ans, count);
    }
    return ans;
}

// Number not occuring twice in the array
int single_num(vector<int> arr1)
{
    map<int, int> mpp;
    for (int i = 0; i < arr1.size(); i++)
    {
        mpp[arr1[i]]++;
    }
    for (auto it : mpp)
    {
        if (it.second == 1)
        {
            return it.first;
        }
    }
    return -1;
}

// Number not occuring twice in the array optimal method
int OPsingle_num(vector<int> arr1)
{
    int XOR = 0;
    for (int num : arr1)
    {
        XOR = XOR ^ num;
    }
    return XOR;
}

int main()
{
    int s1;
    cin >> s1;
    vector<int> arr1(s1);
    for (int i = 0; i < arr1.size(); i++)
    {
        cin >> arr1[i];
    }

    int s = OPsingle_num(arr1);
    cout << s << endl;
}