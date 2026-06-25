#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int cntStudent(std::vector<int> &arr, int pages){
    int students = 1;
    long long pagesStudent = 0;
    for (size_t i = 0; i < arr.size(); i++)
    {
        if(pagesStudent + arr[i] <= pages)
        {
            pagesStudent += arr[i];
        }
        else
        {
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPagesBrute(std::vector<int> &arr, int student)
{
    if (arr.size() < student)
        return -1;

    int low = *std::max_element(arr.begin(), arr.end());
    int high = std::accumulate(arr.begin(), arr.end(), 0);
    for (int pages = low; pages <= high; pages++)
    {
        int studentsNeeded = cntStudent(arr, pages);
        if(studentsNeeded <= student)
            return pages;
    }
    return -1;
}

int findPagesBS(std::vector<int> &arr, int student){
    int low = *std::max_element(arr.begin(), arr.end());
    int high = std::accumulate(arr.begin(), arr.end(), 0);
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if(cntStudent(arr, mid) <= student)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return high + 1;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cin >> arr[i];
    }
    int student;
    std::cin >> student;
    int ans = findPagesBS(arr, student);
    std::cout << ans << std::endl;
}