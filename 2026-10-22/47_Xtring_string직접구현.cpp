//------------------------------------------------------------------
// [문제] std::string 의 동작과 같이 실행되도록 구현해보자.   (10/22 수업)
//
// 교수님 수업 코드의 문제 (10/22 설명)
// 1. p = new char[len];  + 글자 수(len) 만큼만 복사
//    → 문자열 끝 표시를 복사하지 않음 → cout << s.data() 가 어디서 멈출지 모른다
//    → 원래 죽어야 하는 코드. 운 좋게 뒤에 끝 표시가 있어서 멈춘 것
// 2. new 로 받은 메모리를 반환하지 않음
//    → 바깥 세상(free-store)과 연결된 자원이므로 소멸자에서 delete[] 로 반환해야 한다
//
// 고친 것
// 1. new char[len + 1] - 끝 표시 자리까지 확보하고, s[0] ~ s[len] 까지 복사 (s[len] 이 끝 표시)
// 2. 소멸자에서 delete[] p;
// 3. 관찰 메시지(ctor ...)가 찍히는 문제 → special 함수도 같이 만든다
//    · 복사 생성자 / 복사 할당 연산자를 안 만들면 컴파일러가 p(주소)만 복사
//      → 두 Xtring 이 같은 메모리를 가리키고, 둘 다 소멸자에서 delete[] → 두 번 반환
//    · 그래서 복사할 때는 free-store 에 새로 확보하고 글자를 하나씩 복사한다
//
// ※ 3번은 Claude 해결본. 교수님이 수업에서 고친 코드가 나오면 그 방식으로 바꿀 것
//
// 메모리 그림 (Xtrnig.png)
//   STACK        Xtring s  [ len | p ]  16 바이트
//                                 │
//   free-store                    └──▶ [2 0 2 6 년 ... 시 작 (끝)]   ← new char[len + 1]
//                                          ▲ 생성자에서 한 글자씩 복사
//   DATA         "2026년 10월 22일 string 시작"   ← const char (문자열 그 자체)
//   p 가 DATA 를 직접 가리키면 안 된다 (그림의 X)
//------------------------------------------------------------------

#include<iostream>
#include<string>

class Xtring {
public:
	//1- default 생성자 : 빈 문자열
	Xtring() {
		len = 0;
		p = new char[1];
		p[0] = 0;
		std::cout << "ctor()" << std::endl;
	}

	//2- 소멸자 : 자원 반환
	~Xtring() {
		delete[] p;
		std::cout << "dtor()" << std::endl;
	}

	//3- 복사 생성자 : 새로 확보해서 글자를 복사
	Xtring(const Xtring& other) : len{ other.len } {
		p = new char[len + 1];
		for (size_t i = 0; i <= len; ++i) {
			p[i] = other.p[i];
		}
		std::cout << "copy ctor" << std::endl;
	}

	//4- 복사 할당 연산자 : 내 것을 반환하고, 새로 확보해서 복사
	Xtring& operator=(const Xtring& other) {
		if (this == &other) {
			return *this;
		}
		delete[] p;
		len = other.len;
		p = new char[len + 1];
		for (size_t i = 0; i <= len; ++i) {
			p[i] = other.p[i];
		}
		std::cout << "copy assignment op" << std::endl;
		return *this;
	}

	//special 아님 - const char* 로 만드는 생성자
	Xtring(const char* s) : len{ strlen(s) } {
		p = new char[len + 1];
		for (size_t i = 0; i <= len; ++i) {
			p[i] = s[i];
		}
		std::cout << "ctor(char*)" << std::endl;
	}

	size_t size() const {
		return len;
	}

	char* data() const {
		return p;
	}

private:
	size_t len;
	char* p;
};

int main()
{
	Xtring s{ "2026년 10월 22일 string 시작" };
	std::cout << "글자수 - " << s.size() << std::endl;
	std::cout << "내용 - " << s.data() << std::endl;

	Xtring s2 = s;
	std::cout << "s2 - " << s2.data() << std::endl;

	Xtring s3;
	s3 = s;
	std::cout << "s3 - " << s3.data() << std::endl;

	std::cout << "sizeof(Xtring) - " << sizeof(Xtring) << std::endl;
}
