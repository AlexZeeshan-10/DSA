#include <bits/stdc++.h>
using namespace std;

void mergeSortArray(vector<int> &arr1, vector<int> &arr2)
{
}

int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    vector<int> arr1(n);
    vector<int> arr2(m);
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    mergeSortArray(arr1, arr2);
    
    for(int it : arr1){
        cout << it << " ";
    }
    for(int it : arr2){
        cout << it << " ";
    }
}