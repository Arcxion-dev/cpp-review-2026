/*
------------------------------------------
2026. 2 화 34목34		화34  (1주 1일)
------------------------------------------
컴파일 화경 - Release/ x64
프로젝트 설정 - 최신 C++, SDL 검사 - 아니요
------------------------------------------
강의방식 - 출석점수 없음, 이동자유,
첫시간 - save 기능 작성.
------------------------------------------
*/



#include<iostream>
#include<string>
#include<fstream>




void save(std::string); // 함수 선언문

int main() {

	//  ::	-> scope resolution operator
	std::cout << "Hello World" << std::endl;
	std::cout << "Hello World" << "\n";


	save("소스.cpp"); // 기본적으론 char, 하지만 우린 str을 원해
	return 0;
}

void save(std::string fname) {


	std::cout << fname << "을 저장하겠습니다" << "\n";

	//fname울 읽기모드로 열기

	std::ifstream in{ fname };
	if (not in) {
		std::cout << "파일 열기 실패" << "\n";
		exit(20260902);
	}

	//한학기 강의 저장할 파일을 덧붙여 쓰기 모드로 연다
	std::ofstream out{ "2026 C++ 화34모34.txt", std::ios::app }; //RAII 방식 

	//읽을 파일에서 한글자를 읽어 쓸 파일에 기록한다


	//이 과정을 더 이상 읽을 글자가 없을 때까지 반복한다
	in >> std::noskipws;
	char c;
	while (in >> c) {
		out << c;
	}
}
 // 마지막 빈칸 -> end of file 문자가 있음. 난 안보이지만 존재해./*
------------------------------------------
2026. 2 화 34목34		화34  (1주 1일)
------------------------------------------
컴파일 화경 - Release/ x64
프로젝트 설정 - 최신 C++, SDL 검사 - 아니요
------------------------------------------
강의방식 - 출석점수 없음, 이동자유,
첫시간 - save 기능 작성.
------------------------------------------
*/



#include<iostream>
#include<string>
#include<fstream>




void save(std::string); // 함수 선언문

int main() {

	//  ::	-> scope resolution operator
	std::cout << "Hello World" << std::endl;
	std::cout << "Hello World" << "\n";


	save("소스.cpp"); // 기본적으론 char, 하지만 우린 str을 원해
	return 0;
}

void save(std::string fname) {


	std::cout << fname << "을 저장하겠습니다" << "\n";

	//fname울 읽기모드로 열기

	std::ifstream in{ fname };
	if (not in) {
		std::cout << "파일 열기 실패" << "\n";
		exit(20260902);
	}

	//한학기 강의 저장할 파일을 덧붙여 쓰기 모드로 연다
	std::ofstream out{ "2026 C++ 화34모34.txt", std::ios::app }; //RAII 방식 

	//읽을 파일에서 한글자를 읽어 쓸 파일에 기록한다


	//이 과정을 더 이상 읽을 글자가 없을 때까지 반복한다
	in >> std::noskipws;
	char c;
	while (in >> c) {
		out << c;
	}
}
 // 마지막 빈칸 -> end of file 문자가 있음. 난 안보이지만 존재해.
