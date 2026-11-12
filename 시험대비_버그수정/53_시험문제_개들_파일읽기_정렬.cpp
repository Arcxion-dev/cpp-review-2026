//------------------------------------------------------------------
// [시험문제] 11/12 수업 (교수님 12:40 코드 기준, std:: / 괄호 규칙만 정리)
//
// 다운받은 "개들.txt"에 몇 마리인지 모르는 class Dog 객체가 기록되어 있다.
// 모두 읽어서 메모리(contiguous memory)에 저장하라.
// class Dog { private: std::string name; int age; }  이고
// ostream os 에  os << name << " " << age << std::endl;  로 기록하였다.
// 기록된 객체의 수는 최대 200을 넘지 않는다.
// age 기준 오름차순으로 정렬하라.
//
// 실행 결과 (Release / x64, 지금 개들.txt)
//	읽은 Dog 객체의 수 - 100
//	1번째 Dog - 나이 -     5, 이름 - wlr
//	2번째 Dog - 나이 -     8, 이름 - drngvrfgsupmds
//	...
//	100번째 Dog - 나이 -   998, 이름 - qfqwssvv
//
// 12:15 필기본의 dogs[cnt++] = dog; ++cnt; 는 cnt 를 두 번 올리는 버그 (200마리로 나옴)
//------------------------------------------------------------------

#include<iostream>
#include<fstream>
#include<string>
#include<print>

class Dog {
public:
	int getAge() const {
		return age;
	}

private:
	std::string name;
	int age;

	friend std::istream& operator>>(std::istream& is, Dog& dog);
	friend std::ostream& operator<<(std::ostream& os, const Dog& dog);
};

std::istream& operator>>(std::istream& is, Dog& dog)
{
	return is >> dog.name >> dog.age;
}

std::ostream& operator<<(std::ostream& os, const Dog& dog)
{
	std::println(os, "나이 - {:>5}, 이름 - {}", dog.age, dog.name);
	return os;
}

int ageAscend(const void* a, const void* b)
{
	return ((Dog*)a)->getAge() - ((Dog*)b)->getAge();
}

int main()
{
	std::ifstream in{ "개들.txt" };
	if (not in) {
		std::cout << "파일이 없다" << std::endl;
		return 20261112;
	}

	const int NUM{ 200 };
	Dog dogs[NUM];

	size_t cnt{};
	{
		Dog dog;
		while (in >> dog) {
			dogs[cnt] = dog;
			++cnt;
		}
	}

	std::cout << "읽은 Dog 객체의 수 - " << cnt << std::endl;

	qsort(dogs, cnt, sizeof(Dog), ageAscend);

	for (size_t i = 0; i < cnt; ++i) {
		std::cout << i + 1 << "번째 Dog - " << dogs[i] << std::endl;
	}
}
