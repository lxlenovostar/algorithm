/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

#include <iostream>
#include <queue>
using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
		vector<int>::iterator ptr;

		for (ptr = nums.begin(); ptr < nums.end(); ptr++) 
			heap.push(*ptr);

		h_len = k;

		while (heap.size() > h_len) {
			heap.pop();
		}
    }
    
    int add(int val) {
		if (heap.size() < h_len) 
			heap.push(val);
		else  {
			if (val > heap.top()) {
				heap.pop();
				heap.push(val);
			}
		}
		
		int ret = heap.top();

		return ret;
    }

	int top() {
			return heap.top();
	}

private:
    priority_queue<int, std::vector<int>, std::greater<int> > heap;
	size_t      h_len;
};

int main()
{
	int k = 3;
	std::vector<int> nums = {4,5,8,2};
 	KthLargest* obj = new KthLargest(k, nums);
	std::cout << obj->top() <<  std::endl;
 	int param_1 = obj->add(3);
	std::cout << param_1 <<  std::endl;
 	param_1 = obj->add(5);
	std::cout << param_1 <<  std::endl;
 	param_1 = obj->add(10);
	std::cout << param_1 <<  std::endl;
 	param_1 = obj->add(9);
	std::cout << param_1 <<  std::endl;
 	param_1 = obj->add(4);
	std::cout << param_1 <<  std::endl;

	/*
    priority_queue<float, std::vector<float>, std::greater<float> > q;
    // insert three elements into the priority queue
    q.push(66.6);
    q.push(22.2);
    q.push(44.4);

    // read and print two elements
    cout << q.top() << ' ';
    q.pop();
    cout << q.top() << endl;
    q.pop();

    // insert three more elements
    q.push(11.1);
    q.push(55.5);
    q.push(33.3);

    // skip one element
    q.pop();

    // pop and print remaining elements
    while (!q.empty()) {
        cout << q.top() << ' ';
        q.pop();
    }
    cout << endl;
	*/
	
	return 0;
}
