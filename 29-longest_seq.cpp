#include <bits/stdc++.h>
using namespace std;

// linear search algo
bool linearSearch(vector<int> arr, int n)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == n)
            return true;
    }
    return false;
}

// Brute force approach using linear search (O(N^2) or O(N^3))
int longestSuccessiveElements_BruteForce(vector<int> &arr)
{
    if (arr.empty())
        return 0;
    int longest = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        int x = arr[i];
        int cnt = 1;
        // This is where linear search is used to find the next element in the sequence
        while (linearSearch(arr, x + 1))
        {
            x += 1;
            cnt += 1;
        }
        longest = max(longest, cnt);
    }
    return longest;
}

// Optimal approach for longest sequence in an array
int longestSuccessiveElement_better(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int longest = 1, count = 0, Lsmall = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] - 1 == Lsmall)
        {
            count += 1;
            Lsmall = arr[i];
        }
        else if (arr[i] != Lsmall)
        {
            count = 1;
            Lsmall = arr[i];
        }
        longest = max(longest, count);
    }
    return longest;
}

int longestSuccessiveElement_Optimal(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return 0;
    int longest = 1;
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }
    for (int it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                {
                    x = x + 1;
                    cnt = cnt + 1;
                }
                longest = max(longest, cnt);
            }
        }
    }
    return longest;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }

    // Output the result
    cout << longestSuccessiveElement_Optimal(arr) << endl;
    return 0;
}