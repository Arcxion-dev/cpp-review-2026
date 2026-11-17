/*
------------------------------------------
2026. 2 화 34목34		화34  (11주 1일)
------------------------------------------
class -  move semantic 구현 - () 오버로딩 - 이동이 어떻게 사용되나
------------------------------------------
*/

#include<iostream>
#include<string>
#include "save.h"

#include "Xtring.h"

using namespace std;
extern bool 관찰;


int main()
{

	string a{ "2026년 11월 17일" };
	string b = move(a);

	cout << a << endl;
	cout << b << endl;

	save("소스.cpp");
	save("Xtring.cpp");
	save("Xtring.h");

}
