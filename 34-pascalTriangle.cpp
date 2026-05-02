#include<bits/stdc++.h>
using namespace std;


// To calculate nCr of a given number
int nCr(int n, int r){
    long long res = 1;
    for (int i = 0; i < r; i++)
    {
        res = res*(n-i);
        res = res / (i + 1);
    }
    return res;
}


//generating pascal triangle row
void pasTriangleRow(int n){
    int ans = 1;
    cout << "1 ";
    for(int c = 1; c<n; c++){
        ans = ans * (n-c);
        ans = ans / c;
        cout << ans << " ";
    }
}


int main(){
    // code pending re-watch understand again and write the code over here
    int n;
    cin >> n;
    for (int i = 1; i < n+1; i++)
    {
        pasTriangleRow(i);
        cout << endl;
    }
}