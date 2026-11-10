//------------------------------------------------------------------
// [문제] 파일 "몇개인지모르는int" 에서 가장 큰 값을 찾아 화면에 출력하라
// 몇 개인지도 출력하라
// 버그 : if (max < num) → 읽은 값은 n (변수 이름 실수)
//        최댓값 시작값은 int 의 가장 작은 값
//------------------------------------------------------------------

#include<iostream>
#include<fstream>
#include<numeric>

int main()
{
	std::ifstream in{ "몇개인지모르는int" };

	if (!in) {
		std::cout << "파일 열기 실패" << std::endl;
		return 20261013;
	}

	int n;
	int count{ 0 };
	int max{ std::numeric_limits<int>::min() };

	while (in >> n) {
		++count;
		if (max < n) {
			max = n;
		}
	}

	std::cout << "개수 " << count << std::endl;
	std::cout << "가장큰수 " << max << std::endl;
}
