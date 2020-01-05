/*
实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。

示例:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // 返回 true
trie.search("app");     // 返回 false
trie.startsWith("app"); // 返回 true
trie.insert("app");   
trie.search("app");     // 返回 true

说明:

你可以假设所有的输入都是由小写字母 a-z 构成的。
保证所有输入均为非空字符串。
*/

#include <map>
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

int main() {
 	Trie* obj = new Trie();
 	obj->insert("apple");
	std::cout << obj->search("apple") << std::endl;
	std::cout << obj->startsWith("app") << std::endl;
	std::cout << obj->search("app") << std::endl;
 	obj->insert("app");
	std::cout << obj->search("app") << std::endl;

 	return 0;
}

