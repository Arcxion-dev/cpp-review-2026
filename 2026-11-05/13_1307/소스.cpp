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
uniform_int_distribution uid{ 1,100 };
uniform_int_distribution<int> uidChar{ 'a', 'z' };

int main()
{
	Xtring words[100];
	for (Xtring& word : words) {

		string s;
		for (int i = 0; i < uid(dre); ++i)
		{
			s += uidChar(dre);
		}

		word = s.data();
	}
	//1. cout.operator<<(Xtring) - 표준변경. 수정하면안됨
	//2. operator<<(cou,Xtring) - 사용자 작성가능
	
	for (const Xtring& word : words)
		cout << word << endl;

	save("소스.cpp");
	save("Xtring.cpp");
	save("Xtring.h");


}
