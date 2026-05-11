#include <bits/stdc++.h>
using namespace std;

/*

Input to be used to check the functionality of the program
5
1 2 2 4 5

*/
// brute force method to find missing and repeating number in an array of size n
void missingAndRepeatBrute(vector<int> &arr)
{
    int repeat = -1;
    int missing = -1;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int count = 0;
        for (int j = 0; j < arr.size() - 1; j++)
        {
            if (arr[j] == i)
                count++;
            if (count == 2)
                repeat = i;
            else if (count == 0)
                missing = i;
            if (missing == -1 && repeat == -1)
                break;
        }
    }
    cout << "Repeating and missing numbers are: " << repeat << ", " << missing;
}


//better solution for finding missing and repeating
void missingAndRepeatBtr(vector<int> &arr){
    int n = arr.size();
    int hash[n+1] = {0};
    int repeat = -1, missing = -1;
    for(int i=0; i<n; i++){
        hash[arr[i]]++;
    }
    for(int i = 1; i < n+1; i++){
        if(hash[i] == 2) repeat = i;
        else if(hash[i] == 0) missing = i;
        if(repeat != -1 && missing != -1) break;
    }
    cout << repeat << ", " << missing;
}


vector<int> missingAndRepeatOptMath(vector<int> &arr){
    long long n = arr.size();
    long long SN = (n * (n+1)) / 2;
    long long S2N = (n * (n+1)* (2*n+1)) / 6;
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++)
    {
        S += arr[i];
        S2 += (long long) arr[i] * (long long) arr[i];
    }
    long long val1 = S - SN;
    long long val2 = S2 - S2N;
    val2 = val2 / val1;
    long long x = (val1 + val2) / 2;
    long long y = x - val1;
    return {(int)x, (int)y};
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
    vector<int> ans = missingAndRepeatOptMath(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    
}