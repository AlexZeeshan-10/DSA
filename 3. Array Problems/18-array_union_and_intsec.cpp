#include <bits/stdc++.h>
using namespace std;

void left_rotate(vector<int> &arr, int count)
{
    if (arr.empty())
        return;
    count %= arr.size();
    // while(count--){
    // int temp = arr[0];
    // for (int i = 1; i < arr.size(); i++)
    // {
    //     arr[i-1] = arr[i];
    // }
    // arr[arr.size() - 1] = temp;
    // }
    reverse(arr.begin(), arr.begin() + count);
    reverse(arr.begin() + count, arr.end());
    reverse(arr.begin(), arr.end());
}
// Move zeros to end
void move_zero(vector<int> &arr)
{
    if (arr.empty())
        return;
    int j = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

// linear search
vector<int> Linear_Search(vector<int> &arr, int n)
{
    vector<int> temp;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == n)
        {
            temp.push_back(i); // Save the index where the element was found
        }
    }
    return temp;
}

// Leetcode version of linear serach
int searchInsert(vector<int> &nums, int target)
{
    if (nums.empty())
        return 0; // The index to insert in an empty array is 0

    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] >= target)
            return i;
    }
    return n;
}

// Finding union of two sorted arrays
vector<int> union_array(vector<int> arr1, vector<int> arr2)
{
    set<int> st;
    for (int i = 0; i < arr1.size(); i++)
    {
        st.insert(arr1[i]);
    }
    for (int i = 0; i < arr2.size(); i++)
    {
        st.insert(arr2[i]);
    }
    vector<int> temp;
    for (auto it : st)
    {
        temp.push_back(it);
    }
    return temp;
}

// Union of two sorted arrays (Optimised approach)
vector<int> union_arr(vector<int> arr1, vector<int> arr2)
{
    int i = 0, j = 0;
    vector<int> unionArr;
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] <= arr2[j])
        {
            if (unionArr.empty() || arr1[i] != unionArr.back())
            {
                unionArr.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if (unionArr.empty() || arr2[j] != unionArr.back())
            {
                unionArr.push_back(arr2[j]);
            }
            j++;
        }
    }

    while (i < arr1.size())
    {
        if (unionArr.empty() || arr1[i] != unionArr.back())
        {
            unionArr.push_back(arr1[i]);
        }
        i++;
    }

    while (j < arr2.size())
    {
        if (unionArr.empty() || arr2[j] != unionArr.back())
        {
            unionArr.push_back(arr2[j]);
        }
        j++;
    }

    return unionArr;
}

//intersection of two sorted arrays
vector<int> intersection(vector<int> arr1, vector<int> arr2){
    int a = arr1.size(), b = arr2.size();
    vector<int> vis(b);
    vector<int> temp;
    for(int i=0; i<a; i++){
         for(int j=0; j<b; j++){
            if(arr2[j] > arr1[i]) break; // Since sorted, we won't find arr1[i] anymore
            
            if(arr1[i] == arr2[j] && vis[j] == 0){
                temp.push_back(arr1[i]);
                vis[j] = 1;
                break; // Stop searching once we've found and logged a match
            }
        }
    }
    return temp;   
}

//Optimal approach of intersection of two sorted arrays
vector<int> opt_intersection(vector<int> arr1, vector<int> arr2){
    int i=0, j=0;
    vector<int> temp;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i] == arr2[j]){
            temp.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j]) i++;
        else j++;
    }
    return temp;
}

int main()
{
    int s1, s2;
    cin >> s1;
    vector<int> arr1(s1);
    for (int i = 0; i < arr1.size(); i++)
    {
        cin >> arr1[i];
    }

    cin >> s2;
    vector<int> arr2(s2);
    for (int i = 0; i < arr2.size(); i++)
    {
        cin >> arr2[i];
    }

    vector<int> s = opt_intersection(arr1, arr2);

    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " ";
    }
}