//------------------------------------------------------------------
// class - 6 special functions
// 생성자 Dog()  : 객체가 생길 때 호출
// 소멸자 ~Dog() : 객체가 사라질 때 호출
//
// 메모리 그림 (생성자 등.png)
// · Dog = string name (32) + int age (4) → 40 바이트, Dog dog; 는 STACK 에 40 바이트
//
// 언제 생성 / 소멸되나
// 1. main 안의 Dog dog;     → main 이 끝날 때 소멸
// 2. { Dog dog; }           → 블록이 끝날 때 소멸   ★ 메모리 엄격 - 필요한 블록 안에서만
// 3. 전역 Dog dog;          → main 보다 먼저 생성, main 이 끝난 뒤 소멸
// 4. new Dog;               → 소멸자가 호출되지 않는다! (메모리를 되돌려 놓지 않음)
// 5. unique_ptr<Dog>        → p 가 사라질 때 소멸자 자동 호출
//------------------------------------------------------------------

#include<iostream>
#include<string>
#include<memory>

class Dog {
public:
	Dog() {
		std::cout << "생성자 함수가 호출되었다" << std::endl;
	}
	~Dog() {
		std::cout << "소멸자 함수가 호출되었다" << std::endl;
	}

private:
	std::string name;
	int age;
};

int main()
{
	std::cout << "Dog 의 크기 - " << sizeof(Dog) << std::endl;

	std::cout << "--- 블록" << std::endl;
	{
		Dog dog;
	}

	std::cout << "--- unique_ptr" << std::endl;
	{
		std::unique_ptr<Dog> p = std::make_unique<Dog>();
	}

	// new Dog;		// 소멸자가 호출되지 않는다 → 쓰지 않는다

	std::cout << "2026/10/20" << std::endl;
}
