/*
------------------------------------------
2026. 2 화 34목34		화34  (3주 1일)
------------------------------------------

자료형과 변수
------------------------------------------
*/



#include<iostream>
#include<random>
#include "save.h"

using namespace std; 

default_random_engine dre;
uniform_int_distribution uid{ 1,999 };


int main() {

	save("소스.cpp");

	//int 100개를 저장할 멤리에 랜덤값을 저장하였다.
	int num[100];

	for (int i = 0; i < 100; ++i)
		num[i] = uid(dre);

	int index = 0;

	//[문제] num의 값을 4칸에 맞춰 모두 철력해 보세요.

	for (int i = 0; i < 100; ++i)
		cout << format("{:4}", num[i]);
	cout << endl;

	int greatest = 0;

	//[문제] 가장 큰 갑을 찾아 화면에 출력하라 
	for (int i = 0; i < 100; ++i)
		if (num[i] > greatest)
			greatest = num[i];
	cout << greatest << endl;
}
