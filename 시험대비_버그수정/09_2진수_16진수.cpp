//------------------------------------------------------------------
// [문제] int 값을 입력하면 2진수와 16진수로 바꿔 출력하라
// 버그 : bitset<sizeof(int)> 는 4비트 → sizeof(int) * 8
//        hex 는 한 번 설정하면 계속 유지됨 → while(true) 로 반복하면
//        두 번째부터는 10진수 자리까지 16진수로 찍힌다 → 한 번만 입력받는다
//------------------------------------------------------------------

#include<iostream>
#include<bitset>

int main()
{
	std::cout << "int 값을 입력하세요 ";
	int num;
	std::cin >> num;

	std::bitset<sizeof(int) * 8> b = num;

	std::cout << num << "는 2진수로 0B" << b << "입니다" << std::endl;
	std::cout << num << "는 16진수로 0X" << std::hex << num << "입니다" << std::endl;
}
