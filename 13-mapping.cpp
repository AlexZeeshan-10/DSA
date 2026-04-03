#include<bits/stdc++.h>
using namespace std;


// Mapping for int
// int main(){
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i<n ; i ++){
//         cin >> arr[i];
//     }

//     map<int, int> mpp;
//     for(int i = 0; i<n ; i++){
//         mpp[arr[i]]++;
//     }

//     for (auto it : mpp){
//         cout << it.first << " -> " << it.second <<endl;
//     }
//     int q;
//     cin >> q;
//     while(q--){
//         int number;
//         cin >> number;
//         cout << mpp[number] << endl;
//     }
// }

//mapping for sting
int main(){
    string s;
    map<char ,int> mpp;
    cin >> s;

    for (int i = 0; i < s.size(); i++){
        mpp[s[i]]++;
    }
    
    for(auto it : mpp){
        cout << it.first << " -> " << it.second << endl;
    }

    int q;
    cin >> q;
    while (q--){
        char c;
        cin >> c;
        cout << mpp[c] << endl;
    }
}