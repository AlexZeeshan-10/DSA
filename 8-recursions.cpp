#include <bits/stdc++.h>
using namespace std;

void fn(int n){
    cout << n << endl;
    n += 1;
    fn(n);
}

int main(){
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    #endif
    int n;
    cin >> n;
   fn(n);
   return 0;
}