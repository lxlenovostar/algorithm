#include <queue>
#include <iostream>

using namespace std;

class MovingAverage {
private:
    int m_size;
    std::queue<int> m_queue;
    double m_sum;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        m_size = size;
        m_sum = 0.0;
    }
    
    double next(int val) {
        m_queue.push(val);

        if (m_queue.size() > m_size) {
            int del_val = m_queue.front();
            m_sum -= del_val;
            m_queue.pop();
        }

        m_sum += val;

        return m_sum/m_queue.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 */
int main() {
    MovingAverage* obj = new MovingAverage(3);
    double param = obj->next(1);
    std::cout << param << std::endl;
    param = obj->next(10);
    std::cout << param << std::endl;
    param = obj->next(3);
    std::cout << param << std::endl;
    param = obj->next(5);
    std::cout << param << std::endl;
    return 0;
}