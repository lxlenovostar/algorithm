#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> ret;
        ret.resize(row+1);
        for (auto &item: ret) {
            item.resize(col+1, 0);
        }

        for (int i = 1; i <= row; ++i) {
            for (int j = 1; j <= col; ++j) {
                
                if (i == 1) {
                    ret[i][j] = grid[i-1][j-1] + ret[i][j-1];
                } else if (j == 1) {
                    ret[i][j] = grid[i-1][j-1] + ret[i-1][j];
                } else {
                    ret[i][j] = grid[i-1][j-1] + std::min(ret[i][j-1], ret[i-1][j]);
                    //std::cout << "i: " << i << " j: " << j << " ret[i][j]: " << ret[i][j] << std::endl;
                }
            }
        }

        return ret[row][col];
    }
};

int main() {
    vector<vector<int>> grid = {{1,3,1}, {1,5,1}, {4,2,1}};
    Solution *test = new Solution();
    std::cout << test->minPathSum(grid) << std::endl;
    return 0;
}