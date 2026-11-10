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
	Dog(const Dog& other) {
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

	Dog dog;//디폴트 생성자 호출 (special 함수 )



	Dog dog2 = dog; //dog2를 생성하는데 dog와 똑같이 만들어줘
					//dog를 복사해서 dog2를 생성 (speical 함수)

	dog.show();
	dog2.show();

	//소멸자 호출

	save("소스.cpp");
}
