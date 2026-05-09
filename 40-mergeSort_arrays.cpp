#include <bits/stdc++.h>
using namespace std;

/*To test the code use this input :
5
5
0 2
1 3 5 7 9
*/

// Solution by self optimal version 1
void mergeSortArray(vector<int> &arr1, vector<int> &arr2)
{

    int left = arr1.size() - 1, right = 0;
    while (left > -1 && right < arr2.size())
    {
        if (arr1[left] > arr2[right])
        {
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }
        else
            break;
    }

    sort(arr1.begin(), arr1.end()); // sort(arr1, arr1.size())
    sort(arr2.begin(), arr2.end()); // sort(arr2, arr2.size())
}

// Optimal solution version 2{shell method} mentioned in the video

int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    vector<int> arr1(n);
    vector<int> arr2(m);
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    mergeSortArray(arr1, arr2);

    for (int it : arr1)
    {
        cout << it << " ";
    }
    for (int it : arr2)
    {
        cout << it << " ";
    }
}