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

void change(int*, int*);

int main() {


	int num{ 2026 };

	int& r{ num };
	r = 1001;
	cout << num << endl;

	save("소스.cpp");


}
