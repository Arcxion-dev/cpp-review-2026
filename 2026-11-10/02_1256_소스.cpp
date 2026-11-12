/*
------------------------------------------
2026. 2 화 34목34		화34  (9주 2일)
------------------------------------------
class - 6 special fucntions(5,6,7)

**생성자는 객체를 생성하지 않는다 - 생성되고 나서 색칠하는 함수다**
**소멸자는 객체를 소멸하지 않는다 - 색칠한걸 뒷정리 하는 함수다**. 
------------------------------------------
*/

#include<iostream>
#include<print>
#include<random>
#include "save.h"

#include "Xtring.h"

using namespace std;

extern bool 관찰;


class INT {
public:
	INT(int n) : num{ n } {}


	//pre-increment
	INT& operator++() {
		//나를 1 증가시킨다
		++num;

		return *this;
	}
	//post- increment
	INT operator++(int) {
		//내 현재값을 저장
		INT temp(*this); // 복사생성
		//이후에 나를 1증가
		// 전위증가를 이용하여 후위증가 코들르 작성한다
		++(*this);
		//저장한 값을 리턴


		return temp;
	}

private:
	int num;

	friend std::ostream& operator<<(std::ostream& os, const INT& n) {
		return os << n.num;
	}


};


int main()
{
	INT a = 1;
	INT b = ++a;

	cout << "b값 - " << b << endl;

	//int c = a++;
	//cout << "c값 - " << c << endl;

	save("소스.cpp");

}
