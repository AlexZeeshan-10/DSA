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
    map<int, int> mpp;
    int repeat;
    for(int it:arr){
        mpp[it]++;
    }
    for(auto x:mpp){
        if(x.second == 2) repeat = x.first;
    }
    cout << repeat << " ";
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