#include <iostream>
#include <vector>
using namespace std;

// Lower bound method
int lowerBound(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;
    int ans = arr.size() + 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

// upper bound
int upperBound(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;
    int ans = arr.size() + 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int floor(vector<int> &arr, int target){
    int ans = -1;
    int low = 0, high = arr.size()-1;
    while (low <= high)
    {
        int mid = (low + high)/2;
        if(arr[mid] <= mid){
            ans = arr[mid];
            low = mid+1;
        }
        else high = mid -1;
    }
    return ans;
}

// main function
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
    int ans = upperBound(arr, target);
    cout << ans << " ";
}