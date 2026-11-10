//-----------------------------------------------------------------
// save.cpp 한 학기 강의를 저장하는 함수
// 
// 2026. 9. 4 한 학기 강의를 저장하는 함수
//-----------------------------------------------------------------


#include "save.h"
#include "iostream"
#include "fstream"
#include "chrono"




void save(const std::string& fname) {


	std::cout << fname << "을 저장하겠습니다" << "\n";

	//fname울 읽기모드로 열기

	std::ifstream in{ fname };
	if (not in) {
		std::cout << "파일 열기 실패" << "\n";
		exit(20260902);
	}

	//한학기 강의 저장할 파일을 덧붙여 쓰기 모드로 연다
	std::ofstream out{ "2026 C++ 화34모34.txt", std::ios::app }; //RAII 방식 

	//현재 시간 알기
	auto now = std::chrono::system_clock::now();


	//저장한 시간을 파일에 기록한다
	out << "\n";
	out << "===================================" << "\n";
	out << "저장 시간: " << now << "\n";
	out << "===================================" << "\n";
	out << "\n";
	out << "\n";


	//읽을 파일에서 한글자를 읽어 쓸 파일에 기록한다
	//이 과정을 더 이상 읽을 글자가 없을 때까지 반복한다
	in >> std::noskipws;
	char c;
	while (in >> c) {
		out << c;
	}
}
