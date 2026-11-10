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


	int count[6]{0,0,0,0,0,0};
	const int NUM{ 20000 };

	//[문제] 주사위를 10000번 던졋다. 각 눈의 확률을 구하여라.
	
	for (int i = 0; i < NUM; ++i) {
		
		++count[uid(dre) - 1];
	}

	for (int i = 0; i < 6; ++i) {
		//cout << float( count[i]) / 100 << endl;
		cout << format("{:.2f}",count[i]/ static_cast<double>(NUM)) << endl;
	}


}
