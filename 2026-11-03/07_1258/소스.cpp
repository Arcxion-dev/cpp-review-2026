/*
------------------------------------------
2026. 2 화 34목34		화34  (3주 1일)
------------------------------------------
class - 6 special fucntions(5,6,7)

**생성자는 객체를 생성하지 않는다 - 생성되고 나서 색칠하는 함수다**
**소멸자는 객체를 소멸하지 않는다 - 색칠한걸 뒷정리 하는 함수다**. 
------------------------------------------
*/

#include<iostream>
#include<memory>
#include<print>
#include<windows.h>
#include<mmsystem.h>



#include "save.h"
#include "Xtring.h"

#pragma comment(lib, "winmm.lib")

using namespace std;


int main()
{
	

	save("소스.cpp");
	save("Xtring.cpp");
	save("Xtring.h");

	Xtring a{ "2026년 11월 3일" };

	Xtring b{ "화요일 34교시" };


	b = b; // 이 코드는 문법은 허용하지만 코딩할 이유는 없다
	b = a; // 복사 할당연산자를 이용하여 b와 a에 a를 할당한다
	

}
