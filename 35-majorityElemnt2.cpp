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

//Majority element in an array optimal solution Moore's algo for two major elements in an array
vector<int> majorElementOpt(vector<int> &arr){
    int count1 = 0, count2 = 0;
    int ele1 = INT_MIN, ele2 = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if(count1 == 0 && ele2 != arr[i]){
            count1 = 1;
            ele1 = arr[i];
        }
        else if(count2 == 0 && ele2 != arr[i]){
            count2 = 1;
            ele2 = arr[i];
        }
        else if (arr[i] == ele1) count1++;
        else if (arr[i] == ele2) count2++;
        else{
            count1--;
            count2--;
        }
    }
    vector<int> ls;
    count1 = 0, count2 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if(ele1 == arr[i]) count1++;
        if(ele2 == arr[i]) count2++;
    }
    int mini = (int)(arr.size()/3) + 1;
    if(count1 >= mini) ls.push_back(ele1);
    if(count2 >= mini) ls.push_back(ele2);
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
    
    vector<int> ans = majorElementOpt(arr);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    
}