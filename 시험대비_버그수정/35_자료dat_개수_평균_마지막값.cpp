//------------------------------------------------------------------
// [문제] "e-class" 에서 다운받은 "자료.dat" 파일에는 몇 개인지 모르는 int 가 저장되어 있다.
// 1. 모두 몇 개인지 출력한다
// 2. 평균값이 얼마인지 소수점 2자리까지 출력하라.
// 3. 오름차순 정렬 후 마지막 값을 화면에 출력하라
//
// ★ 메모리 엄격 - 변수는 필요한 { } 안에서만 살게 한다
//   cnt 는 뒤에서도 쓰니까 블록 밖, 처음 읽을 때만 쓰는 in1, i, sum 은 블록 안
//
// 버그 1 : static_cast<double>(sum / cnt) → 정수끼리 먼저 나눠서 소수점이 날아감
//          static_cast<double>(sum) / cnt 로 sum 을 먼저 double 로 바꾼다
// 버그 2 : 끝까지 읽은 in 으로 다시 읽으면 아무것도 안 읽힘
//          → 처음부터 다시 읽을 때는 파일을 새로 연다 (in1, in2)
// 버그 3 : {:.2} 가 아니라 {:.2f}
//------------------------------------------------------------------

#include<iostream>
#include<fstream>
#include<format>

int compare(const void*, const void*);

int main()
{
	size_t cnt{};
	{
		std::ifstream in1{ "자료.dat" };

		if (!in1) {
			std::cout << "파일 열기 실패" << std::endl;
			return 20261015;
		}

		int i;
		long long sum{};

		while (in1 >> i) {
			++cnt;
			sum += i;
		}

		std::cout << "총 : " << cnt << " 개" << std::endl;
		std::cout << "평균 : " << std::format("{:.2f}", static_cast<double>(sum) / cnt) << std::endl;
	}	// in1, i, sum 의 수명은 여기서 끝

	std::ifstream in2{ "자료.dat" };

	int* number = new int[cnt];
	for (size_t x = 0; x < cnt; ++x) {
		in2 >> number[x];
	}

	qsort(number, cnt, sizeof(int), compare);
	std::cout << "마지막 숫자 " << number[cnt - 1] << std::endl;

	delete[] number;
}

int compare(const void* a, const void* b)
{
	int num1 = *(const int*)a;
	int num2 = *(const int*)b;

	if (num1 < num2) {
		return -1;
	}
	if (num1 > num2) {
		return 1;
	}
	return 0;
}
