/*
------------------------------------------
2026. 2 화 34목34		화34  (3주 1일)
------------------------------------------
자료형과 변수
------------------------------------------
*/





#include<iostream>
#include<random>
#include<format>
#include "save.h"

using namespace std; 

default_random_engine dre;
uniform_int_distribution uid{1, 6};


int main() {

	save("소스.cpp");

	int a{ 922 }, b{ 2026 };

	//[문제] a의 값과 b의 값을 서로 바꿔라
	//다음 코드가 문제없이 실행 되어야 한다


	//C의 해결책


	void change(int*, int*);

	change(&a, &b);
	cout << a << ", " << b << endl;


}

void change(int* p, int* q) {

	int t = *p;
	*p = *q;
	*q = t;
}
