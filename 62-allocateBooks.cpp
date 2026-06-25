#include <iostream>
#include <vector>

int findPagesBrute(std::vector<int> &arr, int student)
{
    if (arr.size() < student)
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