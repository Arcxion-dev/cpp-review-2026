//------------------------------------------------------------------
// [문제] 1억 이하의 자연수를 한 개 입력받아
// 입력한 개수만큼 int 메모리를 확보하라
// 각 int 값을 [1, 999'9999] 사이의 랜덤값으로 할당하라
// 앞에서부터 100개, 뒤에서 역순으로 100개를 화면에 출력하라
//
// 버그 : 100개보다 적게 입력하면 범위 밖을 읽음
//        int i 와 size_t num 을 섞어 씀 → 모두 size_t
//        delete[] 누락
//------------------------------------------------------------------

#include<iostream>
#include<random>
#include<print>

std::default_random_engine dre;
std::uniform_int_distribution uid{ 1, 999'9999 };

int main()
{
	size_t num;
	std::cin >> num;

	if (num < 1 || num > 1'0000'0000) {
		std::cout << "1억 이하의 자연수를 입력하세요" << std::endl;
		return 1;
	}

	int* p = new int[num];

	for (size_t i = 0; i < num; ++i) {
		p[i] = uid(dre);
	}

	size_t show{ 100 };
	if (num < 100) {
		show = num;
	}

	for (size_t i = 0; i < show; ++i) {
		std::print("{:8}", p[i]);
	}
	std::cout << std::endl;
	std::cout << std::endl;

	for (size_t i = 0; i < show; ++i) {
		std::print("{:8}", p[num - 1 - i]);
	}
	std::cout << std::endl;

	delete[] p;
}
