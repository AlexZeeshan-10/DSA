#include <bits/stdc++.h>
using namespace std;
// void functions -> Does not return any value
// Return functions ->
// Paramaeterized functions -> Takes some input
// Non-parameterized functions -> Does not take any input

// Name printing using void function with parameter

// void printname(string name)
// {
//     cout << "Hey " << name << endl;
// }

// int main()
// {
//     int i, n;
//     cin >> n;
//     for (i = 1; i <= n; i++)
//     {
//         string name;
//         cin >> name;
//         printname(name);
//     }
// }

// Sum of two numbers using return function with parameters

// int sum(int num1, int num2)
// {
//     int num3 = num1 + num2;
//     return num3;
// }
// int main()
// {
//     int num1, num2;
//     cin >> num1 >> num2;
//     int res = sum(num1, num2);
//     cout << "Sum of " << num1 << " + " << num2 << " = " << res << endl;
//     return 0;
// }

// Array functions

void Word(int arr[], int n)
{
    arr[2] += 100;
    cout << arr[2] << endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Word(arr, n);
    cout << arr[2]; // arr[2] is changed because array is passed by reference
}