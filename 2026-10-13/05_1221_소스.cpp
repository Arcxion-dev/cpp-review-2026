/*
------------------------------------------
2026. 2 화 34목34		화34  (3주 1일)
------------------------------------------
FILE I/O - 처리해야 할 자료가 플그램 밖의 파일에 있다,

중간소

------------------------------------------
*/


#include<iostream>
#include<fstream>
#include "save.h"
using namespace std;



int main() {
	save("소스.cpp");

	//[문제]파일 "int 100개" 에는 몇개인지 모르는 int 값이 저장되어 있다. 
	//int값은 공백으로 서로 분리되어 있다
	//저장된 값을 읽어 화면에 출력하고
	//모두 몇개인지도 추력하라.

	std::ifstream in{"int 100개.txt"s};

	if (!in) {
		cout << "파일 열기 실패" << endl;
		return 20261013;
}


	int num;

	while (in >> num) {
		cout << num << ' ';
	}
	cout << endl;



}
