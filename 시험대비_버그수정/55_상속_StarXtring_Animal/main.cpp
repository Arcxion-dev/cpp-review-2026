//------------------------------------------------------------------
// 11/19 수업 - 입력 연산자 + 상속 (Xtring.h / Xtring.cpp 는 교수님 코드 그대로, 11/19 12:12)
// 빌드: cl /std:c++latest /EHsc main.cpp Xtring.cpp
//
// [문제] 입력한 글자를 출력할 때는 숫자 부분을 * 로 표시하는 기능을 구현   예) 2026abcd -> ****abcd
// 교수님 12:18 코드에서 바꾼 점: operator<< 안의 cout → os (파일로 출력해도 맞게),
//                               쓰지 않는 멤버 Xtring name; 제거
//
// 실행 결과 (입력 2026abcd)
//	암호를 입력하세요 :  ****abcd
//	코코움직인다 - 3
//------------------------------------------------------------------
#include<iostream>
#include<cctype>
#include "Xtring.h"

class StarXtring : public Xtring {
	friend std::ostream& operator<<(std::ostream& os, const StarXtring& s) {
		for (size_t i = 0; i < s.size(); ++i) {
			if (isdigit(s[i])) {
				os << '*';
			}
			else {
				os << s[i];
			}
		}
		return os;
	}
};

class Animal {
public:
	Animal(const char* s, int n) : name{ s }, age{ n } {}
	void move() {
		std::cout << name << "움직인다 - " << age << std::endl;
	}
private:
	Xtring name;
	int age;
};

class Dog : public Animal {
public:
	Dog(const char* s, int n) : Animal(s, n) {}
};

int main()
{
	{
		std::cout << "암호를 입력하세요 :  ";
		StarXtring a;
		std::cin >> a;
		std::cout << a << std::endl;
	}

	Dog dog("코코", 3);
	dog.move();
}
