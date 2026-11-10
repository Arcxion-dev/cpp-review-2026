//------------------------------------------------------------------
// 버블 정렬 - 오름차순, 내림차순 (descending order)
// 버그 : 한 번만 훑으면 가장 큰 값만 끝으로 간다 → 이중 for
//------------------------------------------------------------------

#include<iostream>
#include<random>
#include<print>

std::default_random_engine dre;
std::uniform_int_distribution uid{ 1, 999 };
const int NUM{ 1000 };

void change(int*, int*);

int main()
{
	int a[NUM];

	for (int i = 0; i < NUM; ++i) {
		a[i] = uid(dre);
	}

	//오름차순
	for (int i = 0; i < NUM - 1; ++i) {
		for (int k = 0; k < NUM - i - 1; ++k) {
			if (a[k] > a[k + 1]) {
				change(&a[k], &a[k + 1]);
			}
		}
	}

	for (int num : a) {
		std::print("{:8}", num);
	}
	std::cout << std::endl;
	std::cout << std::endl;

	//내림차순 - 비교만 반대
	for (int i = 0; i < NUM - 1; ++i) {
		for (int k = 0; k < NUM - i - 1; ++k) {
			if (a[k] < a[k + 1]) {
				change(&a[k], &a[k + 1]);
			}
		}
	}

	for (int num : a) {
		std::print("{:8}", num);
	}
	std::cout << std::endl;
}

void change(int* p, int* q)
{
	int temp{ *p };
	*p = *q;
	*q = temp;
}
