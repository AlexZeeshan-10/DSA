#include <iostream>
#include <vector>

int findMaxIndex(std::vector<std::vector<int>> &mat, int n, int m, int col)
{
    int maxVal = -1;
    int ind = -1;
    for (size_t i = 0; i < n; i++)
    {
        (mat[i][col] > maxVal)
            ? (maxVal = mat[i][col], ind = i)
            : 0;
    }
    return ind;
}

std::vector<int> findPeakGridBS(std::vector<std::vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();
    int low = 0, high = m - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int maxRowIndex = findMaxIndex(mat, n, m, mid);
        int left = (mid - 1 >= 0) ? mat[maxRowIndex][mid - 1] : -1;
        int right = (mid + 1 <= m) ? mat[maxRowIndex][mid + 1] : -1;
        if (mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right)
        {
            return {maxRowIndex, mid};
        }
        else if (mat[maxRowIndex][mid] < left)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return {-1, -1};
}

int main()
{
    int row, column;
    std::cin >> row;
    std::cin >> column;
    std::vector<std::vector<int>> mat(row, std::vector<int>(column));
    for (size_t i = 0; i < row; ++i)
    {
        for (size_t j = 0; j < column; ++j)
        {
            std::cin >> mat[i][j];
        }
    }

    std::vector<int> ans = findPeakGridBS(mat);
    std::cout << ans[0] << " " << ans[1] << std::endl;
}