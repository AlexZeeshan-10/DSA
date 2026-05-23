#include <iostream>
#include <vector>
using namespace std;

int BSitr(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1, mid = 0;
    while (low <= high)
    {
        mid = (low+high) / 2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) low = mid+1;
        else high = mid-1;
    }
    return -1;
}

int BSrec(vector<int> &arr, int low, int high, int target){
    if(low > high) return -1;
    int mid = low + (high - low)/2;
    if(arr[mid] == target) return mid;
    else if(target > arr[mid]) return BSrec(arr, mid+1, high, target);
    else return BSrec(arr, low, mid-1, target);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }

    int target;
    cin >> target;
    int ans = BSrec(arr, 0, n-1, target);
    cout << ans+1 << " ";
}