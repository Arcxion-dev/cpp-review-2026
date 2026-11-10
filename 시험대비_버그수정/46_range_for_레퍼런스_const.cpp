//------------------------------------------------------------------
// range-for 에서 쓸데없는 복사 없애기 - & 와 const   (10/22 수업)
//
// 1. for (Dog dog : dogs)        → 한 바퀴마다 복사 생성자 + 소멸자 (삽질 코드)
// 2. for (Dog& dog : dogs)       → 레퍼런스 = 원본 그대로 → 복사본을 만들지 않는다
// 3. for (const Dog& dog : dogs) → 복사도 안 하고, 데이터도 건드리지 않는다
//
// const Dog& 로 받은 객체는 const 멤버 함수만 부를 수 있다
//   void show() const { ... }   ← 이 함수는 멤버(name, age)를 바꾸지 않는다는 약속
//   show() 에 const 를 안 붙이면 3번이 컴파일 에러
//
// Dog dogs[3]{ { "코코", 3 }, ... }; 는 인자 있는 생성자(special 아님)가 3번 불린다
//------------------------------------------------------------------

#include<iostream>
#include<string>
#include<print>

class Dog {
public:
	//1- default 생성자
	Dog() {
		age = 0;
		name = "이름을 지어주세요";
		std::cout << "ctor( )" << std::endl;
	}
	//2- 소멸자
	~Dog() {
		std::cout << "dtor " << name << std::endl;
	}
	//3- 복사 생성자
	Dog(const Dog& other) : name{ other.name }, age{ other.age } {
		name += "의 복사본입니다";
		std::cout << "copy  ctor" << std::endl;
	}
	//4- 복사 할당 연산자
	Dog& operator=(const Dog& other) {
		if (this == &other) {
			return *this;
		}
		name = other.name;
		age = other.age;
		std::cout << "copy assignment op" << std::endl;
		return *this;
	}

	Dog(std::string name, int age) : name{ name }, age{ age } {
		std::cout << "ctor(string, int)" << std::endl;
	}

	//const 멤버 함수 - 데이터를 건드리지 않는다
	void show() const {
		std::println("이름:{:<24} 나이:{:3}", name, age);
	}

private:
	std::string name;
	int age;
};

int main()
{
	Dog dogs[3]{ { "코코", 3 }, { "보리", 2 }, { "콩이", 5 } };

	std::cout << "--- 1. for (Dog dog : dogs)" << std::endl;
	for (Dog dog : dogs) {
		dog.show();
	}

	std::cout << "--- 2. for (Dog& dog : dogs)" << std::endl;
	for (Dog& dog : dogs) {
		dog.show();
	}

	std::cout << "--- 3. for (const Dog& dog : dogs)" << std::endl;
	for (const Dog& dog : dogs) {
		dog.show();
	}

	std::cout << "--- main 끝" << std::endl;
}
