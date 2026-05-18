#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &arr, int target){
    
}


int main(){
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    int ans = lowerBound(arr, target);
    cout << ans << " ";
}