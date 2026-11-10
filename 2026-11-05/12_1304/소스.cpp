/*
------------------------------------------
2026. 2 화 34목34		화34  (9주 2일)
------------------------------------------
class - 6 special fucntions(5,6,7)

**생성자는 객체를 생성하지 않는다 - 생성되고 나서 색칠하는 함수다**
**소멸자는 객체를 소멸하지 않는다 - 색칠한걸 뒷정리 하는 함수다**. 
------------------------------------------
*/

#include<iostream>
#include<print>
#include<random>
#include "save.h"

#include "Xtring.h"

using namespace std;

extern bool 관찰;

default_random_engine dre;
//uniform_int_distribution uid{ 1,100 };
//uniform_int_distribution uidChar{ 'a', 'z' };

int main()
{
	관찰 = true;

	Xtring s{ "2026년" };
	Xtring t{ "11월 5일" };



	Xtring a { s + t };

	cout << a  << "--------" <<  123 << endl;
	//1. cout.operator<<(Xtring) - 표준변경. 수정하면안됨
	//2. operator<<(cou,Xtring) - 사용자 작성가능
	
	save("소스.cpp");
	save("Xtring.cpp");
	save("Xtring.h");


}
