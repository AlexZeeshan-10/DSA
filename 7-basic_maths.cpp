#include <bits/stdc++.h>
using namespace std;

int revNum(int n){
    int s, l = 0;
	while (n>0){
		s =  n%10;
		n /= 10;
        l = (l*10) + s;
	}
    cout << l;
}


int countDigit(long long n) {
    int s, count = 0;
    while (n > 0)
    {
    s = n%10;
    n /= 10;
    count += 1;
    }
    cout << count;
    return 0;
}

bool isPrime(int n)
{
	// Write your code here.
	int d = n-1, s, check;
	while (d > 1){
        s = n%d;
        d -= 1;
		if (s == 0){
			check = 1;
			break;
		}

        else {
            check = 0;
        }
	}
    if (check == 1){
        cout << "NO";
    }
    else if(check == 0){
        cout << "YES";
    }
    else{
        return 0;
    }
}

int checkPD(int n){
    int s, l = 0, d = n;
    while (n > 0)
    {
        s = n%10;
        n /= 10;
        l = (l*10) + s;
    }
    if (d == l)
        return 1;
    
    else
        return 0;
}

int checkArmstrong(int n){
    int s, d = n, a = 0;
    while (n > 0)
    {
        s = n%10;
        n /= 10;
        a = a + (s*s*s);
    }
    if (d == a)
        return 1;
    
    else 
        return 0;
}

void printDivisors(int n){
    // int d = 1;
    // while (d<n+1){
    //     int c = n%d;
    //     if (c == 0)
    //     cout << d << endl;
    //     d += 1;
    // }

    vector<int> ls;
    for (int i = 1; i<=sqrt(n); i++){
        if(n%i == 0){
            ls.push_back(i);
            if (n/i != i){
                ls.push_back(n/i);
            }
        }
    }
    sort(ls.begin(), ls.end());
    for(auto it : ls) cout << it << " ";
}

long long int sumOrProduct(long long int n, long long int q)
{
    long long int d = 1;
    if (q==1){
        d = d-1;
        for(int i=1; i<=n; i++ ){
            d += i;
        }
    }

    else if(q == 2){
        for(int i=1; i<=n; i++ ){
            d *= i;
        }
    }
    return d;
}

int GCD(long long n, long long q){
    // for(int i=min(n,q); i >= 1; i-- ){
    //     if(n%i == 0 && q%i == 0){
    //         return i;
    //         break;
    //     }
    // }
    int a = n, b = q;
    while (a>0 && b>0)
    {
        if (a>b)
            a %= b;
    
        else
            b %= a;
        
        if (a == 0){
            return b;
            break;
        }

        else if (b ==0)
            return a;
    }
    
}

int main (){
    long long int n, q;
    cin >> n >> q;
    // int c = checkArmstrong(n);
    // if(c==1)
    // cout << "YES";
    // else if(c==0)
    // cout << "NO";
    long long int c = GCD(n,q);

    cout << c;
}