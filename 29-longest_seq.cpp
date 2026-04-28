#include<bits/stdc++.h>
using namespace std;


//linear search algo
bool linearSearch(vector<int> arr, int n){
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == n) return true;
    }
    return false;
}

// Brute force approach using linear search (O(N^2) or O(N^3))
int longestSuccessiveElements_BruteForce(vector<int>& arr) {
    if(arr.empty()) return 0;
    int longest = 1;
    for(int i = 0; i < arr.size(); i++) {
        int x = arr[i];
        int cnt = 1;
        // This is where linear search is used to find the next element in the sequence
        while(linearSearch(arr, x + 1)) {
            x += 1;
            cnt += 1;
        }
        longest = max(longest, cnt);
    }
    return longest;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n,0);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
    
    // Output the result
    cout << longestSuccessiveElements_BruteForce(arr) << endl;
    return 0;
}