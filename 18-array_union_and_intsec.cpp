#include<bits/stdc++.h>
using namespace std;

void left_rotate(vector<int> &arr, int count){
    if (arr.empty()) return;
    count %= arr.size();
    // while(count--){
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
    if(arr.empty()) return;
    int j = 0;
    for (int i = 0; i < arr.size(); i++){
               if(arr[i] != 0){
                swap(arr[i], arr[j]);
                j++;
        }
    }
}

//linear search
vector<int> Linear_Search(vector<int> &arr, int n){
    vector<int> temp;
    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i]==n){
            temp.push_back(i); // Save the index where the element was found
        }
    }
    return temp;
}

int main(){  
    int n, find;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++){
        cin >> arr[i];
    }

    cin >> find; 
    vector<int> s = Linear_Search(arr, find);

    for (int i = 0; i < s.size(); i++){
        cout << s[i] << " ";
    }
}