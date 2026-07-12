#include <iostream>
#include <vector>

bool binarySearch(std::vector<int> &arr, int target){
    int low = 0, high = arr.size()-1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if(arr[mid] == target) return true;
        else if(arr[mid] > target) high = mid - 1;
        else low = mid + 1;
    }
    return false;
}

bool searchMatrixBS(std::vector<std::vector<int>> &matrix, int target){
    int n = matrix.size();
    int m = matrix[0].size();
    for(size_t i = 0; i<matrix.size(); ++i){
            if(matrix[i][0] <= target && target <= matrix[i][m-1]){
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
    // std::cout << ans << std::endl;
    (ans == 1) ? std::cout << "True" : std::cout << "False";
}