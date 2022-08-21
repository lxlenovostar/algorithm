#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    std::map<int, int> point_color;

    void helper(vector<vector<int>>& graph, int index, bool& ret, int color) {

        point_color[index] = color;

        for (const auto&  neighbor: graph[index]) {
            if (point_color[neighbor] == -1) {
                helper(graph, neighbor, ret, 1-color);
                if (!ret) 
                    return;
            } else {
                if (color == point_color[neighbor]) {
                    ret = false;
                    return;
                }
            }
        }

    }

    bool isBipartite(vector<vector<int>>& graph) {
        if (graph.size() == 0) {
            return false;
        }

        for (int i = 0; i < graph.size(); ++i) {
            point_color.insert(std::make_pair(i, -1));
        }

        bool ret = true;

        for (int i = 0; i < graph.size(); ++i) {
            if (point_color[i] == -1) {
                helper(graph, i, ret, 0);
                if (!ret) {
                    return ret;
                }
            }
        }

        return ret;
    }
};

int main()
{
    vector<vector<int>> graph = {{1,2,3}, {0,2}, {0,1,3}, {0,2}};
    //vector<vector<int>> graph = {{1,3}, {0,2}, {1,3}, {0,2}};
    Solution *test = new Solution();
    std::cout << test->isBipartite(graph) << std::endl;
    return 0;
}