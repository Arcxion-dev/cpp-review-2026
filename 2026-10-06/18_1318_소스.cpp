/*
------------------------------------------
2026. 2 화 34목34		화34  (3주 1일)
------------------------------------------
자료형과 변수
------------------------------------------
*/


#include<iostream>
#include "save.h"
#include "random"

using namespace std;
default_random_engine dre;
uniform_int_distribution uid{ 1,999'9999 };



int main() {
	save("소스.cpp");
	
	//[문제] 1억 이하의 자연수를 한개 입력받아
	//입력한 개수만큼 int 메모리를 확보하라
	//각 int 값을 [1,999'9999] 사이의 랜덤값으로 할당하라
	//앞에서 부터 100개, 뒤에서 역순으로 100개를 화면에 출력하라

	size_t cnt;
	cin >> cnt;
	
	int* rnd = new int[cnt];

	for (int i = 0; i < cnt; ++i){
		rnd[i] = uid(dre);
	}

	for (int i = 0; i < 100; ++i) {
		cout << rnd[i] << endl;
	}
	for (int i = 0; i < 100; ++i) {
		cout << rnd[cnt-1-i] << endl;
	}
}
