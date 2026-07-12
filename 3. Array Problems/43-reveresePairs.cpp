#include <iostream>
#include <vector>
using namespace std;

// Brute method not recommended for large inputs
int countPair(vector<int> &arr)
{
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] > 2 * arr[j])
                ans++;
        }
    }
    return ans;
}

//Optimal approach requires merge alorithm Optimal code starts from here...
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
int countPairOpt(vector<int> &arr, int low, int mid, int high){
    int right = mid+1;
    int cnt = 0;
    for (int i = low; i < mid+1; i++)
    {
        while(right <= high && arr[i] > 2*arr[right]) right++;
        cnt += (right -(mid + 1));
    }
    return cnt;
}

int merge_sort(vector<int> &arr, int l, int h){
    int cnt = 0;
    if(l >= h) return cnt;
    int mid = l + (h - l) / 2;
    cnt += merge_sort(arr, l, mid);
    cnt += merge_sort(arr, mid+1, h);
    cnt += countPairOpt(arr, l, mid, h);
    merge(arr, l, mid, h);
    return cnt;
}

int team(vector<int> &arr,int n){
   return merge_sort(arr, 0, n-1);
}

// Main function
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
    int ans = team(arr, n);
}