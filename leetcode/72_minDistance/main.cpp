/*
给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符

示例 1:

输入: word1 = "horse", word2 = "ros"
输出: 3
解释: 
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')

示例 2:

输入: word1 = "intention", word2 = "execution"
输出: 5
解释: 
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')


在真实的面试中遇到过这道题？
*/

/*
public int minDistance(String word1, String word2) { 
	int n1 = word1.length(); 
	int n2 = word2.length(); 
	
	int[][] dp = new int[n1 + 1][n2 + 1]; 
	
	// dp[0][0...n2]的初始值 
	for (int j = 1; j <= n2; j++)  
		dp[0][j] = dp[0][j - 1] + 1; 
		
	// dp[0...n1][0] 的初始值
	for (int i = 1; i <= n1; i++) 
		dp[i][0] = dp[i - 1][0] + 1; 
		
	// 通过公式推出 dp[n1][n2] 
	for (int i = 1; i <= n1; i++) { 
		for (int j = 1; j <= n2; j++) {
 			// 如果 word1[i] 与 word2[j] 相等。第 i 个字符对应下标是 i-1
 			if (word1.charAt(i - 1) == word2.charAt(j - 1)){
 				p[i][j] = dp[i - 1][j - 1];
 			}else {
 				dp[i][j] = Math.min(Math.min(dp[i - 1][j - 1], dp[i][j - 1]), dp[i - 1][j]) + 1;
 			} 
 		}
 	}

 	return dp[n1][n2]; 
}
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
    	int n1 = word1.size(); 
		int n2 = word2.size();

		vector<vector<int>> dp;
		dp.resize(n1+1);

		for (int i = 0; i < (n1 + 1); ++i) {
			dp[i].resize(n2+1);
		}

		for (int j = 1; j <= n2; j++)  
			dp[0][j] = dp[0][j - 1] + 1; 

		for (int i = 1; i <= n1; i++) 
			dp[i][0] = dp[i - 1][0] + 1; 

		for (int i = 1; i <= n1; ++i)
			for (int j = 1; j <= n2; ++j) {
				if (word1[i-1] == word2[j-1])
					dp[i][j] = dp[i-1][j-1];
				else {
					dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
					dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
					dp[i][j] += 1;
				}
			
			}

		return  dp[n1][n2];
    }
};

int main() {

	string word1 = "horse";
	string word2 = "ros";

	Solution *obj = new Solution();
	std::cout << obj->minDistance(word1, word2) << std::endl;

	return 0;
}

