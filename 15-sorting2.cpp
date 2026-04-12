#include <bits/stdc++.h>
using namespace std;

//MERGE SORT ALGORITHM

void merge(vector<int> &arr, int l, int mid, int h){
    vector<int> temp;
    int left = l, right = mid+1;
    while(left<=mid && right<=h){
        if(arr[left]<arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    
    while (h>=right){
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = l; i <= h; i++)
    {
        arr[i] = temp[i - l];
    }
    
}

void merge_sort(vector<int> &arr, int l, int h){
    if(l >= h) return;
    int mid = l + (h - l) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid+1, h);
    merge(arr, l, mid, h);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int low = 0, high = n-1;
    merge_sort(arr, low, high);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}