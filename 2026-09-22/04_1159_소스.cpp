/*
------------------------------------------
2026. 2 화 34목34		화34  (3주 1일)
------------------------------------------
자료형과 변수
------------------------------------------
*/



#include<iostream>
#include<print>

#include "save.h"

using namespace std; 

int add(int , int);


int main() {

	save("소스.cpp");
	
	//[문제] int값 두개를 전달받아 합계를 알렺는 함수 add를 작성하라.
	//다음 코드가 문제없이 실행되어야 한다.

	while(true) {
		cout << "합계를 계산합니다" << endl;

		int num1, num2;
		cin >> num1 >> num2;

		cout << "합계는 " <<add(num1,num2) << endl;
	}

}

int add(int num1, int num2) {

	return num1 + num2;

}
