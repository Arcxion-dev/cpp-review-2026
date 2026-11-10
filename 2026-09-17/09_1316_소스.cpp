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
uniform_int_distribution uid{ 1,999 };


int main() {

	save("소스.cpp");
	
	int num[1'0000];
	for (int i = 0; i < 1'0000; ++i) {
		num[i] = uid(dre);
	}

	for (int i = 0; i < 1'0000; ++i) {
		print("{:8}", num[i]);
	}
	cout << endl;

	//[문제] 자료 중에서 찾는 값을 물어보고 있으면 몇번째 있는지 없으면 없다라고 대답하라.
	while (true) {

		int target{};
		cin >> target;
		bool exist = false;
		for (int i = 0; i < 1'0000; ++i) {
			if (num[i] == target)
				exist = true;
		}
		if (exist)
			cout << "존재합니다 " << endl;
		else
			cout << "존재하지 않습니다 " << endl;
		
	}
}
