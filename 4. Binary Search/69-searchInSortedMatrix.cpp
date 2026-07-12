#include <iostream>
#include <vector>

bool searchMatrixBS(std::vector<std::vector<int>> &matrix, int target){
    int n = matrix.size();
    int m = matrix[0].size();
    for(size_t i = 0; i<matrix.size(); ++i){
            if(matrix[i][0] <= target && matrix[i][m-1]){
                return binarySearch(matrix[i], target);
            }
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
    
    bool ans = searchMatrixBS(mat, target);
    std::cout << ans << std::endl;
}