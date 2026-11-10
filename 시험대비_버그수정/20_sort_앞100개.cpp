//------------------------------------------------------------------
// 100만 개를 sort 로 정렬하고 앞에서 100개 출력
// 4MB 라서 스택(1MB)에 못 올림 → 전역(DATA)
//------------------------------------------------------------------

#include<iostream>
#include<random>
#include<print>
#include<ranges>
#include<algorithm>

std::default_random_engine dre;
std::uniform_int_distribution uid{ 1, 99999 };
const int NUM{ 1000000 };

int a[NUM];

int main()
{
	for (int i = 0; i < NUM; ++i) {
		a[i] = uid(dre);
	}

	std::sort(std::begin(a), std::end(a));

	for (int num : a | std::views::take(100)) {
		std::print("{:8}", num);
	}
	std::cout << std::endl;
}
