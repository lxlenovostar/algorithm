#include <iostream>
#include <vector>
#include <map>
#include <algorithm> 
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> ret;
		map<string, vector<string>> handle_str;

		if (strs.size() == 0)
			return ret;
		
		for (size_t i = 0; i < strs.size(); ++i) {
			string key = strs[i];
			sort(key.begin(), key.end());
			handle_str[key].push_back(strs[i]);			
		}

		for (auto it = handle_str.begin(); it != handle_str.end(); ++it) {
			ret.push_back(it->second);
		}

		return ret;
    }
};

int main() {
	vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
	Solution *test = new Solution();
	test->groupAnagrams(strs);
}
