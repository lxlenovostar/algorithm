#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool isIpAddressItem(const std::string& str, int begin, int end) {
        std::string ip = str.substr(begin, end - begin +1);
        if (ip.size() >= 2 && ip[0] == '0')
            return false;
        int ip_num = std::atoi(ip.c_str());
        if (ip_num > 255 || ip_num < 0)
            return false;
        return true;
    }

    void helper(const std::string& str, int index, std::vector<std::string> ip_address, vector<string>& result) {
        if (ip_address.size() > 4)
            return ;
        if (index == str.size() && ip_address.size() == 4) {
            result.emplace_back(ip_address[0]+"."+ip_address[1]+"."+ip_address[2]+"."+ip_address[3]);
        } else {
            for (int j = index; j < str.size(); ++j) {
                if (isIpAddressItem(str, index, j)) {
                    ip_address.emplace_back(str.substr(index, j - index + 1));
                    helper(str, j+1, ip_address, result);
                    ip_address.pop_back();
                }
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;

        if (s.size() > 12)
            return ret;
        vector<string> ip_address;
        helper(s, 0, ip_address, ret);
        return ret;
    } 
    
};

int main() {
    Solution *test = new Solution();

    for (const auto& item: test->restoreIpAddresses("1111")) {
        std::cout << item << std::endl;
    }
    return 0;
}