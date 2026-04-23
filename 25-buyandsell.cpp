#include<bits/stdc++.h>
using namespace std;

int buyStock(vector<int> &arr){
    int mini = arr[0], profit = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        int cost = arr[i] - mini;
        profit = max(profit, cost);
        mini = min(mini, arr[i]);
    }
    return profit;
}

int main(){
     int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < arr.size(); i++)
        {
            cin >> arr[i];
        }
        int x = buyStock(arr);
        cout << x;
}