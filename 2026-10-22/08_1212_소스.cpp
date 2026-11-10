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

	//복사 생성자(copy constructor)
	Dog(const Dog& other) : age{ other.age }, name{ other.name } {
		name += "의 복사본입니다";
		cout << "copy  ctor" << endl;
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

	Dog dog{ "코코", 3 };

	Dog dog2{ dog };
	dog.show();
	dog2.show();

	save("소스.cpp");
}
