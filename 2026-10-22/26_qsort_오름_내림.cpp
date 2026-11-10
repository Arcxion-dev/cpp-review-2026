//------------------------------------------------------------------
// qsort 로 정렬 - 오름차순, 내림차순
// (시작번지, 개수, 한 개의 크기, 어떻게)
// 버그 : uid{ 1'999'9999 } → 쉼표가 ' 로 바뀌어 숫자 하나(19999999)가 되어버림
//        delete[] 누락
//------------------------------------------------------------------

#include<iostream>
#include<random>
#include<print>

std::default_random_engine dre;
std::uniform_int_distribution uid{ 1, 999'9999 };

int compare(const void*, const void*);		// 오름차순
int compareDown(const void*, const void*);	// 내림차순

int main()
{
	size_t num;
	std::cin >> num;

	int* p = new int[num];
	for (size_t i = 0; i < num; ++i) {
		p[i] = uid(dre);
	}

	qsort(p, num, sizeof(int), compare);
	std::cout << "오름차순 정렬 후" << std::endl;
	for (size_t i = 0; i < num; ++i) {
		std::print(" {:8}", p[i]);
	}
	std::cout << std::endl;

	qsort(p, num, sizeof(int), compareDown);
	std::cout << "내림차순 정렬 후" << std::endl;
	for (size_t i = 0; i < num; ++i) {
		std::print(" {:8}", p[i]);
	}
	std::cout << std::endl;

	delete[] p;
}

int compare(const void* p, const void* q)
{
	int a = *(int*)p;
	int b = *(int*)q;

	if (a > b) {
		return 1;
	}
	else if (a < b) {
		return -1;
	}
	return 0;
}

int compareDown(const void* p, const void* q)
{
	int a = *(int*)p;
	int b = *(int*)q;

	if (a > b) {
		return -1;
	}
	else if (a < b) {
		return 1;
	}
	return 0;
}
