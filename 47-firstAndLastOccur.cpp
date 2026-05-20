#include<bits/stdc++.h>
using namespace std;

//brute force method to find the first and last occurence in an array
vector<int> occurBrute(vector<int> &arr, int target){
    int i = -1, j = -1;
    for (int x = 0; x < arr.size(); x++)
    {
        if(arr[x] == target){
            if(i == -1) i = x;
            j = x;
        }
    }
    return {i, j};
}


// Lower bound method
int lowerBound(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;
    int ans = arr.size() + 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

// upper bound
int upperBound(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;
    int ans = arr.size() + 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

vector<int> occurOptimal(vector<int> &arr, int target){
    int lb = lowerBound(arr, target);
    if(lb == arr.size() || arr[lb] != target) return {-1, -1};
    return {lb, upperBound(arr, target) - 1};
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    vector<int> ans = occurOptimal(arr, target);
    for(auto it : ans){
        cout << it << " ";
    }
}
