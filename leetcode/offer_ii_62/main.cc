#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Trie {
private:
    struct element {
        bool is_word;
    
        std::vector<struct element*> next; 
    };

    struct element source;

    void dfs(string word, int& index, struct element *root) {
        if (index > word.size()-1)
            return;
        
        if (root->next[word[index] - 'a'] == nullptr) {
            element *new_element = new element();
            new_element->next.resize(26, nullptr);
            //std::cout << "index: " << index << std::endl;
            root->next[word[index] - 'a'] = new_element;
        } 
        
        if (index == word.size() -1) {
            root->is_word = true;
            return;
        }

        dfs(word, ++index, root->next[word[index] - 'a']);
    }
 
    bool check_dfs(string word, int& index, struct element *root) {
        if (index > word.size()-1)
            return true;
        
        if (root->next[word[index] - 'a'] == nullptr) {
            return false;
        } else {
            return check_dfs(word, ++index, root->next[word[index] - 'a']);
        }
    }
  
    bool find_dfs(string word, int& index, struct element *root) {
        if (index > word.size()-1)
            return false;
        

        if (root->next[word[index] - 'a'] == nullptr) {
            return false;
        } else {
            //std::cout << "fuck find index:" << index << " is_word:" << root->is_word << std::endl;
            if (index == word.size() -1 && root->is_word) {
                return true;
            } else {
                return find_dfs(word, ++index, root->next[word[index] - 'a']);
            }
        }
    }



public:
    /** Initialize your data structure here. */
    Trie() {
        source.is_word = false;
        source.next.resize(26, nullptr);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int start = 0;
        dfs(word, start, &source);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int start = 0;
        return find_dfs(word, start, &source);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int start = 0;
        return check_dfs(prefix, start, &source);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 */
int main() {
    Trie* obj = new Trie();
    obj->insert("googlebyte");
    bool param_2 = obj->search("goog");
    std::cout << param_2 << std::endl;
    bool param_3 = obj->startsWith("goog");
    std::cout << param_3 << std::endl;
    obj->insert("goog");
    param_2 = obj->search("goog");
    std::cout << param_2 << std::endl;
    return 0;
}