#include<bits/stdc++.h>
using namespace std;

void left_rotate(vector<int> &arr, int count){
    // count %= arr.size();
    // while(count--){
    //     if (arr.empty()) return;
    // int temp = arr[0];
    // for (int i = 1; i < arr.size(); i++)
    // {
    //     arr[i-1] = arr[i];
    // }
    // arr[arr.size() - 1] = temp;
    // }
    reverse(arr.begin(), arr.begin()+count);
    reverse(arr.begin()+count, arr.end());
    reverse(arr.begin(), arr.end());
}
//Move zeros to end
void move_zero(vector<int> &arr){
    int j = 0;
    for (int i = 0; i < arr.size(); i++){
               if(arr[i] != 0){
                swap(arr[i], arr[j]);
                j++;
        }
    }
}

int main(){  
    int n, count;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++){
        cin >> arr[i];
    }

    cin >> count; 
    move_zero(arr);

    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
}