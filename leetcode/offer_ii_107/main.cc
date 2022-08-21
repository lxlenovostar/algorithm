#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <limits>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int m_row_size;
    int m_col_size;
    std::set<std::pair<int, int>> m_dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    // 无法保存访问过的节点
    /*
    int dfs(vector<vector<int>>& mat, int row, int col, int step) {
        if (row < 0 || row >= m_row_size || col < 0 || col >= m_col_size) {
            return step;
        }

        //visited.insert(std::make_pair(row, col));
        
        if (mat[row][col] == 0) {
            return step+1;
        }

        vector<int> tmp_ret;
        tmp_ret.resize(m_dirs.size());

        int index = 0;
        for (const auto& dir: m_dirs) {
            tmp_ret[index] = dfs(mat, row + dir.first, col + dir.second, step+1);
            ++index;
        }

        return *std::min_element(tmp_ret.begin(), tmp_ret.end());
    }
    */

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m_row_size = mat.size();
        m_col_size = mat[0].size();

        m_dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        vector<vector<int>> ret;
        std::set<std::pair<int, int>> seen;
        ret.resize(m_row_size);
        for (int i = 0; i < m_row_size; ++i) {
            ret[i].resize(m_col_size);
        }
        std::queue<std::pair<int, int>> visited;

        for (int i = 0; i < m_row_size; ++i) {
            for (int j = 0; j < m_col_size; ++j) {
                if (mat[i][j] == 0) {
                    ret[i][j] = 0;
                    visited.push(std::make_pair(i, j));
                    //seen.insert(std::make_pair(i, j));
                    seen.emplace(i, j);
                } else {
                    ret[i][j] = std::numeric_limits<int>::max();
                }
            }
        }

        while (!visited.empty()) {
            const auto & item = visited.front();
            visited.pop();
            int row = item.first;
            int col = item.second;
        
            for (const auto& dir: m_dirs) {
                int next_row =  row + dir.first;
                int next_col = col + dir.second;

                if (next_row >= 0 && next_row < m_row_size && next_col >= 0 && next_col < m_col_size && seen.find(std::make_pair(next_row, next_col)) == seen.end()) {
                    if (ret[next_row][next_col] > ret[row][col] + 1) {
                        ret[next_row][next_col] = ret[row][col] + 1;
                        visited.push(std::make_pair(next_row, next_col));
                        seen.emplace(next_row, next_col);
                    }
                }
            }
        }

        return ret;
    }
};

int main()
{
    //vector<vector<int>> mat = {{0,0,0}, {0,1,0}, {0,0,0}};
    vector<vector<int>> mat = {{0,0,0}, {0,1,0}, {1,1,1}};
    Solution *test = new Solution();
    const vector<vector<int>> &ret = test->updateMatrix(mat);
    for (const auto& item: ret) {
        for (const auto& value: item) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}