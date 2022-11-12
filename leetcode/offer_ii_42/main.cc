#include <queue>
#include <iostream>

using namespace std;

const int interval = 3000;
class RecentCounter {
private:
    std::queue<int> m_queue;
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        m_queue.push(t);

        while (!m_queue.empty()) { 
            int old = m_queue.front();
            if ((t - old) > interval) {
                m_queue.pop();
            } else {
                break;
            } 
        }

        return m_queue.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 */
int main() {
    RecentCounter* obj = new RecentCounter();
    int param = obj->ping(642);
    std::cout << param << std::endl;
    param = obj->ping(1849);
    std::cout << param << std::endl;
    param = obj->ping(4921);
    std::cout << param << std::endl;
    param = obj->ping(5936);
    std::cout << param << std::endl;
    param = obj->ping(5957);
    std::cout << param << std::endl;

    return 0;
}