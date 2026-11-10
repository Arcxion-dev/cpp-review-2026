//------------------------------------------------------------------
// [문제] 주사위를 NUM 번 던졌다. 각 눈의 확률을 구하여라.
// 버그 : 10000번 던지고 1000. 으로 나눴음 → 항상 던진 횟수 NUM 으로 나눈다
//------------------------------------------------------------------

#include<iostream>
#include<random>
#include<format>

std::default_random_engine dre;
std::uniform_int_distribution uid{ 1, 6 };

int main()
{
	int count[6]{ 0, 0, 0, 0, 0, 0 };
	const int NUM{ 10000 };

	for (int i = 0; i < NUM; ++i) {
		++count[uid(dre) - 1];
	}

	for (int i = 0; i < 6; ++i) {
		std::cout << std::format("{:.2f}", count[i] / static_cast<double>(NUM)) << std::endl;
	}
}
