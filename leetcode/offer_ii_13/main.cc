#include <vector>
#include <iostream>

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m_pre.resize(matrix.size()+1);

        int col_size = matrix[0].size();
        for (int i = 0;i < m_pre.size(); ++i) {
            m_pre[i].resize(col_size+1);    
        }

        for (int i = 1; i < m_pre.size(); ++i) {
            int row_sum = 0;
            for (int j = 1; j < m_pre[0].size(); ++j) {
                row_sum += matrix[i-1][j-1];
                m_pre[i][j] = m_pre[i-1][j] + row_sum;
            }
        }
        
        for (int i = 0; i < m_pre.size(); ++i) {
            for (int j = 0; j < m_pre.size(); ++j) {
                std::cout << m_pre[i][j] << " ";
            }
            std::cout << std::endl;
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return m_pre[row2 + 1][col2 +1] - m_pre[row2 + 1][col1] - m_pre[row1][col2+1] + m_pre[row1][col1];
    }

private:
    vector<vector<int>> m_pre; 
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main() {
    vector<vector<int>> nums = {{3,0,1,4,2}, {5,6,3,2,1}, {1,2,0,1,5}, {4,1,0,1,7}, {1,0,3,0,5}};
    NumMatrix *test = new NumMatrix(nums);
    std::cout << test->sumRegion(2, 1, 4, 3) << std::endl;
    std::cout << test->sumRegion(1, 1, 2, 2) << std::endl;
    std::cout << test->sumRegion(1, 2, 2, 4) << std::endl;
    return 0;
}