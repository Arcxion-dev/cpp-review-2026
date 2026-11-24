/*
------------------------------------------
2026. 2 화 34목34		화34  (11주 1일)
------------------------------------------
class -  move semantic 구현 - () 오버로딩 - 이동이 어떻게 사용되나
------------------------------------------
*/

#include<iostream>
#include<string>
#include "save.h"
#include <algorithm> 
#include <functional> 


#include "Xtring.h"

using namespace std;
extern bool 관찰;



class Animal {
public:
	Animal(const char* s, int n) : name{ s }, age{ n } {
		cout << "animal 의 생성자 " << endl;
	}
	~Animal() {
		cout << "animal 소멸되기 직전에 호출되는 소멸자" << endl;
	}

	void move() {
		cout << name << "움직인다 - " << age << endl;
	}
private:
	Xtring name;
	int age;
};

class Dog : public Animal {
public :
	Dog(const char* s, int n) : Animal(s, n) {
		cout << "dog 의 생성자 " << endl;
	}
	~Dog() {
		cout << "dog 소멸되기 직전에 호출되는 소멸자" << endl;

	}


	//멤버함수 오버라이드(overriding) - override와 final을 언제 붙일 수 있나. 
	void move()  {
		cout << "잘 달린다 " << endl;
	}

private :
	int test;
};


int main()
{
	Dog dog("코코", 3);
	dog.move(); //코코 3살 잘 달린다 - 로 출력되게 하라
				//멤버함수 overriding

	save("소스.cpp");
	save("Xtring.h");
	save("Xtring.cpp");
}
