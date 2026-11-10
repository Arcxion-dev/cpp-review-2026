/*
------------------------------------------
2026. 2 화 34목34		화34  (3주 1일)
------------------------------------------
class - 6 special functions
------------------------------------------
*/


#include<iostream>
#include<memory>
#include<print>
#include "save.h"
using namespace std;

class Dog {

public:

	//Dog랑 show함수를 통칭해서 인터페이스라고 부른다
	Dog(string name, int age) : name{ name }, age{ age } {};
	
	void show() {
		print("이름:{:<20} 나이:{:3}", name, age);
	}
private:
	string name;
	int age;
};

int main()
{

	Dog a("철수", 3 );
	a.show();


	save("소스.cpp");

}
