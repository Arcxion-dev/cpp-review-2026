//------------------------------------------------------------------
// num 의 정체를 알 수 있도록 보여주는 세 가지
// - 몇 바이트 메모리를 차지하나   - 어디에 있나   - 자료형은 무엇인가
//------------------------------------------------------------------

#include<iostream>

int main()
{
	int num;

	std::cout << "num의 크기	- " << sizeof num << std::endl;
	std::cout << "num의 주소	- " << std::addressof(num) << std::endl;
	std::cout << "num의 자료형	- " << typeid(num).name() << std::endl;
}
