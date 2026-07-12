#include <bits/stdc++.h>
using namespace std;

//parameterised function call
void sumoN(int n, int sum){
    if(n<1) {
    cout << sum << endl;
    return;
    }

    sumoN(n-1, sum+n);

}


//functional method of sum of n numbers
int PsumoN(int n){
    if(n == 1) return 1;

    return n + PsumoN(n-1);
}


//Parameterised method of factorial of n
void factoN(int n, int fact){
    if(n<1){
        cout << fact << endl;
        return;
    }

    factoN(n-1, fact*n);
}


//functional method of factorial
int PfactoN(int n){
    if(n == 1) return 1;

    return n * PfactoN(n-1);
}


// Reverse an array
void revarr(int a[], int l, int r){
    if(l >= r) return;
    swap(a[l], a[r]);
    revarr(a, l+1, r-1);
}


// check if string is Palindrome
bool checkstr(int i, string &s){
    if (i >= s.size()/2) return true;
    if (s[i] != s[s.size()-i-1]) return false;
    return checkstr(i+1, s);
}

int main(){
    // int n;
    // cin >> n;
    // sumoN(n, 0);

    // cout << PfactoN(n);

    // int a[n], i = 0;
    // while (i < n)
    // {
    //     cin >> a[i];
    //     i += 1;
    // }
    // revarr(a, 0, n-1);

    // for (i = 0; i < n; i++)
    // {
    //     cout << a[i] << endl;
    // }
    
    string s;
    cin >> s;
    cout << checkstr(0, s);
    return 0;
}