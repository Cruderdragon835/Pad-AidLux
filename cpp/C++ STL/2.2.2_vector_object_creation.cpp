#include <iostream>
#include <vector>
using namespace std;

// 用于逐个输出 vector 元素的函数，使用 for 循环遍历
void printVector(vector<int>& v) { // 函数的引用传参，相比指针传参更有优势
	for(vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << " ";  // 解引用迭代器，并输出其指向的值
	}
	cout << endl;
}

// 用于逐个输出 vector 元素的函数，使用 for 循环遍历
void printVector(vector<int>& v) { // 函数的引用传参，相比指针传参更有优势
	for(vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << " ";  // 解引用迭代器，并输出其指向的值
	}
	cout << endl;
}

int main() {
	// 1. 无参默认构造
	vector<int> v1;
	cout << "v1: ";
	printVector(v1);
	// v1 后没有任何输出
	
	// 2. 初始化列表
	// int[a] = {9, 8, 7, 6, 5};
	vector<int> v2_1 = {9, 8, 7, 6, 5};
	cout << "v2_1: ";
	printVector(v2_1);
	// v2_1: 9, 8, 7, 6, 5
	
	vector<int> v2_2({1, 2, 3, 4, 5}); // 必须写上大括号作为一个整体
	cout << "v2_2: ";
	printVector(v2_2);
	// v2_2: 1, 2, 3, 4, 5
	
	// 3. 迭代器
	// 由于迭代器使用左闭右开区间，因此拷贝时截止到 end() 指向的前一位
	vector<int> v3(v2_1.begin(), v2_1.end());
	cout << "v3: ";
	printVector(v3);
	// v3: 9, 8, 7, 6, 5
	
	// 4. 全 0 初始化
	vector<int> v4(8);
	cout << "v4: ";
	printVector(v4);
	// v4: 0, 0, 0, 0, 0, 0, 0, 0
	
	// 5. 全 m 初始化
	vector<int> v5(8, 3);
	cout << "v5: ";
	printVector(v5);
	// v5: 3, 3, 3, 3, 3, 3, 3, 3
	
	// 6. 调用拷贝构造函数进行初始化
	vector<int> v6(v2_1);
	cout << "v6: ";
	printVector(v6);
	// v6: 9, 8, 7, 6, 5
	
	return 0;
}