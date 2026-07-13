#include <iostream>
#include <vector>
#include <climits>

std::vector<int> findPeakGridBrute(std::vector<std::vector<int>> &mat)
{
    std::vector<int> ans(2);
    int maxi = INT_MIN;
    for (size_t i = 0; i < mat.size(); i++)
    {
        for (size_t j = 0; j < mat[0].size(); j++)
        {
            if (mat[i][j] > maxi)
            {
                maxi = mat[i][j];
                ans[0] = i;
                ans[1] = j;
            }
        }
    }
    return ans;
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

    std::vector<int> ans = findPeakGridBrute(mat);
    std::cout << ans[0] << " " << ans[1] << std::endl;
}