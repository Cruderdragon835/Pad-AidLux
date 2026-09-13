#include <iostream>
using namespace std;
int main() {
	int x = 7;
	float y1 = 3.0;
	float y2 = 3.0;
	float z = -1;
	
	auto p1 = [x, y1](int a, int b)->float {
		return x*y1 + a*b;
	};
	cout << p1(10, 20) << endl;
	// 输出：221
	y1+=1.5;
	cout << p1(10, 20) << endl;
	// 输出：221

	auto p2 = [&x, &y2](int a, int b)->float {
		return x*y2 + a*b;
	};
	cout << p2(10, 20) << endl;
	// 输出：221
	y2+=1.5;
	cout << p2(10, 20) << endl;
	// 输出：231.5
	
	return 0;
}