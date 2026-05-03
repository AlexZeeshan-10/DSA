#include<bits/stdc++.h>
using namespace std;


//writing code for better solution to determine major element in an array using list and map data structure
vector<int> majorElementbtr(vector<int> &arr){
    vector<int> ls;
    map<int, int> mpp;
    int n = arr.size();
    int mini = (int)(n/3) + 1;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
        if (mpp[arr[i]] == mini) {
            ls.push_back(arr[i]);
        }
        if(ls.size() == 2) break;
    }
    sort(ls.begin(), ls.end());
    return ls;
}


int main(){
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
    
    vector<int> ans = majorElementbtr(arr);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    
}