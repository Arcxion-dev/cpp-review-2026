/*
------------------------------------------
2026. 2 화 34목34		화34  (11주 1일)
------------------------------------------
class 객체의 파일 입출력
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

	//만약 ~Dog()썼다면 그 이유 써야됨. 교수님은 **안썼다**. 문제는 최소한도로 코딩하라고 하셨기 때문. Xtring대신 string 써도 되지. 근데 멤버나 다른거 같이했으면 안된다

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
	Dog b;

	cout << a << endl; // 코코	3	이라고 출력되게 하라
	cout << b << endl; // 이름없음	이라고 출력되게 하라

	save("소스.cpp");

}
