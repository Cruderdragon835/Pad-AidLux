#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(vector<int>& v) {
	for(vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;
}

// 基础方法：使用成员函数erase()结合for循环，时间复杂度为O(n²)
void remove1(vector<int>& v, int index) {
	v.erase(v.begin() + index);
}

// 改进方法 1：使用成员函数swap()+pop_back()的组合结合for循环，时间复杂度为O(n)
void remove2(vector<int>& v, int index) {
	swap(v[index], v.back());
	v.pop_back();
}

int main() {
	vector<int> v1;
	cout << "remove1: ";
	for(int i = 0; i < 150006; ++i) {
		v1.push_back(i);
	}
	// 使用基础方法，将指定区间中的数据全部删除
	for(int i = 0; i < 150000; ++i){
		remove1(v1, 4);
	} // 4为区间偏移量
	printVector(v1);
	// remove1: 0 1 2 3 150004 150005
	
	vector<int> v2;
	cout << "remove2: ";
	for(int i = 0; i < 150006; ++i) {
		v2.push_back(i);
	}
	// 使用改进方法 1，将指定区间中的数据全部删除
	for(int i = 0; i < 150000; ++i){
	remove2(v2, 4);
	}
	printVector(v2);
	// remove2: 0 1 2 3 6 5
	
	vector<int> v3;
	cout << "remove3: ";
	for(int i = 0; i < 150006; ++i) {
		v3.push_back(i);
	}
	// 使用改进方法 2，将指定区间中的数据全部删除
	v3.erase(remove_if(v3.begin(), v3.end(), 
		[](int x){return x >= 4 && x < 150004;}), 
		v3.end());
	printVector(v3);
	
	return 0;
}