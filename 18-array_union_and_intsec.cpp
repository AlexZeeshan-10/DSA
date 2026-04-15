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

// Finding union and intersection of two sorted arrays
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
    vector<int> temp(st.size());
    for (auto it : st)
    {
        temp.push_back(it);
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

    vector<int> s = union_array(arr1, arr2);

    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " ";
    }
}