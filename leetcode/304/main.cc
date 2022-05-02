#include <vector>
#include <iostream>
using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        size_t n = matrix.size() + 1;
        size_t m = matrix[0].size() + 1;

        pre_sum.resize(n);
        for (size_t i = 0; i < n; ++i)
            pre_sum[i].resize(m);

        for (size_t i = 1; i < n; ++i) 
            for (size_t j = 1; j < m; ++j) {
                pre_sum[i][j] = pre_sum[i-1][j] + pre_sum[i][j-1] + matrix[i-1][j-1] - pre_sum[i-1][j-1];
            }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return (pre_sum[row2+1][col2+1] - pre_sum[row1][col2+1] - pre_sum[row2+1][col1] + pre_sum[row1][col1]);
    }
private:
    vector<vector<int>> pre_sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main() {
    vector<vector<int>> nums= {{3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5}};
    NumMatrix numMatrix(nums);
    std::cout << numMatrix.sumRegion(2, 1, 4, 3) << std::endl; // return 8 (红色矩形框的元素总和)
    std::cout << numMatrix.sumRegion(1, 1, 2, 2) << std::endl; // return 11 (绿色矩形框的元素总和)
    std::cout << numMatrix.sumRegion(1, 2, 2, 4) << std::endl; // return 12 (蓝色矩形框的元素总和)
    return 0;
}