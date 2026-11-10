//------------------------------------------------------------------
// [문제] 파일 "몇개인지모르는int" 에는 정확하게 1000만 개 int 가 있다.
// 전체 오름차순 정렬하라
// 앞에서 200번째 값부터 10개를 화면에 출력하라.
// 값은 1번째부터 센다
// 버그 : x[0] 부터 출력했음 → 200번째는 x[199]
//------------------------------------------------------------------

#include<iostream>
#include<fstream>

int x[1000'0000];				// 40MB → 전역(DATA)

int compare(const void*, const void*);

int main()
{
	std::ifstream in{ "몇개인지모르는int" };

	if (!in) {
		std::cout << "파일 열기 실패" << std::endl;
		return 20261013;
	}

	for (int i = 0; i < 1000'0000; ++i) {
		in >> x[i];
	}

	qsort(x, 1000'0000, sizeof(int), compare);

	for (int i = 0; i < 10; ++i) {
		std::cout << x[i + 199] << std::endl;
	}
}

int compare(const void* p, const void* q)
{
	int a = *(int*)p;
	int b = *(int*)q;

	if (a > b) {
		return 1;
	}
	else if (a < b) {
		return -1;
	}
	return 0;
}
