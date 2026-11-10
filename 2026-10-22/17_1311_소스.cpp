/*
------------------------------------------
2026. 2 화 34목34		화34  (3주 1일)
------------------------------------------
class - 6 special functions (56)
------------------------------------------
*/


#include<iostream>
#include<memory>
#include<print>
#include "save.h"
using namespace std;


class Xtring {
public:
	Xtring(const char* s) : len{ strlen(s) } {
		p = new char[len];
		for (int i = 0; i < len; ++i)
			p[i] = s[i];
	};
	size_t size() {
		return len;
	}
	char* data() {
		return p;
	}

private:
	size_t len;
	char* p;

};


int main()
{
	save("소스.cpp");

	//[문제] std::string의 동작과 같이 실행되도록 구현해보자.

	Xtring s{ "2026년 10월 22일 string 시작" }; // 얘는 const char임. 쟤를 보통 메모리그림 참조해서 표현,
	cout << "string 이 관리하는 글자 개수 - " << s.size() << endl;
	cout << "string이 관리하는 글자메모리의 시작번지 - " << s.data() << endl;
}
