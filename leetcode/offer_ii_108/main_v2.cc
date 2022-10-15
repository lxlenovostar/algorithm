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
        std::set<std::string> no_visited_node(wordList.begin(), wordList.end());
       
        if (no_visited_node.find(endWord) == no_visited_node.end()) {
            return 0;
        }
        
        std::set<std::string> set_1;
        std::set<std::string> set_2;
        int length = 2;

        set_1.insert(beginWord);
        set_2.insert(endWord);

        while (!set_1.empty() && !set_2.empty()) {
            // 从节点少的开始
            if (set_2.size() < set_1.size()) {
                std::swap(set_2, set_1);
            }
        
            std::set<std::string> set_3;

            for (const auto& item : set_1) {
                const auto &neighbors = get_neighbors(item, wordList);
                    for (const auto& word: neighbors) {
                        if (set_2.find(word) != set_2.end()) {
                            return length;
                        }

                        if (no_visited_node.find(word) != no_visited_node.end()) {
                            no_visited_node.erase(word);
                            set_3.insert(word);
                        }

                    }
            }

            std::swap(set_1, set_3);
            ++length;
        }

        return 0;
    }
};

int main() {
    std::string beginWord = "hit";
    std::string endWord = "cog";
    std::vector<std::string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    /*
    std::string beginWord = "qa";
    std::string endWord = "sq";
    std::vector<std::string> wordList = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};

    std::string beginWord = "hit";
    std::string endWord = "cog";
    std::vector<std::string> wordList = {"hot","dot","dog","lot","log"};
    */

    Solution *test = new Solution();
    std::cout << test->ladderLength(beginWord, endWord, wordList) << std::endl;
    return 0;
}