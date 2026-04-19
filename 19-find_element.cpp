#include <bits/stdc++.h>
using namespace std;

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
        if(hash[i] == 0) return i;
    }
    return -1;
}

int OPmissing_no(vector<int> arr1){
    int n = arr1.size();
    int s1, s2 = 0;
    s1 = n * (n+1) / 2;
    for (int i = 0; i < n; i++)
    {
        s2 += arr1[i];
    }
    return s1-s2;
}

int main()
{
    int s1;
    int s2;
    cin >> s1;
    vector<int> arr1(s1);
    for (int i = 0; i < arr1.size(); i++)
    {
        cin >> arr1[i];
    }

    // cin >> s2;
    // vector<int> arr2(s2);
    // for (int i = 0; i < arr2.size(); i++)
    // {
    //     cin >> arr2[i];
    // }

    int s = OPmissing_no(arr1);
    cout << s << endl;
}