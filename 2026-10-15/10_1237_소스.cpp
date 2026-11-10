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

	ifstream in{ "2026 C++ 화34모34.txt" };


	string word;

	size_t cnt{};
	while (in >> word) {
		++cnt;

		cout << word << endl;
	}
	cout << "단어 개수 - " << cnt;
}
