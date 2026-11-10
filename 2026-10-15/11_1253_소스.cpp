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
	int x;
	int y;
};


int main() {

	Point2D a{ 1,2 };

	cout << a.x << ", " << a.y << endl;

	save("소스.cpp");

}
