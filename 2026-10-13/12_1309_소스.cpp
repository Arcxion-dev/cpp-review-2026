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
#include<random>
#include "save.h"
using namespace std;

default_random_engine dre;
uniform_int_distribution uid{ 1000'0000 };


int x[10000000];

int compare(const void*, const void*);

int main() {
	save("소스.cpp");



	//[문제] 파일 "몇개인지모르는int"에는 정확하게 1000만개 int가 있다. 
	//전체 오름차순 정렬하라
	// 앞에서 200번째 값부터 10개를 화면에 출력하라.
	//값은 1번째 부터 센다


	std::ifstream in{ "몇개인지모르는int" };



	for (int i = 0; i < 10000000; ++i) {
		in >> x[i];
	}



	qsort(x, 10000000, sizeof(int), compare);

	for (int i = 0; i < 10; ++i) {
		cout << x[i] << endl;
	}
}

int compare(const void* p, const void* q)
{
	return *(int*)p - *(int*)q;
}
