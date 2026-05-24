#include <iostream>
#include <vector>
using namespace std;

// brute force method to find the first and last occurence in an array
vector<int> occurBrute(vector<int> &arr, int target)
{
    int i = -1, j = -1;
    for (int x = 0; x < arr.size(); x++)
    {
        if (arr[x] == target)
        {
            if (i == -1)
                i = x;
            j = x;
        }
    }
    return {i, j};
}

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

vector<int> occurOptimal(vector<int> &arr, int target)
{
    int lb = lowerBound(arr, target);
    if (lb == arr.size() || arr[lb] != target)
        return {-1, -1};
    return {lb, upperBound(arr, target) - 1};
}

int occurOptimalfirst(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;
    int first = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            first = mid;
            high = mid - 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return first;
}

int occurOptimallast(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;
    int last = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            last = mid;
            low = mid + 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return last;
}

pair<int, int> occurOptimal1(vector<int> &arr, int target){
    int first = occurOptimalfirst(arr, target);
    if(first == -1) return {-1, -1};
    int last = occurOptimallast(arr, target);
    return {first, last};
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    pair<int, int> ans = occurOptimal1(arr, target);
    cout << ans.first << " " << ans.second << "\n";
}
