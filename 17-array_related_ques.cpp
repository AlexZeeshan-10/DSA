#include<bits/stdc++.h>
using namespace std;

//largest element in array
int large_ele(vector<int> &arr){
    int temp = INT_MIN;
    for (int i = 0; i < arr.size(); i++){
        if(temp < arr[i]){
            temp = arr[i];
        }
    }
    return temp;
}

//second largest element in array
int sec_large(vector<int> &arr){
    int large = large_ele(arr);
    int temp = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i] > temp && arr[i] != large){
            temp = arr[i];
        }
    }
    return temp;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++){
        cin >> arr[i];
    }
    int ele = large_ele(arr);
    cout << ele << endl;
}
