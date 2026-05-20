#include<bits/stdc++.h>
using namespace std;

//brute force method to find the first and last occurence in an array
vector<int> occurBrute(vector<int> &arr, int target){
    int i = -1, j = -1;
    for (int x = 0; x < arr.size(); x++)
    {
        if(arr[x] == target){
            if(i == -1) i = x;
            j = x;
        }
    }
    return {i, j};
}

vector<int> occurOptimal(vector<int> &arr, int target){
    
}

int main(){
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;

}
