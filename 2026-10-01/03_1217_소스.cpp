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
#include<ranges>
#include<algorithm>

using namespace std;

default_random_engine dre;
uniform_int_distribution uid{ 1, 99999};
const int NUM{ 1000000 };

int a[NUM];

void change(int*, int*);

int main() {


	//a의 값을 1부터 NUM까지 int값으로 assign 한다
	for (int i = 0; i < NUM; ++i) {
		a[i] = uid(dre);
	}

	sort(begin(a), end(a));

	for (int num : a | views::take(100))
		print("{:8}", num);
	cout << endl;
	save("소스.cpp");


}

void change(int* p, int* q) {
	int temp{ *p };
	*p = *q;
	*q = temp;
}
