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

class Dog {
public:

	Dog() : name{ "이름없음" }, age{ 0 } {}

	Dog(const Xtring& name, int a) 
		: name{ name }, age{ a } {}

private:
	Xtring name;
	int age;

	friend ostream& operator <<(ostream& os, const Dog& dog) {
		os << dog.name << " " << dog.age << endl;
		return os;
	}
};


int main()
{
	Dog a{ "코코", 3 };

	//cout << a << endl; // 코코	3	이라고 출력되게 하라

	save("소스.cpp");

}
