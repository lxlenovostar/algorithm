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

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::queue<std::string> tmp_queue_1;
        std::queue<std::string> tmp_queue_2;
        std::set<std::string> checked_node;
        int step = 0;
        tmp_queue_1.push(beginWord);
        ++step;
        while (!tmp_queue_1.empty()) {
            const auto& check_word = tmp_queue_1.front();
            tmp_queue_1.pop();
            if (check_word == endWord)
                return step;

            const auto &neighbors = get_neighbors(check_word, wordList);
            for (const auto& word: neighbors) {
                if (checked_node.find(word) == checked_node.end()) {
                    tmp_queue_2.push(word);
                    checked_node.insert(word);
                }
            }

            if (tmp_queue_1.empty()) {
                ++step;
                std::swap(tmp_queue_1, tmp_queue_2);
            }
        }

        return 0;
    }
};

int main() {
    /*
    std::string beginWord = "hit";
    std::string endWord = "cog";
    std::vector<std::string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    */

    std::string beginWord = "qa";
    std::string endWord = "sq";
    std::vector<std::string> wordList = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};

    Solution *test = new Solution();
    std::cout << test->ladderLength(beginWord, endWord, wordList) << std::endl;
    return 0;
}