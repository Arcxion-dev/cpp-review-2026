//------------------------------------------------------------------
// [문제] "소스.cpp" 파일에 있는 소문자 중에서 사용자가 찾길 원하는 소문자가 모두 몇 개인지 출력하라.
// (원본은 문제만 있고 풀이가 비어 있었음)
//------------------------------------------------------------------

#include<iostream>
#include<fstream>

int main()
{
	std::cout << "찾을 소문자: ";
	char target;
	std::cin >> target;

	if (!islower(target)) {
		std::cout << "소문자가 아닙니다" << std::endl;
		return 1;
	}

	std::ifstream in{ "소스.cpp" };

	if (!in) {
		std::cout << "파일 열기 실패" << std::endl;
		return 20261015;
	}

	int count{ 0 };
	char ch;
	while (in >> ch) {
		if (ch == target) {
			++count;
		}
	}

	std::cout << target << " - " << count << "개" << std::endl;
}
