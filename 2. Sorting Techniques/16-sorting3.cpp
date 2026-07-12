#include <bits/stdc++.h>
using namespace std;

// QUICK SORT ALGORITHM
int pivot(vector<int> &arr, int l, int h){
     int pivot = arr[l];
     int i = l;
     int j = h;
     while (i < j)
     {
        while (arr[i] <= pivot && i <= h-1){
            i++;
        }
        while (arr[j] > pivot && j >= l+1){
            j--;
        }
        if(i<j) swap(arr[i], arr[j]);
     }
     swap(arr[l], arr[j]);
     return j;
}

void quick_sort(vector<int> &arr, int l, int h){
    if(l < h){
    int part = pivot(arr, l, h);
    quick_sort(arr, l, part-1);
    quick_sort(arr, part+1, h);
    }
}
 

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int low = 0, high = n-1;
    //function call
    quick_sort(arr, low, high);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}