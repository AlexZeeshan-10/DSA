#include <iostream>
#include <vector>
using namespace std;

// merge algo
int merge(vector<int> &arr, int l, int mid, int h)
{
    int cnt = 0;
    vector<int> temp;
    int left = l;
    int right = mid + 1;
    while (left <= mid && right <= h)
    {

        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);

            cnt += (mid - left + 1);

            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= h)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = l; i <= h; i++)
    {
        arr[i] = temp[i - l];
    }
    return cnt;
}

// mergeSort algo
int merge_sort(vector<int> &arr, int l, int h)
{
    int cnt = 0;
    if (l >= h)
        return 0;
    int mid = l + (h - l) / 2;
    cnt += merge_sort(arr, l, mid);
    cnt += merge_sort(arr, mid + 1, h);
    cnt += merge(arr, l, mid, h);
    return cnt;
}

int inversionCount(vector<int> &arr)
{
    return merge_sort(arr, 0, arr.size() - 1);
}

// main function
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = inversionCount(arr);
    cout << ans;
}