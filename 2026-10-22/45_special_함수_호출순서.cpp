//------------------------------------------------------------------
// class - 6 special functions  (10/20 ~ 10/22 수업)
//
// special 함수 = 내가 안 만들어도 컴파일러가 알아서 만들어 주는 함수
//   1. default 생성자            Dog()
//   2. 소멸자                    ~Dog()
//   3. 복사 생성자               Dog(const Dog& other)
//   4. 복사 할당 연산자          Dog& operator=(const Dog& other)
//   (5, 6 은 아직 수업 전)
//
// special 이 아닌 것 - 내가 만들어야만 생긴다
//   Dog(std::string name, int age)  ← 인자 있는 생성자 (일반 생성자)
//   show(), getAge()                ← 멤버 함수 (인터페이스, getter)
//
// 언제 무엇이 호출되나 - 실행해서 출력 순서를 확인한다
//------------------------------------------------------------------

#include<iostream>
#include<string>
#include<print>

class Dog {
public:
	//1- default 생성자 : Dog dog; 처럼 인자 없이 만들 때
	Dog() {
		age = 0;
		name = "이름을 지어주세요";
		std::cout << "  [default 생성자]" << std::endl;
	}

	//2- 소멸자 : 객체가 사라질 때
	~Dog() {
		std::cout << "  [소멸자] " << name << std::endl;
	}

	//3- 복사 생성자 : 다른 Dog 를 복사해서 "새로 만들 때"
	Dog(const Dog& other) : name{ other.name }, age{ other.age } {
		name += "의 복사본";
		std::cout << "  [복사 생성자]" << std::endl;
	}

	//4- 복사 할당 연산자 : "이미 있는" Dog 에 다른 Dog 를 대입할 때
	Dog& operator=(const Dog& other) {
		if (this == &other) {			// 나를 나에게 할당할 필요는 없다
			return *this;
		}
		name = other.name;
		age = other.age;
		std::cout << "  [복사 할당 연산자]" << std::endl;
		return *this;					// 할당 후 자기 자신 → dog2 = dog3 = dog; 가 가능
	}

	//special 아님 - 인자 있는 생성자
	Dog(std::string name, int age) : name{ name }, age{ age } {
		std::cout << "  [인자 있는 생성자 - special 아님]" << std::endl;
	}

	//special 아님 - 멤버 함수
	void show() {
		std::println("  이름:{:<20} 나이:{:3}", name, age);
	}

	int getAge() {
		return age;
	}

private:
	std::string name;
	int age;
};

int main()
{
	std::cout << "1. Dog dog;" << std::endl;
	Dog dog;

	std::cout << "2. Dog dog1{ \"코코\", 3 };" << std::endl;
	Dog dog1{ "코코", 3 };

	std::cout << "3. Dog dog2 = dog1;   (새로 만들면서 복사)" << std::endl;
	Dog dog2 = dog1;

	std::cout << "4. Dog dog3{ dog1 };  (새로 만들면서 복사)" << std::endl;
	Dog dog3{ dog1 };

	std::cout << "5. dog2 = dog;        (이미 있는 dog2 에 대입)" << std::endl;
	dog2 = dog;

	std::cout << "6. for (Dog d : dogs) 처럼 값으로 받으면" << std::endl;
	Dog dogs[2]{ { "철수", 3 }, { "보리", 20 } };
	for (Dog d : dogs) {
		d.show();
	}

	std::cout << "7. for (Dog& d : dogs) 처럼 레퍼런스로 받으면" << std::endl;
	for (Dog& d : dogs) {
		d.show();
	}

	std::cout << "8. main 끝 - 만든 순서의 반대로 소멸" << std::endl;
}
