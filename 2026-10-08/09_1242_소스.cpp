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
int main() {
	save("소스.cpp");


	unique_ptr<int[]> p = make_unique<int[]>(100);
	p[0] = 123;

}
