//------------------------------------------------------------------
// [문제] 가장 큰 unsigned int 값을 출력하라
// 버그 : 0B 리터럴이 8비트 5묶음(40비트)이었음 → 4묶음(32비트)
//        4 * 1024 * 1024 * 1024 - 1 은 int 끼리의 곱셈이라 넘쳐버림 → 사용하지 않는다
//------------------------------------------------------------------

#include<iostream>
#include<numeric>

int main()
{
	unsigned int a = 0B11111111'11111111'11111111'11111111;
	unsigned int b = 0XFF'FF'FF'FF;
	unsigned int c = std::numeric_limits<unsigned int>::max();

	//가장 큰 unsigned int = 4294967295
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
}
