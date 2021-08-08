#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		void rotate_1(vector<vector<int>>& matrix) {
			auto new_matrix = matrix;

			size_t len = matrix.size();

			for (size_t i = 0; i < matrix.size(); ++i) {
				for (size_t j = 0; j < matrix[i].size(); ++j) {
					new_matrix[j][(len - i - 1)] = matrix[i][j];
				}
			}

			matrix = new_matrix;
			return;
	   }
	
	 void swap(int &a, int &b) {
	 	int tmp = b;
		b = a;
		a = tmp;
	 } 
		
	  void rotate(vector<vector<int>>& matrix) {
		/*
		 * (i, j)  <==> (len - i - 1, j)
		 * */

		size_t len = matrix.size();
		for (size_t i = 0; i < len/2; ++i) {
			for (size_t j = 0; j < len; ++j) {
				std::cout << "x: " << (len - i -1) << " ==>" << i << " y: " << (j) << " ==>" << j << std::endl;
				swap(matrix[len - i - 1][j], matrix[i][j]);		
			}	
		}  

		/* debug */
		/*
		for (size_t i = 0; i < matrix.size(); ++i) {
			for (size_t j = 0; j < matrix[i].size(); ++j) {
				std::cout << matrix[i][j] << " ";
			}
			std::cout << std::endl;
		}
		*/
			
		/*
		 * (i, j) <==> (j, i)
		 * */
		for (size_t i = 0; i < len; ++i) {
			for (size_t j = 0; j < i ; ++j) {
				std::cout << "x: " << (j) << " ==>" << i << " y: " << (i) << " ==>" << j << std::endl;
				swap(matrix[j][i], matrix[i][j]);		
			}	
		}  

		/* debug */
		/*
		for (size_t i = 0; i < matrix.size(); ++i) {
			for (size_t j = 0; j < matrix[i].size(); ++j) {
				std::cout << matrix[i][j] << " ";
			}
			std::cout << std::endl;
		}
		*/
		

	  }
};

int main() {
	//vector<vector<int>> matrix = {{1,2}, {3,4}};
	//vector<vector<int>> matrix = {{5,1,9,11}, {2,4,8,10}, {13,3,6,7}, {15,14,12,16}};
	//vector<vector<int>> matrix = {{1,2,3,4}, {5,6,7,8}, {9, 10, 11, 12}};
	vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};

	Solution *test = new Solution();
	test->rotate(matrix);

	/*
	for (size_t i = 0; i < matrix.size(); ++i) {
		for (size_t j = 0; j < matrix[i].size(); ++j) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	*/

}
