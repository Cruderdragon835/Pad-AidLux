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
	vector<int> v1 = {1, 2, 3, 4, 5};
	vector<int> v2 = {9, 8, 7, 6, 5};
	cout << "v1: ";
	printVector(v1);
	cout << "v2: ";
	printVector(v2);
	
	return 0;
}