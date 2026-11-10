//------------------------------------------------------------------
// 파일 "2026 C++ 화34모34.txt" 의 단어를 하나씩 읽어 출력하고 단어 개수를 출력
// 버그 : 처음엔 파일 이름에 .txt 를 빼먹어서 열리지 않았음 → 열기 실패 검사를 꼭 한다
// in >> word 는 공백/줄바꿈으로 구분된 덩어리 하나를 읽는다
//------------------------------------------------------------------

#include<iostream>
#include<fstream>
#include<string>

int main()
{
	std::ifstream in{ "2026 C++ 화34모34.txt" };

	if (!in) {
		std::cout << "파일 열기 실패" << std::endl;
		return 20261015;
	}

	std::string word;
	size_t cnt{};

	while (in >> word) {
		++cnt;
		std::cout << word << std::endl;
	}

	std::cout << "단어 개수 - " << cnt << std::endl;
}
