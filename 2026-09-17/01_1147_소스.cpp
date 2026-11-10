/*
------------------------------------------
2026. 2 화 34목34		화34  (3주 1일)
------------------------------------------
강의의 가독서을 위해 std namespace를 열어놓겠다
학생들은 이렇게 코딩하지 않도록 찾아보고 알아둔다
자료형과 변수
------------------------------------------
*/



#include<iostream>
#include "save.h"

using namespace std; 



int main() {
	
	save("소스.cpp");
	int num[100];
	char c;
	float f;
	double d;


	cout << "크기 - " << sizeof num << endl;
	cout << "주소 - " << addressof(num) << endl;
	cout << "타입 - " << typeid(num).name() << endl;

}
