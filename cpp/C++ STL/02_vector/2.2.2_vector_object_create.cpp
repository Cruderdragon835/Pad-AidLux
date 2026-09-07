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

int main() {
	// 无参默认构造
	vector<int> v;
	cout << "v: ";
	printVector(v);
	// v 后没有任何输出
	
	// 1. 初始化列表初始化（以下两种写法等价）
	// int[a] = {9, 8, 7, 6, 5};
	// 1_1. 等号赋值
	vector<int> v1_1 = {9, 8, 7, 6, 5};
	cout << "v1_1: ";
	printVector(v1_1);
	// v1_1: 9, 8, 7, 6, 5
	
	// 1_2. 括号赋值
	vector<int> v1_2({1, 2, 3, 4, 5}); // 必须写上大括号作为一个整体
	cout << "v1_2: ";
	printVector(v1_2);
	// v1_2: 1, 2, 3, 4, 5
	
	// 2. 拷贝构造函数初始化（以下两种写法等价）
	// 2_1. 等号赋值
	vector<int> v2_1 = v1_1;
	cout << "v2_1: ";
	printVector(v2_1);
	// v2_1: 9, 8, 7, 6, 5
	
	// 2_2. 括号赋值
	vector<int> v2_2(v1_1);
	cout << "v2_2: ";
	printVector(v2_2);
	// v2_2: 9, 8, 7, 6, 5

	// 3. 迭代器初始化
	// 由于迭代器使用左闭右开区间，因此拷贝时截止到 end() 指向的前一位
	vector<int> v3_1(v1_1.begin(), v1_1.end());
	cout << "v3_1: ";
	printVector(v3_1);
	// v3_1: 9, 8, 7, 6, 5

	// 迭代器的两个区间端点可以加减常数进行左右移动，但不能超过数组的区间范围
	vector<int> v3_2(v1_1.begin()+1, v1_1.end()-1);
	cout << "v3_2: ";
	printVector(v3_2);
	// v3_2: 8, 7, 6
	
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
	
	return 0;
}