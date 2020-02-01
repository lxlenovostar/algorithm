/*
给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true.
给定 word = "SEE", 返回 true.
给定 word = "ABCB", 返回 false.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int N;
	int M;

    bool dfs(vector<vector<char>>& board, string target, int row, int column, string value, vector<vector<bool>> &check_map, size_t count) {
		if ( count >= target.size() || row < 0 || row >= N || column < 0 || column >= M || check_map[row][column] == true || board[row][column] != target[count])
			return false;

		value += board[row][column];
		check_map[row][column] = true;
		count++;

		std::cout << "row: " << row << " column: " << column << " value: " << value << " target: " << target << std::endl;

		if (value == target) {
			std::cout << "what1 row: " << row << " column: " << column << " value: " << value << " target: " << target << std::endl;
			return true;
		} else {
			std::cout << "what2 row: " << row << " column: " << column << " value: " << value << " target: " << target << std::endl;
		}

		
		bool up = dfs(board, target, row-1, column, value, check_map, count);
		if (up)
			return true;

		bool down = dfs(board, target, row+1, column, value, check_map, count);
		if (down)
			return true;

		bool left = dfs(board, target, row, column-1, value, check_map, count);
		if (left)
			return true;

		bool right = dfs(board, target, row, column+1, value, check_map, count);
		if (right)
			return true;
		
		// Backtracking
		check_map[row][column] = false;

		return false;
	}

    bool exist(vector<vector<char>>& board, string word) {
		N = board.size();
		M = board[0].size();

		int len = word.size();
		if (len <= 0)
			return false;


			for (int j = 0; j < N; ++j) {
				for (int k = 0; k < M; ++k) {

					bool find = false;


					if (board[j][k] == word[0]) {
						string value;
						//value.resize(word.size());

						vector<vector<bool>> check_map;
						check_map.resize(N);
						for (int z = 0; z < N; ++z)
							check_map[z].resize(M);

						size_t count = 0;
						find = dfs(board, word, j, k, value, check_map, count);				

						if (find)
							return true;
					} // if

				} // for k
			} // for j
        
		return false;
    }
};

int main() {
	/*
	vector<vector<char>> board =
		{
			{'a','a','a','a'},
			{'a','a','a','a'},
			{'a','a','a','a'},
			{'a','a','a','a'},
			{'a','a','a','b'},
		};

	string word = "aaaaaaaaaaaaaaaaaaaa";
	*/
	
	vector<vector<char>> board =
		{
			{'C','A','A'},
			{'A','A','A'},
			{'B','C','D'}
		};

	string word = "AAB";
	
	/*
	vector<vector<char>> board =
	{
		{'A','B','C','E'},
		{'S','F','C','S'},
		{'A','D','E','E'}
	};

	//string word = "SEE";
	//string word = "ABCCED";
	string word = "ABCD";
	*/

	Solution *obj = new Solution();
	std::cout << obj->exist(board, word) << std::endl;

	return 0;
}
