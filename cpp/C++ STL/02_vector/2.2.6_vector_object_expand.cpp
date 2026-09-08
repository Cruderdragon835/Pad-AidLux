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
	// 1.vector对象扩容现象实验
	vector<int> v1;
	cout << "v1: size = " << v1.size() << endl;
	cout << "v1: capacity = " << v1.capacity() << endl;
	// v1: size = 0
	// v1: capacity = 0
	// 一个未经初始化的vector对象，大小和容量都是0
	
	v1 = {9, 8, 7, 6};
	printVector(v1);
	cout << "v1: size = " << v1.size() << endl;
	cout << "v1: capacity = " << v1.capacity() << endl;
	// v1: 9, 8, 7, 6
	// v1: size = 4
	// v1: capacity = 4
	
	v1.push_back(3); // 插入一个元素3
	cout << "v1: size = " << v1.size() << endl;
	cout << "v1: capacity = " << v1.capacity() << endl;
	// MSVC: v1: size = 5 v1: capacity = 6 (4*1.5=6)
	// GCC: size = 5 v1: capacity = 8 (4*2=8)
	// 若采用MSVC编译器，则默认扩容系数为1.5。若采用GCC编译器，则默认扩容系数为2。
	
	v1.push_back(1);
	cout << "v1: size = " << v1.size() << endl;
	cout << "v1: capacity = " << v1.capacity() << endl;
	// MSVC: v1: size = 6 v1: capacity = 6
	// GCC: size = 6 v1: capacity = 8
	
	v1.push_back(2);
	cout << "v1: size = " << v1.size() << endl;
	cout << "v1: capacity = " << v1.capacity() << endl;
	// MSVC: v1: size = 7 v1: capacity = 9 (6*1.5=9)
	// GCC: v1: size = 7 v1: capacity = 8
	
	for(int i = 0; i < 3; i++) {
		v1.push_back(i);
	}
	cout << "v1: size = " << v1.size() << endl;
	cout << "v1: capacity = " << v1.capacity() << endl;
	// MSVC: v1: size = 10 v1: capacity = 13 (9*1.5=13.5，向下取整为13)
	// GCC: v1: size = 10 v1: capacity = 16 (8*2=16)
	
	// 2.vector容量控制
	// 01.函数reserve()
	vector<int> v2_1;
	cout << "v2_1: size = " << v2_1.size() << endl;
	cout << "v2_1: capacity = " << v2_1.capacity() << endl;
	// v2_1: size = 0
	// v2_1: capacity = 0
	
	v2_1.reserve(5);
	cout << "v2_1: size = " << v2_1.size() << endl;
	cout << "v2_1: capacity = " << v2_1.capacity() << endl;
	// v2_1: size = 0
	// v2_1: capacity = 5
	
	// 02.函数resize()
	vector<int> v2_2 = {1, 2, 3, 4};
	cout << "v2_2: size = " << v2_2.size() << endl;
	cout << "v2_2: capacity = " << v2_2.capacity() << endl;
	// v2_2: size = 4
	// v2_2: capacity = 4
	
	v2_2.resize(10); // 新的容量n>size，触发扩容
	cout << "v2_2: size = " << v2_2.size() << endl;
	cout << "v2_2: capacity = " << v2_2.capacity() << endl;
	// v2_2: size = 10
	// v2_2: capacity = 10
	// resize()让容量capacity刚好扩容到size的大小，不会像push_back()引发的倍数扩容一样浪费内存资源
	
	v2_2.resize(3); // 现在新的容量n<size，进行缩容
	cout << "v2_2: size = " << v2_2.size() << endl;
	cout << "v2_2: capacity = " << v2_2.capacity() << endl;
	// v2_2: size = 3
	// v2_2: capacity = 10
	
	// 03.函数shrink_to_fit()
	vector<int> v2_3;
	v2_3.reserve(10);
	cout << "v2_3: size = " << v2_3.size() << endl;
	cout << "v2_3: capacity = " << v2_3.capacity() << endl;
	// v2_3: size = 0
	// v2_3: capacity = 10
	
	v2_3 = {1, 2, 3, 4};
	cout << "v2_3: size = " << v2_3.size() << endl;
	cout << "v2_3: capacity = " << v2_3.capacity() << endl;
	// v2_3: size = 4
	// v2_3: capacity = 10
	
	v2_3.shrink_to_fit();
	cout << "v2_3: size = " << v2_3.size() << endl;
	cout << "v2_3: capacity = " << v2_3.capacity() << endl;
	// v2_3: size = 4
	// v2_3: capacity = 4
	
	return 0;
}