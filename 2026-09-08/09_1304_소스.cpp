/*
------------------------------------------
2026. 2 화 34목34		화34  (2주 1일)
------------------------------------------
입력과 출력
------------------------------------------

*/



#include "save.h"
#include<iostream>
#include <string> // 파일 상단에 추가

int main() {
    

	save("소스.cpp");
    //C++ 프로그램이 실행되면 다음 4개 객체는 언제나 자동 생성된다
    //cout, cerr(에러출력), clog, cin(입력)

    //[문제] 이름을 입력받아서 환영 인사를 하자.

    std::cout << "이름을 입력하세요: ";

    //여기서 이름을 입력받음
    std::string name;
    std::cin >> name;

    int cnt{};
    while (true) {
        std::cout << name << "님, 반갑습니다!";
        cnt++;
		for (int i = 0; i < cnt; ++i) {
            std::cout << "!";
		}
		std::cout << "\n";
    }
}
