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

	Xtring() {
		cout << "ctor()" << endl;
	}
	~Xtring() {
		cout << "dtor()" << endl;

	}

	Xtring(const char* s) : len{ strlen(s) } {
		p = new char[len];
		for (int i = 0; i < len; ++i)
			p[i] = s[i];

		cout << "ctor(char*)" << endl; //이 관찰 메시지를 보면 스페셜 함수 만들라는거임. 문제로 쓸수도?
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
	cout << "글자수 - " << s.size() << endl;
	cout << "내용 - " << s.data() << endl;
}
