#include <vector>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// 实现了深度优先搜索，广度优先搜索
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int nums = 0;

        for (int i = 0 ; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                   nums++;
                   bfs(grid, i, j); 
                }
            }
        }

        return nums;
    }
private:
    void bfs(vector<vector<char>>& grid, int i, int j) {
        queue<std::pair<int , int>> check_stack;
        check_stack.push(std::make_pair(i, j));

        while (!check_stack.empty()) {
            auto node = check_stack.front();
            check_stack.pop();

            vector<vector<int>> dirs = {{-1, 0}, {1,0}, {0,-1}, {0,1}};

            for (auto dir : dirs) {
                int r = node.first + dir[0];
                int c = node.second + dir[1];
                if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c] == '1') {
                    grid[r][c] = '0';
                    check_stack.push(std::make_pair(r, c));
                }
            }

        }
    }

    void dfs2(vector<vector<char>>& grid, int i, int j) {
        stack<std::pair<int , int>> check_stack;
        check_stack.push(std::make_pair(i, j));

        while (!check_stack.empty()) {
            auto node = check_stack.top();
            check_stack.pop();

            vector<vector<int>> dirs = {{-1, 0}, {1,0}, {0,-1}, {0,1}};

            for (auto dir : dirs) {
                int r = node.first + dir[0];
                int c = node.second + dir[1];
                if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c] == '1') {
                    grid[r][c] = '0';
                    check_stack.push(std::make_pair(r, c));
                }
            }

        }
    }

    void dfs1(vector<vector<char>>& grid, int i, int j) {

        vector<vector<int>> dirs = {{-1, 0}, {1,0}, {0,-1}, {0,1}};

        for (auto dir : dirs) {
            int r = i + dir[0];
            int c = j + dir[1];
            if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c] == '1') {
                grid[r][c] = '0';
                dfs1(grid, r, c);
            }
        }
    }
};

int main() {
    vector<vector<char>>  nums =  {
  {'1', '1', '1', '1', '0'},
  {'1', '1', '0', '1', '0'},
  {'1', '1', '0', '0', '0'},
  {'0', '0', '0', '0', '0'}};

    Solution *test = new Solution();
    std::cout << test->numIslands(nums) << std::endl;
    return 0;
}