/*
------------------------------------------
2026. 2 화 34목34		화34  (3주 1일)
------------------------------------------
class - 6 special functions
------------------------------------------
*/


#include<iostream>
#include<string>
#include<memory>
#include<print>
#include "save.h"

class Dog {
public:
	//Dog랑 show함수를 통칭해서 인터페이스라고 부른다
	Dog(std::string name, int age) : name{ name }, age{ age } {}

	void show() {
		std::println("이름:{:<20} 나이:{:3}", name, age);
	}

	//age 는 private 이라 class 밖의 compare 에서 직접 읽을 수 없다
	//→ age 를 알려주는 멤버 함수를 만든다
	int getAge() {
		return age;
	}

private:
	std::string name;
	int age;
};

int compare(const void*, const void*);

int main()
{
	Dog dogs[3]{ { "철수", 3 }, { "보리", 20 }, { "초코", 7 } };

	//[문제] dogs를 age 기준 오름차순으로 정렬하라. (qsort)

	std::cout << "정렬 전" << std::endl;
	for (Dog dog : dogs) {
		dog.show();
	}

	// (시작번지, 개수, 한 개의 크기, 어떻게)
	qsort(dogs, 3, sizeof(Dog), compare);

	std::cout << "정렬 후" << std::endl;
	for (Dog dog : dogs) {
		dog.show();
	}

	save("소스.cpp");
}

int compare(const void* a, const void* b)
{
	Dog& d1 = *(Dog*)a;
	Dog& d2 = *(Dog*)b;

	if (d1.getAge() < d2.getAge()) {
		return -1;
	}
	if (d1.getAge() > d2.getAge()) {
		return 1;
	}
	return 0;
}
