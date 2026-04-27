#include<bits/stdc++.h>
using namespace std;

// Brute-force approach
vector<int> lead(vector<int> &arr){
    vector<int> temp;
    for (int i = 0; i < arr.size(); i++)
    {   bool lead = true;
        for (int j = i+1; j < arr.size(); j++)
        {
            if(arr[i] < arr[j]) {
            lead = false;
            break;
            }
        }
        if(lead == true){
            temp.push_back(arr[i]);
        }
    }
    return temp;
}

// Optimal O(N) Approach
vector<int> optimalLead(vector<int> &arr){
    vector<int> ans;
    if(arr.empty()) return ans;
    
    int maxi = arr[arr.size() - 1];
    ans.push_back(maxi); // The rightmost element is always a leader
    
    for (int i = arr.size() - 2; i >= 0; i--) {
        if (arr[i] >= maxi) {
            ans.push_back(arr[i]);
            maxi = arr[i];
        }
    }
    
    reverse(ans.begin(), ans.end()); // Reverse to maintain the original relative order
    return ans;
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
    ans = optimalLead(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    
}