#include<bits/stdc++.h>
using namespace std;

int merge_sort(vector<int>& arr,int l,int h){
    
}

int inversionCount(vector<int>& arr) {
    return merge_sort(arr,0,arr.size()-1);
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    int ans = inversionCount(arr);
}