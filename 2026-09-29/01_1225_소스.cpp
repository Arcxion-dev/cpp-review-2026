/*
------------------------------------------
2026. 2 화 34목34		화34  (3주 1일)
------------------------------------------
자료형과 변수
------------------------------------------
*/





#include<iostream>
#include<random>
#include<format>
#include "save.h"

using namespace std;

default_random_engine dre;
uniform_int_distribution uid{ 1, 6 };


int main() {

	save("소스.cpp");

	int a{ 922 }, b{ 2026 };

	//[문제] a의 값과 b의 값을 서로 바꿔라
	//다음 코드가 문제없이 실행 되어야 한다


	//C++의 해결책


	void change(int&, int&);

	change(a, b);
	cout << a << ", " << b << endl;


}

void change(int& p, int& q) {

	int t = p;
	p = q;
	q = t;
}
/*
------------------------------------------
2026. 2 화 34목34		화34  (3주 1일)
------------------------------------------
자료형과 변수
------------------------------------------
*/





#include<iostream>
#include<random>
#include<format>
#include "save.h"

using namespace std;

default_random_engine dre;
uniform_int_distribution uid{ 1, 6 };


int main() {



	//[문제] 프로그램이 정상 실행되는 NUM의 최대값을 구하여라.

	
	//256 * 4? 
	//4 * 2^8 = 1024 = 1mb;
	// 백만 / 4;
	//25만 근처
	//1024 * 1024 / 4

	const int NUM{ 256000 };

	int a[NUM];

	//a의 값을 1부터 NUM까지 int값으로 assign 한다
	for (int i = 0; i < NUM; ++i) {
		a[i] = i + 1;
	}


	//앞에서부터 100개 뒤에서부터 100개 출력
	for (int i = 0; i < 100; ++i) {
		cout << a[i] << ' ';
	}

	cout << endl;
	cout << endl;

	for (int i = 0; i < 100; i++)
	{
		cout << a[NUM - 1 - i] << ' ';
	}


	cout << endl;

	//save("소스.cpp");



}
