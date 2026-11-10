/*
------------------------------------------
2026. 2 화 34목34		화34  (3주 1일)
------------------------------------------
자료형과 변수
------------------------------------------
*/


#include<iostream>
#include<random>
#include<print>
#include "save.h"

using namespace std;
default_random_engine dre;
uniform_int_distribution uid{ 1'999'9999 };


int compare(const void*, const void*); //비교할 숫자를 받는건 비효율적. 해당 숫자의 주소지를 받아야됨. 그런데 quicksort입장에서 compare에 인자로 뭘 넣을지 모른다고, 그래서 void를 쓴다.

int main() {
	save("소스.cpp");
	
	//[문제] 1억 이하의 자연수를 한개 입력받아
	//입력한 개수만큼 int 메모리를 확보하라
	//각 int 값을 [1,999'9999] 사이의 랜덤값으로 할당하라
	//앞에서 부터 100개, 뒤에서 역순으로 100개를 화면에 출력하라

	size_t num;
	cin >> num;
	
	int* p;
	p = new int[num];

	for (int i = 0; i < num; ++i){
		p[i] = uid(dre);
	}

	for (int i = 0; i < 100; ++i) {
		print("{:8}", p[i]);
	}

	cout << endl;
	cout << endl;

	for (int i = num-1;  i > num-1- 100; --i) {
		print("{:8}", p[i]);
	}


	cout << "정렬시작";

	qsort(p, num, sizeof(int), compare);
	cout << endl;

	cout << "정렬 후 결과";
	for (int i = 0; i < 100; ++i) {
		print("{:8}", p[i]);
	}

	cout << endl;
	cout << endl;

	for (int i = num - 1; i > num - 1 - 100; --i) {
		print("{:8}", p[i]);
	}
}

int compare(const void* p, const void* q)
{
	//int* a = (int*)p;
	//int* b = (int*)q;
	//를 역참조하면
	int a = *(int*)p;
	int b = *(int*)q;

	if (a > b)
		return 1;
	else if(a<b)
		return -1;
	
	return 0;
}
