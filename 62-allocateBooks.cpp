#include <iostream>
#include <vector>

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