//------------------------------------------------------------------
// 11/3 수업 - 파일 분리 (Xtring.h / Xtring.cpp / 이 파일)
// Xtring.h, Xtring.cpp 는 교수님 코드 그대로 (11/3 13:11 최종)
// 빌드: cl /std:c++latest /EHsc main.cpp Xtring.cpp
// 실행 결과: 내 글자수는 - 6 / 4 / 3 / 6   (& 덕분에 복사생성/소멸 없음)
// for (Xtring word : words) 로 바꾸면 매 바퀴 복사생성 → 출력 → 소멸() 이 찍힌다
//------------------------------------------------------------------
#include<iostream>
#include "Xtring.h"

extern bool 관찰;

int main()
{
	Xtring words[]{ "2026년", "11월", "3일", "화요일" };

	관찰 = true;
	for (Xtring& word : words) {
		std::cout << "내 글자수는 - " << word.size() << std::endl;
	}
	관찰 = false;
}
