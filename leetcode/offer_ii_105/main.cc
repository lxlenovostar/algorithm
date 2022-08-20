#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int m_row_size;
    int m_col_size;
    std::set<std::pair<int, int>> check_point;

    void helper(vector<vector<int>>& grid, int row, int col, int& ret) {
        if (row >= m_row_size || col >= m_col_size || row < 0 || col < 0 || grid[row][col] == 0) {
            return;
        }

        if (check_point.find(std::make_pair(row, col)) != check_point.end()) {
            return;
        }
        check_point.insert(std::make_pair(row, col));
        
        ++ret;
        helper(grid, row-1, col, ret);
        helper(grid, row+1, col, ret);
        helper(grid, row, col-1, ret);
        helper(grid, row, col+1, ret);

    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ret = 0;

        if (grid.size() < 1)
            return ret;

        m_row_size = grid.size();
        m_col_size = grid[0].size();

        for (int i = 0; i < m_row_size; ++i) {
            for (int j = 0; j < m_col_size; ++j) {
                int tmp_ret = 0;
                helper(grid, i, j, tmp_ret);
                ret = std::max(ret, tmp_ret);
            }
        } 

        return ret;
    }
};

int main()
{
    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0}, 
                                {0,0,0,0,0,0,0,1,1,1,0,0,0}, 
                                {0,1,1,0,1,0,0,0,0,0,0,0,0}, 
                                {0,1,0,0,1,1,0,0,1,0,1,0,0}, 
                                {0,1,0,0,1,1,0,0,1,1,1,0,0}, 
                                {0,0,0,0,0,0,0,0,0,0,1,0,0}, 
                                {0,0,0,0,0,0,0,1,1,1,0,0,0}, 
                                {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    Solution *test = new Solution();
    std::cout << test->maxAreaOfIsland(grid) << std::endl;
    return 0;
}