#include<bits/stdc++.h>
using namespace std;

void left_rotate(vector<int> &arr){
    if (arr.empty()) return;
    int temp = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        arr[i-1] = arr[i];
    }
    arr[arr.size() - 1] = temp;
}

int main(){  
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++){
        cin >> arr[i];
    }

    left_rotate(arr);

    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
}