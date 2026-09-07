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
	// 1. 函数 push_back()
	// 从末尾依次插入元素
	vector<int> v1;
	for(int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	cout << "v1: ";
	printVector(v1);
	// v1: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
	
	// 2. 函数 insert()
	// 插入值
	vector<int> v2_1;
	v2_1.insert(v2_1.begin(), 2);
	cout << "v2_1: ";
	printVector(v2_1);
	// v2_1: 2
	
	// 插入初始化列表
	vector<int> v2_2;
	v2_2.insert(v2_2.begin(), {2, 3, 4, 5});
	cout << "v2_2: ";
	printVector(v2_2);
	// v2_2: 2 3 4 5
	
	// 插入多个值
	vector<int> v2_3;
	v2_3.insert(v2_3.begin(), 4, 3); // 在指定位置插入4个3
	cout << "v2_3: ";
	printVector(v2_3);
	// v2_3: 3 3 3 3
	
	// 插入另一个 vector 对象中的元素
	vector<int> v2_4;
	v2_4.insert(v2_4.begin(), v1.begin() + 1, v1.end() - 3);
	cout << "v2_4: ";
	printVector(v2_4);
	// v2_4: 1 2 3 4 5 6
	
	// 插入数组
	vector<int> v2_5;
	int arr[4] = {1, 2, 3, 4};
	v2_5.insert(v2_5.begin(), arr, arr + 3);
	cout << "v2_5: ";
	printVector(v2_5);
	// v2_5: 1 2 3
	
	return 0;
}