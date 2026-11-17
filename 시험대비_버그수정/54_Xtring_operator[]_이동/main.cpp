//------------------------------------------------------------------
// 11/12 ~ 11/17 수업 - operator[] (const 유무 오버로딩) + 이동생성 / 이동할당
// Xtring.h, Xtring.cpp 는 교수님 코드 그대로 (11/17 12:27)
// 빌드: cl /std:c++latest /EHsc main.cpp Xtring.cpp
//
// 실행 결과 (Release / x64)
//	2026 11 12  →  qsort(&s[0], ...) 후  "  01112226"
//	[ 2]생성(*)  글자수 16 / [ 3]이동생성 글자수 16 (같은 글자주소)
//	a 는 빈 줄 (이동 후 a 는 사용하면 안 됨 - UB, 여기서는 확인용)
//	2026년 11월 17일
//------------------------------------------------------------------
#include<iostream>
#include<cstdlib>
#include<utility>
#include "Xtring.h"

extern bool 관찰;

int 오름(const void* a, const void* b)
{
	return *(char*)a - *(char*)b;
}

int main()
{
	{
		Xtring s{ "2026 11 12" };
		qsort(&s[0], s.size(), sizeof(char), 오름);		// &s[0] → char& operator[] 필요
		std::cout << s << std::endl;
	}

	관찰 = true;
	Xtring a{ "2026년 11월 17일" };
	Xtring b = std::move(a);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
}
