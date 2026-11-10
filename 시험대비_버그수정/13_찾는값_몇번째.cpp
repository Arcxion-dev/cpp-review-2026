//------------------------------------------------------------------
// [문제] 자료 중에서 찾는 값을 물어보고 있으면 몇 번째 있는지, 없으면 없다라고 대답하라.
// 버그 : 문제는 "몇 번째" 인데 존재 여부만 출력했음
// 관계 연산자 (relational operator) < <= > >= == !=
//------------------------------------------------------------------

#include<iostream>
#include<random>
#include<print>

std::default_random_engine dre;
std::uniform_int_distribution uid{ 1, 999 };

int main()
{
	int num[1'0000];
	for (int i = 0; i < 1'0000; ++i) {
		num[i] = uid(dre);
	}

	for (int i = 0; i < 1'0000; ++i) {
		std::print("{:8}", num[i]);
	}
	std::cout << std::endl;

	while (true) {
		int target{};
		std::cin >> target;

		int pos{ -1 };
		for (int i = 0; i < 1'0000; ++i) {
			if (num[i] == target) {
				pos = i;
				break;
			}
		}

		if (pos != -1) {
			std::cout << pos + 1 << "번째에 있습니다" << std::endl;
		}
		else {
			std::cout << "존재하지 않습니다" << std::endl;
		}
	}
}
