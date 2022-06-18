#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int N = matrix.size();

        if (N == 0) 
            return ret;

        int M = matrix[0].size();

        int row = 0;
        int column = 0;
        int total_num = N*M;

        vector<vector<int>> direction = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int direct_now = 0;

        vector<vector<bool>> visited(N, vector<bool>(M));

        int next_row = 0;
        int next_col = 0;
        for (int i = 0; i < total_num; ++i) {
            visited[row][column] = true;
            ret.push_back(matrix[row][column]);

            next_row = row + direction[direct_now][0];
            next_col = column + direction[direct_now][1];

            //std::cout << "next_row: " << next_row << std::endl;
            //std::cout << "next_col: " << next_col << std::endl;

            if (next_row >= N || next_col >= M || next_row < 0 ||  next_col < 0 || visited[next_row][next_col]) {
                direct_now =  (direct_now + 1) % 4;
            }

            row += direction[direct_now][0];
            column += direction[direct_now][1];
        }

        return ret;

    }
};

int main()
{
    vector<vector<int> >matrix = {{1,2,3}, 
                                {4,5,6}, 
                                {7,8,9}};

    Solution *test = new Solution();

    for (const auto& item: test->spiralOrder(matrix))
        std::cout << item  << std::endl;

    return 0;
}