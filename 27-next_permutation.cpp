#include<bits/stdc++.h>
using namespace std;


//next permutation
vector<int> nextPermutation(vector<int> &arr){
    int ind = -1;
    int n = arr.size();
    for (int i = n-2; i >= 0; i--)
    {
        if(arr[i] < arr[i+1]){
            ind = i;
            break;
        }
    }
    if(ind == -1){
        reverse(arr.begin(), arr.end());
        return arr;
    }
    for (int i = n-1; i > ind ; i--)
    {
        if(arr[i]>arr[ind]){
            swap(arr[i], arr[ind]);
        }
    }
    return arr;
}


int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
    vector <int> ans;
    ans = nextPermutation(arr);
    for (int it : ans)
    {
        cout << it << " ";
    }
    
}