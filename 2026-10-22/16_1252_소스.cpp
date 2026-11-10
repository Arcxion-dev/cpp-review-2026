/*
------------------------------------------
2026. 2 화 34목34		화34  (3주 1일)
------------------------------------------
class - 6 special functions (56)
------------------------------------------
*/


#include<iostream>
#include<memory>
#include<print>
#include "save.h"
using namespace std;

int main()
{
	save("소스.cpp");

	string s{ "2026년 10월 22일 string 시작" };
	cout << "string 이 관리하는 글자 개수 - " << s.size() << endl;
	cout << "string이 관리하는 글자메모리의 시작번지 - " << s.data() << endl;
}
