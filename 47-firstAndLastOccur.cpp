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

// Lower bound method: Finds the first index where the element is greater than or equal to the target
int lowerBound(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;
    int ans = arr.size() + 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target)
        {
            // Potential answer found, but continue looking on the left for a smaller index
            ans = mid;
            high = mid - 1;
        }
        else
            // Target is greater, so the lower bound must be on the right half
            low = mid + 1;
    }
    return ans;
}

// Upper bound method: Finds the first index where the element is strictly greater than the target
int upperBound(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;
    int ans = arr.size() + 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > target)
        {
            // Potential answer found, but continue looking on the left for a smaller index
            ans = mid;
            high = mid - 1;
        }
        else
            // Target is greater than or equal, so the upper bound must be on the right half
            low = mid + 1;
    }
    return ans;
}

// Optimal approach using the lower_bound and upper_bound helper functions
vector<int> occurOptimal(vector<int> &arr, int target)
{
    int lb = lowerBound(arr, target);
    // If target is not present in the array
    if (lb == arr.size() || arr[lb] != target)
        return {-1, -1};
    // The last occurrence is the index just before the upper bound
    return {lb, upperBound(arr, target) - 1};
}

// Function to find the first occurrence using binary search directly
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
            high = mid - 1; // Move left to see if there are earlier occurrences
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

// Function to find the last occurrence using binary search directly
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
            low = mid + 1; // Move right to see if there are later occurrences
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

// Wrapper function to get both first and last occurrences
pair<int, int> occurOptimal1(vector<int> &arr, int target){
    int first = occurOptimalfirst(arr, target);
    // If the element doesn't exist, we can early exit without searching for the last occurrence
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
