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


default_random_engine dre{ random_device ()()}; //random device >절대추적불간으
uniform_int_distribution uidLen{ 1,100 };
uniform_int_distribution<int> uidChar{ 'a','z' };
uniform_int_distribution uidAge{ 1,999 };


class Dog {
public:

	Dog() {
		for (int i = 0; i < uidLen(dre);++i) {
			name += uidChar(dre);
		}
		age = uidAge(dre);
	}


	Dog(const string& name, int a) 
		: name{ name }, age{ a } {}

private:
	string name;
	int age;

	friend ostream& operator <<(ostream& os, const Dog& dog) {
		os << dog.name << " " << dog.age << endl;
		return os;
	}
};


int main()
{
	Dog dogs[100];

	for (const Dog& dog : dogs)
		cout << dog << endl;

	save("소스.cpp");

}
