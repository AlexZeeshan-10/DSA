#include <bits/stdc++.h>
using namespace std;

vector<int> missing(vector<int> &arr1)
{

}

int main()
{
    int s1, s2;
    cin >> s1;
    vector<int> arr1(s1);
    for (int i = 0; i < arr1.size(); i++)
    {
        cin >> arr1[i];
    }

    cin >> s2;
    vector<int> arr2(s2);
    for (int i = 0; i < arr2.size(); i++)
    {
        cin >> arr2[i];
    }

    vector<int> s = missing(arr1);
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " ";
    }
}