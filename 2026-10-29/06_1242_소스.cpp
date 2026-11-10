/*
------------------------------------------
2026. 2 화 34목34		화34  (3주 1일)
------------------------------------------
class - 6 special fucntions(5,6,7)

**생성자는 객체를 생성하지 않는다 - 생성되고 나서 색칠하는 함수다**
**소멸자는 객체를 소멸하지 않는다 - 색칠한걸 뒷정리 하는 함수다**. 
------------------------------------------
*/


#include<iostream>
#include<memory>
#include<print>
#include<windows.h>
#include<mmsystem.h>


#include "save.h"

#pragma comment(lib, "winmm.lib")

using namespace std;





class Xtring {
public:

	Xtring() :len{ }, p{ nullptr } {
		cout << "ctor()" << endl;

	}
	~Xtring() {
		cout << "dtor() -- " << len << endl;
		//자원을 확보하는 클래스는 소멸전에 자원을 반환해야 한다
		delete[] p; // 얘가 문제를 만들었다는데? 즉사케이스?? 그래서 Xtring 디폴트로 만들때 클리어 해야된데. len{}, p{} 추가함.
	}

	Xtring(const char* s) : len{ strlen(s) } {
		p = new char[len];
		//for (int i = 0; i < len; ++i)
		//	p[i] = s[i];

		memcpy(p, s, len);

		cout << "ctor(char*)" << endl; //이 관찰 메시지를 보면 스페셜 함수 만들라는거임. 문제로 쓸수도?
	};
	size_t size() {
		return len;
	}
	char* data() {
		return p;
	}

	void show() {
		cout << "글자수 : " << len << ", 내용 : ";
		cout.write(p, len);
		cout << endl;
	}

private:
	size_t len;
	char* p;

};


int main()
{
	

	save("소스.cpp");

	Xtring a;
	a.show();
	Xtring b{ "2026년 10월 29일" };
	b.show();

}
