#include <iostream>
#include <vector>
#include <climits>

std::vector<int> findPeakGridBrute(std::vector<std::vector<int>>& mat){
    
}

int main(){
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