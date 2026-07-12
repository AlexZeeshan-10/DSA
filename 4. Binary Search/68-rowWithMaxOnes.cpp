#include <iostream>
#include <vector>

int lowerBound(std::vector<int> &arr, int target)
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

int rowWithMax1s(std::vector<std::vector<int>> &mat, int n, int m){
    int cnt_max = 0;
    int index = -1;
    for (size_t i = 0; i < n; i++)
    {
        int cnt_ones = m - lowerBound(mat[i], 1);
        (cnt_ones > cnt_max) ? cnt_max = cnt_ones, index = i : 0;
    }
    return index;
}

int main(){
    int row, column;
    std::cin >> row;
    std::cin >> column;

    std::vector<std::vector<int>> mat(row, std::vector<int>(column));

    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < column; j++)
        {
            std::cin >> mat[i][j];
        }
    }

    int ans = rowWithMax1s(mat, row, column);
    std::cout << ans << std::endl;
}