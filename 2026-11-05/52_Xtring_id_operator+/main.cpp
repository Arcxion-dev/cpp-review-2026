//------------------------------------------------------------------
// 11/5 수업 - id 부여 + operator+ (Xtring.h / Xtring.cpp 는 교수님 코드 그대로, 11/5 12:38)
// 빌드: cl /std:c++latest /EHsc main.cpp Xtring.cpp
// 실행 결과: [1]생성(*) 6 / [2]생성(*) 8 / [3]생성() 0 (temp) / + 연산자 덮기... /
//           [3]소멸() 14 / [2]소멸() / [1]소멸()   ← 복사생성 없음 = RVO
// 주의: operator+ 안의 cout << temp.p 는 끝 표시가 없어 가끔 뒤에 쓰레기 글자가 붙음
//------------------------------------------------------------------
#include<iostream>
#include "Xtring.h"

extern bool 관찰;

int main()
{
	관찰 = true;

	Xtring s{ "2026년" };
	Xtring t{ "11월 5일" };

	Xtring a{ s + t };
}
