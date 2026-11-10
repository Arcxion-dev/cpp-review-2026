//------------------------------------------------------------------
// int 100개를 저장할 메모리에 랜덤값을 저장하였다.
// [문제] num 의 값을 4칸에 맞춰 모두 출력해 보세요.
// [문제] 가장 큰 값을 찾아 화면에 출력하라
// 버그 : index 를 증가시키지 않아 같은 값만 출력 / 최댓값을 구하고 출력하지 않음
//        최댓값의 시작값은 0 이 아니라 int 의 가장 작은 값
//------------------------------------------------------------------

#include<iostream>
#include<random>
#include<format>
#include<numeric>

std::default_random_engine dre;
std::uniform_int_distribution uid{ 1, 999 };

int main()
{
	int num[100];

	for (int i = 0; i < 100; ++i) {
		num[i] = uid(dre);
	}

	int index = 0;
	for (int i = 0; i < 25; ++i) {
		for (int k = 0; k < 4; ++k) {
			std::cout << std::format("{:4}", num[index]);
			++index;
		}
		std::cout << std::endl;
	}

	int greatest{ std::numeric_limits<int>::min() };
	for (int i = 0; i < 100; ++i) {
		if (num[i] > greatest) {
			greatest = num[i];
		}
	}
	std::cout << "가장 큰 값 - " << greatest << std::endl;
}
