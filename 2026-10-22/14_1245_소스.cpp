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


	//1- default 생성자
	Dog() {
		age = 0;
		name = "이름을 지어주세요";

		cout << "ctor( )" << endl; // 아래에 Dog(string, int하나 더있는데 이거랑 구붆려고.
	}
	//2- 소멸자
	~Dog() {
		cout << "dtor" << endl;
	}

	//3- 복사 생성자(copy constructor)
	Dog(const Dog& other) : age{ other.age }, name{ other.name } {
		name += "의 복사본입니다";
		cout << "copy  ctor" << endl;
	}


	//4- 복사 할당 연산자(copy assignemnt operator)
	Dog& operator=(const Dog& other) {
		//dog2 = dog3에서 dog2 = dog2= dog2= dog2= dog3; 이게 적법한 문장이래. return값의 의미는 할당연산후 자기자신. 그래서 적법한 문장이 되는거지. 
		// 마찬가지로 int n ,x가 있을때 n=x=n=x=n 이런것도 적합한 문장. 

		//btw 같은 객체를 할당할 이유는 없다. 나를 나에게 할당하는건 굳이잖아? 
		if (this == &other)
			return *this;
		name = other.name;
		age = other.age;

		cout << "copy assignment op" << endl;
		return *this;

	}

	Dog(string name, int age) : name{ name }, age{ age } {
		cout << "ctor(strng, int)" << endl;
	}; 

	void show() {
		println("이름:{:<20} 나이:{:3}", name, age);
	}

private:
	string name;
	int age;
};

int main()
{

	 Dog dogs[3]{ {"코코", 3},{"보리", 2}, { "콩이", 5 } };
	 //스페셔라지않아. 실행하니가 소멸자만 나오네.

	 for (Dog& dog : dogs)
		 dog.show();

	save("소스.cpp");
}
