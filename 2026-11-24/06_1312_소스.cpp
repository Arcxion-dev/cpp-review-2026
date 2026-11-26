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
	Animal() = default;
	Animal(const char* s, int n) : name{ s }, age{ n } {
		cout << "animal 의 생성자 " << endl;
	}
	~Animal() {
		cout << name <<  " - animal 소멸되기 직전에 호출되는 소멸자" << endl;
	}

	/*void move() {
		cout << name << "움직인다 - " << age << endl;
	}*/


	//가상함수 - > 이 멤버는 자식 클래스에서 override할수 있다.
	// = 0 -> 가상함수 중에서 몸체가 없는 함수
	virtual void move() = 0; //순수가상함수(pure virtual function)
	
	//순수가상함수가 1개라도 있는 클래스는 추상 클래스(abstract class) 라고 한다
	//추상 클래스는 instancing이 불가능하다. 


protected:		//이렇게 선언된 멤버는 자식 클래스에서 private 멤버로 사용가능.
	Xtring name;
	int age;
};

class Dog : public Animal {
public :

	Dog() = default;

	Dog(const char* s, int n) : Animal(s, n) {
		cout << "dog 의 생성자 " << endl;
	}
	~Dog() {
		cout << "dog 소멸되기 직전에 호출되는 소멸자" << endl;

	}


	//멤버함수 오버라이드(overriding) - override와 final을 언제 붙일 수 있나. 
	void move() override {
		cout << name << " " << age << "살 잘 달린다 " << endl;
	}

private :
	int test;
};

class Bird : public Animal {
public:
	Bird() = default;
	
	Bird(const char* s, int n)
		// : name{s} age{n}안되는이유
	{
		name = s;
		age = n;
	}
	void move() override final {
		cout << name << " " << age << "살 잘 난다" << endl;
	}
};


int main()
{
	Dog dogs[3];
	Bird birds[2];

	for (Dog& dog : dogs) {
		dog.move();
	}
	for (Bird& bird : birds) {
		bird.move();
	}

	save("소스.cpp");
}
