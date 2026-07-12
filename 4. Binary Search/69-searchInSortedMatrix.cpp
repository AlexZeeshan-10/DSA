#include <iostream>
#include <vector>

bool searchMatrixBrute(std::vector<std::vector<int>>, int target){
    
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
    
    bool ans = searchMatrixBrute(mat, target);
    std::cout << ans << std::endl;
}