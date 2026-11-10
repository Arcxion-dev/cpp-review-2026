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

	Dog() {
		age = 0;
		name = "이름을 지어주세요";

		cout << "ctor( )" << endl; // 아래에 Dog(string, int하나 더있는데 이거랑 구붆려고.
	}
	~Dog() {
		cout << "dtor";
	}

	Dog(string name, int age) : name{ name }, age{ age } {}; 

	void show() {
		println("이름:{:<20} 나이:{:3}", name, age);
	}

private:
	string name;
	int age;
};

int main()
{

	Dog dog;//디폴트 생성자 호출 special 함수 

	save("소스.cpp");
	dog.show();
}
