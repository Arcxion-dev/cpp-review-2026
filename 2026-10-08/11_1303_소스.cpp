/*
------------------------------------------
2026. 2 화 34목34		화34  (3주 1일)
------------------------------------------
자료형과 변수
------------------------------------------
*/


#include<iostream>
#include<string>
#include "save.h"

using namespace std;

int cmp(const void*, const void*);

int main() {
	save("소스.cpp");

	string s{ "The quick brown fox jumps over the lazy dog"s };
	cout << s << endl;

	//qsort 를 사용하여 s를 오름차순으로 정렬하라.
	//s는 s[0] 부터 s[s.size()-1]까지의 contiguous 메모리에 문자를 저장하고 있다


	qsort(&s[0], s.size() - 1, sizeof(string), cmp);
	
}

int cmp(const void* a, const void* b) {
	return (char*)a - (char*)b;
}
