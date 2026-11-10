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
	


	//num의 정체를 알수 있도록 도와주는 언어의 기능
	// - 너 메모리 얼마나 차지하니/
	// - 너 어디에 살고있니? 
	// - 너 자료형이 뭐니
	int num; // 변수형	자료명

	std::cout << "num의 크기" << sizeof num << '\n';
	std::cout << "num의 주소" << std::addressof(num) << '\n';
	std::cout << "num의 자료형" << typeid(num).name() << '\n';

	

	save("소스.cpp");
}
