/*
------------------------------------------
2026. 2 화 34목34		화34  (11주 1일)
------------------------------------------
class 연산자 오버로딩 [] , ()
------------------------------------------
*/

#include<iostream>
#include<string>
#include "save.h"

#include "Xtring.h"

using namespace std;
extern bool 관찰;


int 오름(const void* a, const void* b) {
	return *(char*)a - *(char*)b;
}

int main()
{
	string s{ "2026 11 12" };

	qsort(&s[0], s.size(), sizeof(char), 오름);
	save("소스.cpp");

}
