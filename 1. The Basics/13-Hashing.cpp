#include <bits/stdc++.h>
using namespace std;


//hash mapping
// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i=0; i<n; i++)
//     {
//         cin >> arr[i];
//     }

//     int hash[100] = {0};
//     for(int i = 0; i<n; i++){
//         hash[arr[i]] += 1;
//     }

//     int q;
//     cin >> q;

//     while (q--)
//     {
//         int num;
//         cin >> num;
//         cout << hash[num] << endl;
        
//     }   
    

//     return 0;
// }

int main(){
    string s;
    cin >> s;

    int hash[256] = {0};
    for(int i = 0; i < s.size(); i++){
        hash[s[i]]++;
    }

    int q;
    cin >> q;
    while(q--){
        char c;
        cin >> c;
        cout << hash[c] << endl;
    }
    return 0;
}

