/*
------------------------------------------
2026. 2 화 34목34		화34  (3주 1일)
------------------------------------------
FILE I/O - 처리해야 할 자료가 플그램 밖의 파일에 있다,

중간소

------------------------------------------
*/


#include<iostream>
#include<fstream>
#include<format>
#include<print>
#include "save.h"
using namespace std;


int compare(const void*, const void*);

int main() {
	save("소스.cpp");

	//[문제] "e-class"에서 다운받은 "자료.dat" 파일에는 몇개인지 모르는 int가 저장되어 있다.
	//1. 모두 몇개인지 출력한다
	//2. 평균값이 얼마인지 소수점 2자리까지 출력하라.
	//3. 오름차순 정렬 후 마지막 값을 화면에 출력하라
	//

	ifstream in1{ "자료.dat" };
	ifstream in2{ "자료.dat" };

	int i;
	size_t cnt{};
	long long sum{};
	
	while (in1 >> i) {
		++cnt;
		sum += i;
	}

	int* number = new int[cnt];


	for (int x = 0; x < cnt; ++x) {
		in2 >> number[x];
	}


	qsort(number, cnt, sizeof(int), compare);

	cout << "총 : " << cnt << " 개" << endl;
	cout << "평균 : " << format("{:.2f}", static_cast<double>(sum / cnt)) << endl;
	cout << "마지막 숫자 " << (number[cnt - 1]) << endl;


	delete[] number;
}



int compare(const void* a, const void* b) {
	int num1 = *(const int*)a;
	int num2 = *(const int*)b;

	if (num1 < num2) return -1;
	if (num1 > num2) return 1;
	return 0;
}
