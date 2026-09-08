#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& v) {
	for(vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;
}

int main() {
	vector<int> v = {1, 2, 3, 4, 5};
	
	// 1. 函数 pop_back()
	vector<int> v1 = v;
	v1.pop_back();
	cout << "v1: ";
	printVector(v1);
	// v1: 1 2 3 4
	
	// 2. 函数 erase()
	// 删除一个元素
	vector<int> v2 = v;
	v2.erase(v2.begin() + 2);
	cout << "v2: ";
	printVector(v2);
	// v2: 2 3 4 5
	
	// 删除一组元素
	vector<int> v3 = v;
	v3.erase(v3.begin(), v3.end() - 1);
	cout << "v3: ";
	printVector(v3);
	// v3: 5
	
	return 0;
}