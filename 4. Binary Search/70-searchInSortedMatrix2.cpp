#include <iostream>
#include <vector>

bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    int n = matrix.size();
    int m = matrix[0].size();
    int row = 0, col = m - 1; 

    while (row < n && col >= 0) {
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] > target) col--; 
        else row++; 
    }
    return false;
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

    int target;
    std::cin >> target;

    bool ans = searchMatrix(mat, target);
    (ans == 1) ? std::cout << "True" : std::cout << "False";
}