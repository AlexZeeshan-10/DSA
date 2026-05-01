#include<bits/stdc++.h>
using namespace std;

// To calculate nCr of a given number
int nCr(int n, int r){
    long long res = 1;
    for (int i = 0; i < r; i++)
    {
        res = res*(n-1);
        res = res / (i + 1);
    }
    return res;
}

int main(){

}