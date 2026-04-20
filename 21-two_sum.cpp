#include<bits/stdc++.h>
using namespace std;

string two_sum(vector<int> &arr, int s){
    int left = 0, right = arr.size()-1;;
    sort(arr.begin(), arr.end());
    while (left<right)
    {
        int sum = arr[left] + arr[right];
        if(sum == s) return "YES";
        else if(sum<s) left++;
        else right--;
    }
    return "NO";
}

int OPtwo_sum(vector<int> &arr, int s){
    
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
    int s = 0;
    cin >> s;
    string ans = two_sum(arr, s);
    cout << ans << " ";
}