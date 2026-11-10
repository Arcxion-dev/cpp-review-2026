//------------------------------------------------------------------
// Xtring 복사 생성자 - 10/29 수업 (12:57 ~ 13:01)
//
// 복사 생성자 없이 Xtring b = a; → len, p 값만 복사 → 같은 free-store 를 둘이 가리킴
//   → 소멸 때 두 번 delete[] → 0xC0000374 (즉사 안 하면 우연)
// 복사 생성자: b 가 new char[len] 으로 새로 확보 + memcpy 로 내용 복사
//
// 실행 결과 (Release / x64)
//	ctor(char*)
//	copy ctor
//	글자수 : 16, 내용 : 2026년 10월 29일
//	글자수 : 16, 내용 : 2026년 10월 29일
//	dtor() -- 16
//	dtor() -- 16
//
// 소멸: b 먼저 (접시 위) → 각 객체는 free-store 반환 후 STACK 메모리가 사라짐
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
	Xtring b{ a }; //복사 생성자 호출

	a.show();
	b.show();
}
