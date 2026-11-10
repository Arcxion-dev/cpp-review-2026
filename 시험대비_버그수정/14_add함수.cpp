//------------------------------------------------------------------
// [문제] int 값 두 개를 전달받아 합계를 알려주는 함수 add 를 작성하라.
// 다음 코드가 문제없이 실행되어야 한다.
//------------------------------------------------------------------

#include<iostream>

int add(int, int);

int main()
{
	while (true) {
		std::cout << "합계를 계산합니다" << std::endl;

		int num1, num2;
		std::cin >> num1 >> num2;

		std::cout << "합계는 " << add(num1, num2) << std::endl;
	}
}

int add(int num1, int num2)
{
	return num1 + num2;
}
