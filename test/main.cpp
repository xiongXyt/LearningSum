#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	vector<string>v;
	v.push_back("123");
	v.push_back("1234");
	v.push_back("12345");

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	// 向指定位置插入元素
	v.insert(v.begin(), "123456");
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	cout << "*************" << endl;
	int n[10] = { 0 };
	for (auto elem : n) {
		cout << elem << endl;
	}

	return 0;
}

