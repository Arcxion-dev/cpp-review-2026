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

	//[문제] "소스.cpp" 파일에 있는 소문자를 모두 대문자로 바꾼 "소스대문자.cpp"를 만들어라.
	
	ifstream in{ "소스.cpp" };
	ofstream out{ "소스대문자.cpp" };
	char ch;
	in >> noskipws;
	while (in >> ch) {
		if (islower(ch)) {
			ch = toupper(ch);
		}
		out << ch;
	}

}
