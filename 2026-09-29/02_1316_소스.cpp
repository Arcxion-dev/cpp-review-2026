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
uniform_int_distribution uid{ 1, 999'9999};
const int NUM{ 1000 };


int main() {

	int a[NUM];

	//a의 값을 1부터 NUM까지 int값으로 assign 한다
	for (int i = 0; i < NUM; ++i) {
		a[i] = uid(dre);
	}

	for (int num : a) //range-for [] 이 range를 알수있는 자료구조라서
		print("{:8}", num);
	cout << endl;

	save("소스.cpp");



}
