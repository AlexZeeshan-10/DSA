#include <bits/stdc++.h>
using namespace std;

int main()
{

    // Age check using if else

    //   int x;
    //   cin >> x;
    //   if (0 < x && x < 18)
    //   {
    //     cout << "Age is " << x << ", Person is not Adult " <<endl;
    //   }
    //   else if (x >= 18)
    //   {
    //     cout << "Age is " << x << ", Person is Adult" <<endl;
    //   }
    //   else
    //   {
    //     cout << "Error" << endl;
    //   }

    // Grade check using if else if else

    // int marks;
    // cin >> marks;
    // if (marks >= 0 && marks <= 25)
    // {
    //     cout << "Marks obtained are " << marks << endl;
    //     cout << "Grade is F";
    // }
    // else if (marks < 45)
    // {
    //     cout << "Marks obtained are " << marks << endl;
    //     cout << "Grade is E";
    // }
    // else if (marks < 50)
    // {
    //     cout << "Marks obtained are " << marks << endl;
    //     cout << "Grade is D";
    // }
    // else if (marks < 60)
    // {
    //     cout << "Marks obtained are " << marks << endl;
    //     cout << "Grade is C";
    // }
    // else if (marks < 80)
    // {
    //     cout << "Marks obtained are " << marks << endl;
    //     cout << "Grade is B";
    // }
    // else if (marks <= 100)
    // {
    //     cout << "Marks obtained are " << marks << endl;
    //     cout << "Grade is A";
    // }
    // else
    // {
    //     cout << "Invalid Marks";
    // }

    // Job eligibility using if else

    // int age;
    // cin >> age;
    // if (age >= 0 && age < 18)
    // {
    //     cout << "Person is not eligible for job";
    // }
    // else if (age < 58)
    // {
    //     cout << "Person is eligible for job";
    //     if (age >= 55)
    //     {
    //         cout << ", but retirement soon";
    //     }
    // }
    // else if (age <= 100)
    // {
    //     cout << "Person is retired";
    // }
    // else
    // {
    //     cout << "Invalid Age";
    // }

    // Day fo the week using switch case

    int day;
    cin >> day;
    switch (day)
    {
    case 1:
        cout << "Monday";
        break;
    case 2:
        cout << "Tuesday";
        break;
    case 3:
        cout << "Wednesday";
        break;
    case 4:
        cout << "Thursday";
        break;
    case 5:
        cout << "Friday";
        break;
    case 6:
        cout << "Saturday";
        break;
    case 7:
        cout << "Sunday";
        break;
    default:
        cout << "Invalid Day";
        break;
    }

    return 0;
}