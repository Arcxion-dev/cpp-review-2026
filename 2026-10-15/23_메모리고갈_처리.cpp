//------------------------------------------------------------------
// 메모리가 고갈되었을 때 처리 (try / catch)
// 버그 : 반복할 때마다 new 만 하고 delete[] 를 안 했음 → 반복 안에서 delete[]
//------------------------------------------------------------------

#include<iostream>

int main()
{
	int num{ 0 };
	while (true) {
		std::cin >> num;

		int* p;
		try {
			p = new int[num];
		}
		catch (std::exception& e) {
			std::cout << "메모리가 고갈되었을 때 : " << e.what() << std::endl;
			return 20261006;
		}

		for (int i = 0; i < num; ++i) {
			p[i] = i + 1;
		}

		long long sum{};
		for (int i = 0; i < num; ++i) {
			sum += p[i];
		}
		std::cout << "1부터 " << num << "까지의 합계 = " << sum << std::endl;

		delete[] p;
	}
}
