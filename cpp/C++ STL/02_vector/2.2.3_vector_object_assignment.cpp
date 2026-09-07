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
	// 1. 初始化列表赋值（以下两种写法等价）
	// 1_1. 等号赋值
	vector<int> v1_1 = {9, 8, 5, 2, 1, 1};
	cout << "v1_1: ";
	printVector(v1_1);
	
	// 1_2. 括号赋值
	vector<int> v1_2({9, 8, 5, 2, 1, 1});
	cout << "v1_2: ";
	printVector(v1_2);
	
	// 2. assign(迭代器)赋值
	vector<int> v2;
	v2.assign(v1_1.begin(), v1_1.end());
	cout << "v2: ";
	printVector(v2);
	
	// 3. assign(初始化列表)赋值
	vector<int> v3;
	v3.assign({1, 2, 3, 4, 5, 6});
	cout << "v3: ";
	printVector(v3);
	
	// 4. assign 全 m 赋值
	vector<int> v4;
	v4.assign(8, 3);
	cout << "v4: ";
	printVector(v4);
	// v4: 3, 3, 3, 3, 3, 3, 3, 3
	
	return 0;
}