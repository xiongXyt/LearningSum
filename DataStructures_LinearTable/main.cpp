#include"Array.h"
#include<iostream>
using namespace std;

int main() {
	int num=10;
	Array arr(num, 2);
	arr.AddArrayIndex(10, 2);
	arr.AddArrayIndex(10, 3);
	arr.PintArray();
	arr.DeletrAllNumArray(10);
	arr.PintArray();
	
	// �ڴ��ͷ�ʱ����������

	return 0;
}
