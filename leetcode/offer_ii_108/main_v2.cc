#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

class Solution {
private:
    std::vector<std::string> get_neighbors(const std::string& word, const vector<string>& wordList) {
        std::vector<std::string> ret_neighbors;

        for (const auto& neighbor: wordList) {
            size_t obj = neighbor.size() - 1;
            size_t equal_num = 0;
            for (size_t i = 0; i < neighbor.size(); ++i) {
                if (neighbor[i] == word[i]) {
                    ++equal_num;
                }
            }

            if (equal_num == obj) {
                ret_neighbors.push_back(neighbor);
            }
        }

        return ret_neighbors;
    }
    
    bool check_end(const std::string& word, const vector<string>& wordList) {
        for (const auto& item: wordList) {
            if (word == item)
                return true;
        }

        return false;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::queue<std::string> tmp_queue_begin;
        std::queue<std::string> tmp_queue_end;
        std::set<std::string> checked_node_begin; 
        std::set<std::string> checked_node_end; 
        std::queue<std::string> next_queue_begin;
        std::queue<std::string> next_queue_end;

        if (check_end(endWord, wordList) == false)
            return 0;

        tmp_queue_begin.push(beginWord);
        tmp_queue_end.push(endWord);
        int step = 2;
        while (!tmp_queue_begin.empty() || !tmp_queue_end.empty()) {

            const auto& check_word = tmp_queue_begin.front();
            tmp_queue_begin.pop();
            if (check_word == endWord)
                return step;

            const auto &neighbors = get_neighbors(check_word, wordList);
            for (const auto& word: neighbors) {
                if (checked_node_begin.find(word) == checked_node_begin.end()) {
                    std::cout << "what1 " << word <<  " step:" << step <<  std::endl;
                    next_queue_begin.push(word);
                    std::cout << "what3 " << word << "\n";
                    checked_node_begin.insert(word);
                }
                if (checked_node_end.find(word) != checked_node_end.end()) {
                    std::cout << "what6 " << "\n";
                    return step+1;
                }
            }
 
            const auto& check_end_word = tmp_queue_end.front();
            tmp_queue_end.pop();
            if (check_end_word == beginWord)
                return step;

            const auto &end_neighbors = get_neighbors(check_end_word, wordList);
            for (const auto& word: end_neighbors) {
                if (checked_node_end.find(word) == checked_node_end.end()) {
                    std::cout << "what2 " << word <<  " step:" << step <<  std::endl;
                    next_queue_end.push(word);
                    std::cout << "what4 " << word << "\n";
                    checked_node_end.insert(word);
                }
                if (checked_node_begin.find(word) != checked_node_begin.end()) {
                    std::cout << "what7 " << "\n";
                    return step+1;
                }
            }

            std::cout << "next begin: " << next_queue_begin.size() << std::endl;
            std::cout << "next end: " << next_queue_end.size() << std::endl;
   
            if (tmp_queue_begin.empty()) {
                std::swap(next_queue_begin, tmp_queue_begin);
                ++step;
            }

            if (tmp_queue_end.empty()) {
                std::swap(next_queue_end, tmp_queue_end);
                ++step;
            }
            
            std::cout << "tmp begin: " << tmp_queue_begin.size() << std::endl;
            std::cout << "tmp end: " << tmp_queue_end.size() << std::endl;
        }

        return 0;
    }
};

int main() {
    /*
    std::string beginWord = "hit";
    std::string endWord = "cog";
    std::vector<std::string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    std::string beginWord = "qa";
    std::string endWord = "sq";
    std::vector<std::string> wordList = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
    */

    std::string beginWord = "hit";
    std::string endWord = "cog";
    std::vector<std::string> wordList = {"hot","dot","dog","lot","log"};

    Solution *test = new Solution();
    std::cout << test->ladderLength(beginWord, endWord, wordList) << std::endl;
    return 0;
}