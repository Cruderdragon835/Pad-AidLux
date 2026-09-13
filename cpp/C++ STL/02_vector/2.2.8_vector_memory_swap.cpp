#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& v) {
	for(vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;
}

int main() {
	vector<int> v1 = {1, 2, 3, 4, 5};
	vector<int> v2 = {9, 8, 7, 6, 5};
	cout << "v1: ";
	printVector(v1);
	cout << "v2: ";
	printVector(v2);
	// v1: 1 2 3 4 5
	// v2: 9 8 7 6 5
	
	// 成员函数swap()需要通过对象调用来实现
	v1.swap(v2);
	
	cout << "v1: ";
	printVector(v1);
	cout << "v2: ";
	printVector(v2);
	// v1: 9 8 7 6 5
	// v2: 1 2 3 4 5
	
	// 标准库函数swap()直接使用就行
	swap(v1, v2);
	
	cout << "v1: ";
	printVector(v1);
	cout << "v2: ";
	printVector(v2);
	// v1: 1 2 3 4 5
	// v2: 9 8 7 6 5
	
	return 0;
}