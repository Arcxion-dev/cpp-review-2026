/*
------------------------------------------
2026. 2 화 34목34		화34  (11주 1일)
------------------------------------------
class -  move semantic 구현 - () 오버로딩 - 이동이 어떻게 사용되나
------------------------------------------
*/

#include<iostream>
#include<string>
#include "save.h"
#include <algorithm> 
#include <functional> 


#include "Xtring.h"

using namespace std;
extern bool 관찰;

//Inheritance 
//1 - 코드 재사용
//2 - 다형성


//[문제] 입력한 글자를 출력할때는 숫자부분을 *로 표시하는 기능을 구현
//예) 2026abcd
//	-> ****abcd



class StarXtring : public Xtring {
	
};

int main()
{

	cout << "암호를 입력하세요 :  ";
	StarXtring a;
	cin >> a;

	cout << a << endl;

	save("소스.cpp");
	save("Xtring.h");
	save("Xtring.cpp");
}
