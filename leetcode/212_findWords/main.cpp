/*
给定一个二维网格 board 和一个字典中的单词列表 words，找出所有同时在二维网格和字典中出现的单词。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。

示例:

输入: 
words = ["oath","pea","eat","rain"] and board =
[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]

输出: ["eat","oath"]
说明:
你可以假设所有输入都由小写字母 a-z 组成。

提示:

你需要优化回溯算法以通过更大数据量的测试。你能否早点停止回溯？
如果当前单词不存在于所有单词的前缀中，则可以立即停止回溯。什么样的数据结构可以有效地执行这样的操作？散列表是否可行？为什么？ 前缀树如何？如果你想学习如何实现一个基本的前缀树，请先查看这个问题： 实现Trie（前缀树）。
*/

#include <map>
#include <set>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct Node {
	map<char, Node*> node; 
	map<char, bool> flag; 
};


class Trie {
public:
	Node root;
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
		Node *current = &root;
		for (size_t i = 0; i < word.size(); i++) {

			if (current->node.find(word[i]) == current->node.end()) {
				Node *next = new Node();
				current->node[word[i]] = next;

				if (i+1 == word.size())
					current->flag[word[i]] = true;

				current = next;
			} else {
				if (i+1 == word.size())
					current->flag[word[i]] = true;

				current = current->node[word[i]];
			} // if 
		
		} // for


    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
    	Node *current = &root;
		for (size_t i = 0; i < word.size(); i++) {
			if (current->node.find(word[i]) == current->node.end()) {
				return false;
			} else {
				if (i+1 == word.size() && current->flag[word[i]] == true)
					return true;

				current = current->node[word[i]];

			} // if 
		
		} // for

		return false;
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
     	Node *current = &root;
		for (size_t i = 0; i < prefix.size(); i++) {
			if (current->node.find(prefix[i]) == current->node.end()) {
				return false;
			} else {
				if (i+1 == prefix.size() && current->flag[prefix[i]] == false)
					return true;

				current = current->node[prefix[i]];
			} // if 
		
		} // for

		return true;
        
    }
};


class Solution {
public:
	vector<string> result;
	set<string> result_check;
	int N;
	int M;

	void checker(vector<vector<char>>& board, int begin_i, int begin_j, Trie* t_obj, string str, vector<vector<int>> &key) {
		string new_str = str + board[begin_i][begin_j];

		if (t_obj->search(new_str) == true) {
			std::cout << "what1 new_str: " << new_str << std::endl;
			if (result_check.find(new_str) == result_check.end()) {
				result.push_back(new_str);
				result_check.insert(new_str);
			}
			//return ;
		}
		
		if (t_obj->startsWith(new_str) == false) {
			std::cout << "what2 new_str: " << new_str << std::endl;
			return ;
		} else {
			key[begin_i][begin_j] = 1;
			
			std::cout << "what2.1 new_str: " << new_str << std::endl;

			if (begin_i+1 < N && key[begin_i+1][begin_j] != 1) { 
				checker(board, begin_i+1, begin_j, t_obj, new_str, key);	
			}

			if (begin_i-1 >= 0 && key[begin_i-1][begin_j] != 1)  {
				checker(board, begin_i-1, begin_j, t_obj, new_str, key);	
			}

			if (begin_j+1 < M && key[begin_i][begin_j+1] != 1) { 
				checker(board, begin_i, begin_j+1, t_obj, new_str, key);	
			}
			
			std::cout << "what2.2 begin_i: " << begin_i << " begin_j: " << begin_j << std::endl;

			if (begin_j-1 >= 0 && key[begin_i][begin_j-1] != 1) { 
				checker(board, begin_i, begin_j-1, t_obj, new_str, key);	
			}
			
			key[begin_i][begin_j] = 0;

		}

		return ;
	}

	void helper(vector<vector<char>>& board, Trie* trie_obj) {

		vector<vector<int>> key_map(N, vector<int>(M, 0));
		for (size_t i = 0; i < board.size(); ++i)	{
			for (size_t j = 0; j < board[i].size(); ++j) {
					string str("");
					std::cout << "what.02" << std::endl;

					checker(board, i, j, trie_obj, str, key_map);
			
			} //for j
		} // for i	

	}

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		N = board.size();
		M = board[0].size();

 		Trie* trie_obj = new Trie();

		for (size_t i = 0; i < words.size(); ++i) {
			//std::cout << "what.02" << std::endl;
 			trie_obj->insert(words[i]);

		}
		
		helper(board, trie_obj);	

		return result;
        
    }
};

int main() {
	/*vector<string> words = {"oath","pea","eat","rain"};
	//vector<string> words = {"oath"};
	vector<vector<char>> board =
	{	
		{'o','a','a','n'},
		{'e','t','a','e'},
		{'i','h','k','r'},
		{'i','f','l','v'}
	};
	*/

	/*
	vector<string> words = {"a"};
	vector<vector<char>> board =
	{	
		{'a', 'a'}
	};
	*/
	
	vector<string> words = {"aaa", "aaab"};
	vector<vector<char>> board =
	{	
		{'a', 'b'},
		{'a', 'a'}
	};
	
	Solution *obj = new Solution();
	vector<string> ret = obj->findWords(board, words);

	for (size_t i = 0; i < ret.size(); i++) {
		std::cout << ret[i] << std::endl;
	}


	/*
 	Trie* obj = new Trie();
 	obj->insert("apple");
	std::cout << obj->search("apple") << std::endl;
	std::cout << obj->startsWith("app") << std::endl;
	std::cout << obj->search("app") << std::endl;
 	obj->insert("app");
	std::cout << obj->search("app") << std::endl;
	*/

 	return 0;
}

