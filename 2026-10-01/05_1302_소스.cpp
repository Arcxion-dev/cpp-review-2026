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

int main() {

	save("소스.cpp");

	//스택 오버플로우 만들어보기
	void f();

	f();

}

void f() {
	char c[1024 * 100]{ 'c' }; //약 100 kb
	cout << c[0] << c[10000] << endl;
	cout << "c의 주소 - " << addressof(c);

	f(); //recursive function call
}
