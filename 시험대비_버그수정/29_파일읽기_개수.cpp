//------------------------------------------------------------------
// [문제] 파일 "int 100개.txt" 에는 몇 개인지 모르는 int 값이 저장되어 있다.
// int 값은 공백으로 서로 분리되어 있다
// 저장된 값을 읽어 화면에 출력하고 모두 몇 개인지도 출력하라.
//------------------------------------------------------------------

#include<iostream>
#include<fstream>

int main()
{
	std::ifstream in{ "int 100개.txt" };

	if (!in) {
		std::cout << "파일 열기 실패" << std::endl;
		return 20261013;
	}

	int num;
	int i{ 0 };

	while (in >> num) {
		std::cout << num << ' ';
		++i;
	}
	std::cout << std::endl;
	std::cout << "모두 " << i << "개" << std::endl;
}
