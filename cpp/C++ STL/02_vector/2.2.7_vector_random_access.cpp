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
	vector<int> v = {9, 8, 7, 6, 5};
	cout << "v[2] = " << v[2] << endl;
	cout << "v.at(2) = " << v.at(2) << endl;
	// v[2] = 7
	// v.at(2) = 7
	
	// cout << v[12] << endl;
	// cout << v.at(12) << endl;
	// 面对两种越界情况，只有使用函数 at() 访问时报错并退出，而使用方括号访问单纯只是没有任何输出，并未报错。
	
	cout << "front: " << v.front() << endl;
	cout << "back: " << v.back() << endl;
	// front: 9
	// back: 5
	
	return 0;
}