#include <iostream>
#include <vector>

std::vector<int> findPeakGridBS(std::vector<std::vector<int>> &mat){
    int n = mat.size(), m = mat[0].size();
    int low = 0, high = m - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int maxRowIndex = findMaxIndex(mat, n, m, mid);
        
    }
    
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
    
    std::vector<int> ans = findPeakGridBS(mat);
    std::cout << ans[0] << " " << ans[1] << std::endl;
}