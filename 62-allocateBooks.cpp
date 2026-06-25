#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>



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
    int ans = findPagesBrute(arr, student);
    std::cout << ans << std::endl;
}