/*
------------------------------------------
2026. 2 화 34목34		화34  (3주 1일)
------------------------------------------
FILE I/O - 처리해야 할 자료가 플그램 밖의 파일에 있다,

------------------------------------------
*/


#include<iostream>
#include<fstream>
#include "save.h"
using namespace std;



int main() {
	save("소스.cpp");

	//[문제] 1부터 100까지의 int값을 파일 "int 100개"에 출력하라.

	std::ofstream out{"int 100개"s};

	cout << sizeof out << endl;


	for (int i = 0; i < 100; ++i){
		cout << i + 1 << ' ';
	}
	cout << endl;


}
