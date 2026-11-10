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

	//Dog랑 show함수를 통칭해서 인터페이스라고 부른다
	Dog(string name, int age) : name{ name }, age{ age } {}; // 교수님은 여기 괄호 일케한거 맞음

	void show() {
		print("이름:{:<20} 나이:{:3}", name, age);
	}

	//getter 와 setter - 얘네도 interface 함수(오히려 진정한 인터페이스 함수라 할수잇지)
	int	getAge() {
		return age;
	}
	

private:
	string name;
	int age;
};

int 오름(const void*, const void*);

int main()
{

	Dog dogs[3]{ {"철수", 3} , {"보리", 20} ,{ "초코" , 7 } };


	qsort(dogs, 3, sizeof(Dog), 오름);

	//[문제] dogs를 age 기준 오름차순으로 정렬하라. (qsort)
	for (Dog dog : dogs)
		dog.show();



	save("소스.cpp");

}

int 오름(const void* a, const void* b) {

	Dog dog1 = *(Dog*)a;
	Dog dog2 = *(Dog*)b;

	return dog1.getAge() > dog2.getAge(); // int값이니까 이렇게 할수있다고 배웠네?? 그러면서 이렇게 쓰시네.
}
