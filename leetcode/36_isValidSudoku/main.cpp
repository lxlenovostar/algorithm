/*
判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。


上图是一个部分填充的有效的数独。

数独部分空格内已填入了数字，空白格用 '.' 表示。

示例 1:

输入:
[
  ['5','3','.','.','7','.','.','.','.'],
  ['6','.','.','1','9','5','.','.','.'],
  ['.','9','8','.','.','.','.','6','.'],
  ['8','.','.','.','6','.','.','.','3'],
  ['4','.','.','8','.','3','.','.','1'],
  ['7','.','.','.','2','.','.','.','6'],
  ['.','6','.','.','.','.','2','8','.'],
  ['.','.','.','4','1','9','.','.','5'],
  ['.','.','.','.','8','.','.','7','9']
]
输出: true
示例 2:

输入:
[
  ['8','3','.','.','7','.','.','.','.'],
  ['6','.','.','1','9','5','.','.','.'],
  ['.','9','8','.','.','.','.','6','.'],
  ['8','.','.','.','6','.','.','.','3'],
  ['4','.','.','8','.','3','.','.','1'],
  ['7','.','.','.','2','.','.','.','6'],
  ['.','6','.','.','.','.','2','8','.'],
  ['.','.','.','4','1','9','.','.','5'],
  ['.','.','.','.','8','.','.','7','9']
]
输出: false
解释: 除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。
     但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。
说明:

一个有效的数独（部分已被填充）不一定是可解的。
只需要根据以上规则，验证已经填入的数字是否有效即可。
给定数独序列只包含数字 1-9 和字符 '.' 。
给定数独永远是 9x9 形式的。
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool helper(vector<vector<char>>& board, int i, int j) {
		int rowMax = i + 3;
		int colMax = j + 3;

		std::cout << "i: " << i << " j: " <<  j << std::endl;
		set<char> check_set;
		for (int _i = i ; _i < rowMax; _i++) {
			for (int _j = j; _j < colMax; _j++) {
				//int i = _i % 3;
				//int j = _j % 3;
				int i = _i; 
				int j = _j;
				std::cout << "check i: " << i << " j: " <<  j << std::endl;
				if (board[i][j] != '.' && check_set.find(board[i][j]) != check_set.end()) {
					return false;
				}

				if (board[i][j] != '.') {
					check_set.insert(board[i][j]);
				}

			} // for
		} //for
	
		return true;
	}

    bool isValidSudoku(vector<vector<char>>& board) {
		if (board.size() == 0)
			return true;

		//check row
		for (int i = 0; i < 9; i++) {
			set<char> check_set;
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.' && check_set.find(board[i][j]) != check_set.end()) {
					return false;
				}

				if (board[i][j] != '.') {
					check_set.insert(board[i][j]);
				}
			} // for
		} // for

		//check col 
		for (int i = 0; i < 9; i++) {
			set<char> check_set;
			for (int j = 0; j < 9; j++) {
				if (board[j][i] != '.' && check_set.find(board[j][i]) != check_set.end()) {
					return false;
				}

				if (board[j][i] != '.') {
					check_set.insert(board[j][i]);
				}
			} // for
		} // for

		//check 3*3

		for (int i = 0; i < 9; i+=3) {
			for (int j = 0; j < 9; j+=3)  {
				bool ret = helper(board, i, j);	
				if (ret == false)
					return false;
			}	
		}


		return true;
    }
};

int main() {
	/*vector<vector<char>> nums =	
	{
		{'8','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}
	};
	*/

	vector<vector<char>> nums =	
	{
			{'.','.','.','.','5','.','.','1','.'},
			{'.','4','.','3','.','.','.','.','.'},
			{'.','.','.','.','.','3','.','.','1'},
			{'8','.','.','.','.','.','.','2','.'},
			{'.','.','2','.','7','.','.','.','.'},
			{'.','1','5','.','.','.','.','.','.'},
			{'.','.','.','.','.','2','.','.','.'},
			{'.','2','.','9','.','.','.','.','.'},
			{'.','.','4','.','.','.','.','.','.'}
	};	

	Solution *obj = new Solution();
	std::cout << obj->isValidSudoku(nums) << std::endl;

	return 0;
}

