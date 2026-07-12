#include<bits/stdc++.h>
using namespace std;

//largest element in array
int large_element(vector<int> &arr){
    if(arr.size()<2) return INT_MIN;
    int largest = INT_MIN;
    for (int i = 0; i < arr.size(); i++){
        if(largest < arr[i]){
            largest = arr[i];
        }
    }
    return largest;
}

//second largest element in array
int sec_large(vector<int> &arr){
    if (arr.size() < 2) return INT_MIN; // Guard against tiny arrays
    int largest = arr[0];
    int sec_largest = INT_MIN;
    for (int i = 1; i < arr.size(); i++)
    {
      if(largest < arr[i]){
        sec_largest = largest;
        largest = arr[i];
      }
      else if(largest > arr[i] && sec_largest < arr[i]){
        sec_largest = arr[i];
      }
    }
    return sec_largest;
}

//Smallest element in an array
int small_element(vector<int> &arr){
    if(arr.size() < 2) return INT_MAX;
    int smallest = INT_MAX;
    for (int i = 0; i < arr.size(); i++){
        if(smallest>arr[i]){
            smallest = arr[i];
        }
    }
    return smallest;
}

//Second smallest element in an array
int sec_smallest(vector<int> &arr){
    if(arr.size()<2) return INT_MAX;
    int smallest = arr[0];
    int Ssmallest = INT_MAX;
    for (int i = 0; i < arr.size(); i++){
        if(smallest > arr[i]){
            Ssmallest = smallest;
            smallest = arr[i];
        }
        else if(smallest < arr[i] && Ssmallest > arr[i]){
            Ssmallest = arr[i];
        }
    }
    return Ssmallest;
}
//check if array is sorted
void sorted_arr_check(vector<int> &arr){
    bool flag = true;
    for (int i = 0; i < arr.size()-1; i++)
    {
        if(arr[i]<=arr[i-1]){
            flag = true;
        }
        else if (arr[i]>arr[i+1]){
            cout << "Not sorted";
            flag = false;
            break;
        }
    }
    if(flag == true){
        cout << "Sorted";
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++){
        cin >> arr[i];
    }
    sorted_arr_check(arr);
    // int element = sec_smallest(arr);
    // cout << element << endl;
}
