//------------------------------------------------------------------
// Xtring - 10/29 수업 단계별 수정 (교수님 방식)
//
// 생성자는 객체를 생성하지 않는다 - 생성되고 나서 색칠하는 함수다
// 소멸자는 객체를 소멸하지 않는다 - 색칠한 걸 뒷정리 하는 함수다
//
// 1. 끝 표시(0) 없이 len 만큼만 복사 → cout << p 는 0 이 나올 때까지 읽음 (운 좋게 끝남)
// 2. Xtring a[10]; → default 생성자가 p 를 초기화 안 함 → delete[] 쓰레기 주소 → 즉사
// 3. default 생성자 :len{ }, p{ nullptr } → delete[] nullptr 은 아무 일도 안 함
// 4. show() 의 cout.write(p, len) → 정확히 len 바이트만 출력 (끝 표시 필요 없음)
// 5. 소멸자에서 len 출력 → 어느 객체가 먼저 소멸되는지 구별 (만든 순서의 반대)
//
// 실행 결과 (Release / x64)
//	ctor()
//	글자수 : 0, 내용 :
//	ctor(char*)
//	글자수 : 16, 내용 : 2026년 10월 29일
//	dtor() -- 16
//	dtor() -- 0
//
// 아직 복사 생성자 / 복사 할당이 없음 → Xtring c = b; 하면 두 번 delete[] → 죽음
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
	Xtring a;
	a.show();
	Xtring b{ "2026년 10월 29일" };
	b.show();
}
