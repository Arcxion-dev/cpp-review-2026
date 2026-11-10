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

extern bool 관찰;

int main()
{
	

	save("소스.cpp");
	
	관찰 = true;
	Xtring a[20];

}
