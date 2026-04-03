#include <bits/stdc++.h>
using namespace std;

// uniform pattern
void print1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << " * ";
        }
        cout << endl;
    }
}

// right angled triangle pattern
void print2(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

// right angled number pattern
void print3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

// right angled uniform pattern
void print4(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

// reverse star right angled pattern
void print5(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > i; j--)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

// reverse number right angled pattern
void print6(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << j;
        }
        cout << endl;
    }
}

// star pyramid pattern
void print7(int n)
{
    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < n - i + 1; j++)
        {
            cout << " ";
        }

        // star
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }

        // space
        for (int j = 0; j < n - i + 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

// reverse star pyramid pattern
void print8(int n)
{
    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        // star
        for (int j = 0; j < 2 * n - (2 * i + 1); j++)
        {
            cout << "*";
        }

        // space
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

// star and reverse star consecutive pyramid pattern
void print9(int n)
{
    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < n - i + 1; j++)
        {
            cout << " ";
        }

        // star
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }

        // space
        for (int j = 0; j < n - i + 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    { // space
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        // star
        for (int j = 0; j < 2 * n - (2 * i + 1); j++)
        {
            cout << "*";
        }

        // space
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

// consecutive right angled triangle pattern
void print10(int n)
{
    for (int i = 1; i <= 2 * n - i; i++)
    {
        int stars = i;
        if (i > n)
            stars = 2 * n - i;
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

// alternate 0-1 triangle pattern
void print11(int n)
{
    int start = 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            start = 1;
        else
            start = 0;
        for (int j = 0; j <= i; j++)
        {
            cout << start;
            start = 1 - start;
        }
        cout << endl;
    }
}

// number pattern double sided right angled triangle
void print12(int n)
{
    int space = 2 * (n - 1);
    for (int i = 1; i <= n; i++)
    {
        // number
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        // space
        for (int j = 1; j <= space; j++)
        {
            cout << " ";
        }
        // number
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }
        cout << endl;
        space -= 2;
    }
}

// pattern 13 Striver's sheet
void print13(int n)
{
    int num = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
}

// Alphabet pattern
void print14(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + i; ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}

// Reverse Alphabet pattern
void print15(int n)
{

    for (int i = 0; i < n; i++)
    {
        char ch = 'A';
        for (int j = n; j > i; j--)
        {

            cout << ch << " ";
            ch++;
        }
        cout << endl;
    }
}

// Alphabet same line pattern
void print16(int n)
{
    int ch = 'A';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << (char)ch << " ";
        }
        ch = ch + 1;
        cout << endl;
    }
}

// Alphabet Pyramid Pattern
void print17(int n)
{
    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        // characters
        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << ch;
            if (j <= breakpoint - 1)
            {
                ch++;
            }
            else
            {
                ch--;
            }
        }

        // space
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

// Alphabet Reverse right angled triangle pattern starts from 'E'
void print18(int n)
{
    for (int i = 0; i < n; i++)
    {
        char ch = 'E' - i;
        for (int j = 0; j <= i; j++)
        {
            cout << ch << " ";
            ch = ch + 1;
        }
        cout << endl;
    }
}

// square and rect patterns using "*"
void print19(int n)
{
    for (int i = 0; i < n; i++)
    {
        // star
        for (int j = n; j > i; j--)
        {
            cout << "*";
        }

        // space
        for (int j = 0; j < 2 * i; j++)
        {
            cout << " ";
        }

        // star
        for (int j = n; j > i; j--)
        {
            cout << "*";
        }

        cout << endl;
    }

    for (int i = n; i >= 0; i--)
    {
        // star
        for (int j = n; j > i; j--)
        {
            cout << "*";
        }

        // space
        for (int j = 0; j < 2 * i; j++)
        {
            cout << " ";
        }

        // star
        for (int j = n; j > i; j--)
        {
            cout << "*";
        }

        cout << endl;
    }
}

// square pattern using "*"
void print20(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }

        cout << endl;
    }
}

// main function
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        print9(n);
        cout << endl;
    }
}