/*
------------------------------------------
2026. 2 화 34목34		화34  (2주 1일)
------------------------------------------
입력과 출력
------------------------------------------

*/



#include "save.h"
#include<iostream>
#include <print>
#include <string>

int main() {
    

	save("소스.cpp");
    //C++ 프로그램이 실행되면 다음 4개 객체는 언제나 자동 생성된다
    //cout, cerr(에러출력), clog, cin(입력)

    //[문제] int형 변수 2개를 입력받아 합계를 출력하라.
	
	std::cout << "두 정수를 입력하세요: " << std::endl;

    int a, b;
	std::cin >> a;
	std::cin >> b;
	std::cout << a + b << std::endl;


	save("소스.cpp");
}
