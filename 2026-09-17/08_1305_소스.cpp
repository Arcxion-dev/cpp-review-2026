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


	int num[10]{ 3,4,9,2,5,0,7,1,8,6 };
	for (int i = 0; i < 10; ++i) {
		cout << num[i] << ' ';
	}
	cout << endl;
	
	


	//[문제] 가장 큰 값을 제일 오른쪽으로 옮겨라

	for (int i = 0; i < 10-1; ++i) {
		if (num[i] > num[i + 1]) {
			int temp{ num[i] };
			num[i] = num[i + 1];
			num[i + 1] = temp;
		}
			
	}


	for (int i = 0; i < 10; ++i) {
		cout << num[i] << ' ';
	}



}
