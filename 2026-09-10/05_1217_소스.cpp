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
#include <string> // 파일 상단에 추가

int main() {
    

	save("소스.cpp");
    //C++ 프로그램이 실행되면 다음 4개 객체는 언제나 자동 생성된다
    //cout, cerr(에러출력), clog, cin(입력)

    //[문제] 구구단의 단을 입력받아서 구구단을 출력하라.

    std::cout << "구구단 입니다  " << std::endl;

    ////여기서 이름을 입력받음
    //int dan;
    //std::cin >> dan;

	//if (dan < 1 || dan > 9) {
	//	std::cout << "1~9 사이의 숫자를 입력하세요.\n";
	//	return 1; // 프로그램 종료
	//}

    for (int i = 0; i <= 9; i++)
    {

        for (int j = 1; j <= 9; ++j) {

            //std::println("{} * {} = {}", dan, i, dan * i);

            std::cout << i << " * " << j << " = " << j * i << "\n";
        }

		std::cout << "\n";
    }

}
