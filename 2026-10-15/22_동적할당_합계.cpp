//------------------------------------------------------------------
// [문제] 사용자가 입력한 숫자만큼 int 를 저장할 메모리를 확보해라
// 그 메모리를 1부터 시작하는 정수로 채워라
// 전체 합계를 계산하여 화면에 출력하라
//
// 버그 : *p 는 주소가 아니라 첫 번째 int 값 → 주소는 &p[0]
//        int sum 은 넘칠 수 있음 → long long
//        delete[] 누락
//------------------------------------------------------------------

#include<iostream>

int g{};

int main()
{
	int num{ 0 };
	std::cin >> num;

	// int a[num]; -> 실행해야 num 이 정해지므로 에러

	int* p = new int[num];		// p 는 스택, p 가 가리키는 메모리는 free-store

	for (int i = 0; i < num; ++i) {
		p[i] = i + 1;
	}

	long long sum{};
	for (int i = 0; i < num; ++i) {
		sum += p[i];
	}
	std::cout << "1부터 " << num << "까지의 합계 = " << sum << std::endl;

	std::cout << "num의 주소 (STACK)       : " << std::addressof(num) << std::endl;
	std::cout << "p에 저장된 주소 (FREE)   : " << &p[0] << std::endl;
	std::cout << "DATA       주소          : " << &g << std::endl;
	std::cout << "CODE       주소          : " << std::addressof(main) << std::endl;

	delete[] p;
}
