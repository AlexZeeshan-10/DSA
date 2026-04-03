#include <bits/stdc++.h>
using namespace std;


// print name n times using recursion
void name5(int n, string s)
{
    if (n < 6)
        cout << s << endl;
    else
        return;

    n += 1;
    // name5(s);
}


// print one to n using recursion method
void o2n(int i, int n){
    if(i>n) return;
    
    cout << i << endl;
    o2n(i+1, n);
}


//print n to one using backtrack recursive method
void n2o(int i, int n){
    if(i>n) return;
    
    n2o(i+1, n);
    cout << i << endl;
}



int main()
{   
    // string s;
    int n;
    cin >> n;
    n2o(1,n);
}