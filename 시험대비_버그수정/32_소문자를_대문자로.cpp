//------------------------------------------------------------------
// [문제] "소스.cpp" 파일에 있는 소문자를 모두 대문자로 바꾼 "소스대문자.cpp" 를 만들어라.
// 버그 : in >> ch 는 공백과 줄바꿈을 건너뜀 → noskipws
//------------------------------------------------------------------

#include<iostream>
#include<fstream>

int main()
{
	std::ifstream in{ "소스.cpp" };
	std::ofstream out{ "소스대문자.cpp" };

	char ch;
	in >> std::noskipws;
	while (in >> ch) {
		if (islower(ch)) {
			ch = char(toupper(ch));
		}
		out << ch;
	}
}
