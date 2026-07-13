#include <iostream>
#include <vector>

bool searchMatrixBrute(std::vector<std::vector<int>> &matrix, int target)
{
    for (size_t i = 0; i < matrix.size(); ++i)
    {
        for (size_t j = 0; j < matrix[0].size(); ++j)
        {
            if (matrix[i][j] == target)
                return true;
        }
    }
}

bool searchMatrixBS(std::vector<std::vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size() - 1;

    int row = 0;
    int column = m;

    while (row < n && column >= 0)
    {
        if (matrix[row][column] == target)
            return true;
        else if (matrix[row][column] < target)
            row++;
        else
            column--;
    }

    return false;
}

int main()
{
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

    int target;
    std::cin >> target;

    bool ans = searchMatrixBS(mat, target);
    (ans == 1) ? std::cout << "True" : std::cout << "False";
}