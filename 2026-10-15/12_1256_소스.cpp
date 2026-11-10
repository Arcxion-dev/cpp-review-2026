/*
------------------------------------------
2026. 2 화 34목34		화34  (3주 1일)
------------------------------------------
사용자 정의 자료형
------------------------------------------
*/


#include<iostream>
#include "save.h"
using namespace std;

//struct와 class의 차이점을 찾아보세요
struct Point2D { //괄호조심

	//멤버 변수
	int x;
	int y;

	//함수도 내가 만들수 있다. - 멤버 함수
	void show() {
		cout << "( " << x << ", " << y << " )" << endl;
	}
};


int main() {

	Point2D a{ 1,2 };

	a.show();

	save("소스.cpp");

}
