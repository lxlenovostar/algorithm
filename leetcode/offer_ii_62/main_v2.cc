#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Trie {
private:
    Trie* check(string word) {
        Trie *node = this;

        for (const auto& ch: word) {
            int index = ch - 'a';

            if (node->next[index] == nullptr) {
                return nullptr;
            }

            node = node->next[index];
        }

        return node;
    }
 
public:
    /** Initialize your data structure here. */
    Trie():next(26), is_word(false) {
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *node = this;

        for (const auto& ch: word) {
            int index = ch - 'a';

            if (node->next[index] == nullptr) {
                node->next[index] = new Trie();
            }

            node = node->next[index];
        }

        node->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
       Trie* ret = check(word);

       return ret == nullptr || ret->is_word == false ? false : true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
       Trie* ret = check(prefix);

       return ret == nullptr ? false : true;
    }
private:
    std::vector<Trie*> next; 
    bool is_word;
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