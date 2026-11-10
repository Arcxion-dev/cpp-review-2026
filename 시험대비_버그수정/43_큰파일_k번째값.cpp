//------------------------------------------------------------------
// [문제] 파일 "몇개인지모르는int" 에는 몇 개인지 모르는 int 가 저장되어 있다.
// 전체를 오름차순 정렬하고, 앞에서 k번째 값부터 10개를 화면에 출력하라.
// 값은 1번째부터 센다.
//
// 1. 개수를 모른다 → 먼저 한 번 읽어서 개수 cnt 를 센다
//    in1 은 개수 셀 때만 필요하니 블록 { } 안에서만 살게 한다 (메모리 엄격)
// 2. 1000만 개면 40MB → 스택(1MB)에는 못 올림
//    개수를 실행해야 알 수 있으니 new 로 딱 cnt 개만 free-store 에 확보
// 3. 처음부터 다시 읽을 때는 파일을 새로 연다 (in2)
// 4. qsort 로 오름차순 정렬 → k번째는 p[k - 1]
// 5. delete[] p
//------------------------------------------------------------------

#include<iostream>
#include<fstream>

int compare(const void*, const void*);

int main()
{
	size_t cnt{};
	{
		std::ifstream in1{ "몇개인지모르는int" };

		if (!in1) {
			std::cout << "파일 열기 실패" << std::endl;
			return 20261020;
		}

		int num;
		while (in1 >> num) {
			++cnt;
		}
	}	// in1, num 의 수명은 여기서 끝

	std::cout << "개수 - " << cnt << std::endl;

	if (cnt < 1) {
		std::cout << "자료가 없습니다" << std::endl;
		return 20261020;
	}

	std::cout << "몇 번째부터? ";
	size_t k;
	std::cin >> k;

	if (k < 1 || k > cnt) {
		std::cout << "1 ~ " << cnt << " 사이로 입력하세요" << std::endl;
		return 20261020;
	}

	int* p = new int[cnt];
	{
		std::ifstream in2{ "몇개인지모르는int" };
		for (size_t i = 0; i < cnt; ++i) {
			in2 >> p[i];
		}
	}	// in2 의 수명은 여기서 끝

	qsort(p, cnt, sizeof(int), compare);

	for (size_t i = k - 1; i < k - 1 + 10; ++i) {
		if (i < cnt) {
			std::cout << i + 1 << "번째 - " << p[i] << std::endl;
		}
	}

	delete[] p;
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
