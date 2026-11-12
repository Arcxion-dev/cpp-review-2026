/*
------------------------------------------
2026. 2 화 34목34		화34  (11주 1일)
------------------------------------------
class 객체의 파일 입출력
------------------------------------------
*/

#include<iostream>
#include<print>
#include<random>
#include "save.h"
#include<fstream>
#include<istream>




#include "Xtring.h"

using namespace std;
extern bool 관찰;



//[시험문제] 다운받은 "개들.txt"에 몇 마리인지 모르는 class Dog 객체가 기록되어 있다. 
//모두 읽어서 메모리(contiguous memory)->((배운게 이거말곤 없음. 배운내용 기반해서 푸는건 코어 규칙이야)) 에 저정하라.

//class Dog{
//private :
//		string name;
//		int age;
//}
// 이고
//ostream os 에 
//		os << name << " " << age << endl;
//위와 같은 코드로 기록하였다

//기록된 객체의 수는 최대 200을 넘지 않는다.

class Dog {

public :
	int getAge() const {
		return age;
	}
private:
	string name;
	int age;
	friend istream& operator>>(istream& is, Dog& dog);// 읽어서 변하는거 아니니까 const가 아니래. istream이 const가 아닌이유는 이전과 같은이유래

	friend ostream& operator<<(ostream& is, Dog& dog);
};

istream& operator>>(istream& is, Dog& dog)
{
	return is >> dog.name >> dog.age;
}

ostream& operator<<(ostream& os, Dog& dog)
{
	println(os, "나이 - {:>5}, 이름 - {}", dog.age, dog.name);
	return os;
	

}


int ageAscend(const void* a, const void* b)
{
	return ((Dog*)a)->getAge() - ((Dog*)b)->getAge();
}

int main()
{


	ifstream in{ "개들.txt" };
	if (not in) {
		cout << "파일이 없다" << endl;
		return 20261112;
	}


	const int NUM{ 200 };

	Dog dogs[NUM];

	size_t cnt{};
	Dog dog;
	while (in >> dog)
	{
		dogs[cnt] = dog;
		++cnt;
	}

	cout << "읽은 Dog 객체의 수 - " << cnt << endl;

	//age 기준 오름차순으로 정렬하라
	qsort(dogs, cnt, sizeof Dog, ageAscend);


	for (int i = 0; i < cnt; ++i) {
		cout << i + 1 << "번째 Dog - " << dogs[i] << endl;
	}
	save("소스.cpp");



}
