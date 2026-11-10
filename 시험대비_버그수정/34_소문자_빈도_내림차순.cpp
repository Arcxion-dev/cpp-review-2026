//------------------------------------------------------------------
// [문제] "소스.cpp" 파일에 있는 소문자를 많이 나온 순서로 내림차순 정렬하라
// (원본은 문제만 있고 풀이가 비어 있었음)
// count[0] 은 'a', count[1] 은 'b' ... count[25] 는 'z' 의 개수
// 가장 많은 것을 찾아 출력하고 -1 로 지우는 일을 26번 반복
//------------------------------------------------------------------

#include<iostream>
#include<fstream>

int main()
{
	std::ifstream in{ "소스.cpp" };

	if (!in) {
		std::cout << "파일 열기 실패" << std::endl;
		return 20261015;
	}

	int count[26]{};

	char ch;
	while (in >> ch) {
		if (islower(ch)) {
			++count[ch - 'a'];
		}
	}

	for (int k = 0; k < 26; ++k) {
		int greatest{ 0 };
		for (int i = 1; i < 26; ++i) {
			if (count[i] > count[greatest]) {
				greatest = i;
			}
		}

		if (count[greatest] <= 0) {
			break;
		}

		std::cout << char('a' + greatest) << " - " << count[greatest] << std::endl;
		count[greatest] = -1;
	}
}
