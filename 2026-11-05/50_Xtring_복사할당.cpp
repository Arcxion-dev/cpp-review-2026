//------------------------------------------------------------------
// Xtring 복사 할당 연산자 - 10/29 수업 (13:07 ~ 13:20)
//
// operator= 없이 Xtring b; b = a; → len, p 만 대입 → 같은 블록 두 번 delete[] → 0xC0000374
// operator= : ① 자기 대입 검사 ② 옛 자원 반환 ③ 새로 확보 + 복사 ④ return *this (연쇄 대입)
//
// 실행 결과 (Release / x64)
//	ctor(char*)
//	ctor()
//	copy assignment op   (x5 - 오른쪽부터 b=a, a=b, b=a, a=b, b=a)
//	글자수 : 16, 내용 : 2026년 10월 29일
//	글자수 : 16, 내용 : 2026년 10월 29일
//	dtor() -- 16
//	dtor() -- 16
//------------------------------------------------------------------

#include<iostream>
#include<cstring>

class Xtring {
public:
	Xtring() :len{ }, p{ nullptr } {
		std::cout << "ctor()" << std::endl;
	}

	~Xtring() {
		std::cout << "dtor() -- " << len << std::endl;
		//자원을 확보하는 클래스는 소멸전에 자원을 반환해야 한다
		delete[] p;
	}

	Xtring(const char* s) : len{ strlen(s) } {
		p = new char[len];
		memcpy(p, s, len);
		std::cout << "ctor(char*)" << std::endl;
	};

	// 3- 복사 생성자
	Xtring(const Xtring& other) : len{ other.len } {
		p = new char[len];
		memcpy(p, other.p, len);
		std::cout << "copy ctor" << std::endl;
	}

	// 4- 복사 할당 연산자
	Xtring& operator=(const Xtring& other) {
		if (this == &other) {
			return *this;
		}

		//내가 확보했던 자원을 반환
		delete[] p;

		//other와 같은 내용으로 나를 만든다
		len = other.len;
		p = new char[len];
		memcpy(p, other.p, len);

		std::cout << "copy assignment op" << std::endl;

		return *this;
	}

	size_t size() {
		return len;
	}

	char* data() {
		return p;
	}

	void show() {
		std::cout << "글자수 : " << len << ", 내용 : ";
		std::cout.write(p, len);
		std::cout << std::endl;
	}

private:
	size_t len;
	char* p;
};

int main()
{
	Xtring a{ "2026년 10월 29일" };
	Xtring b;

	b = a = b = a = b = a;

	a.show();
	b.show();
}
