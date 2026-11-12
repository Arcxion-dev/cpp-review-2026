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




int main()
{
	std::string s{ "2026 11 12" };

	for (int i = 0; i < s.size();++i)
		cout << s.operator[](i) << endl;
	save("소스.cpp");

}
