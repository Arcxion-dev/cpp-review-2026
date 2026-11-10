/*
------------------------------------------
2026. 2 화 34목34		화34  (3주 1일)
------------------------------------------
강의의 가독서을 위해 std namespace를 열어놓겠다
학생들은 이렇게 코딩하지 않도록 찾아보고 알아둔다
자료형과 변수
------------------------------------------
*/



#include "save.h"
#include<iostream>
#include<numeric>
#include<bitset>


using namespace std; 

int main() {
	


	//unsigned int num = 4* 1024 * 1024 * 1024 -1;
	//unsigned int num = 0B11111111'11111111'11111111'11111111; 
	//unsigned int num = 0XFF'FF'FF'FF; 
	//unsigned int num = std::numeric_limits<unsigned int>::max(); 
	
	//[문제] int값을 입력하면 2진수로 바꿔 출력하라

	cout << "int 값을 입력하세요 ";
	int num;
	cin >> num;

	bitset<sizeof(int)> b = num ;

	//가장 큰 int = 4294967295
	cout << num << "는 이진수로 " << b << "입니다" <<endl;
	

	save("소스.cpp");
}
