#include <bits/stdc++.h>
using namespace std;

void mergeSortArray(vector<int> &arr1, vector<int> &arr2)
{
    
    int left = arr1.size() - 1, right = 0;
    while(left > -1 && right < arr2.size()){
        if(arr1[left] > arr2[right]) {
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }
        else break;
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
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