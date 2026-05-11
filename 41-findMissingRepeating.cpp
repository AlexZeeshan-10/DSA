#include <bits/stdc++.h>
using namespace std;

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




int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
    missingAndRepeatBtr(arr);
}