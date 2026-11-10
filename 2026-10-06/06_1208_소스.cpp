/*
------------------------------------------
2026. 2 화 34목34		화34  (3주 1일)
------------------------------------------
자료형과 변수
------------------------------------------
*/





#include<iostream>

#include<print>
#include "save.h"

using namespace std;
//[문제] 사용자가 입력한 숫자만큼 int를 저장할 메모리를 확보해라
//그 메모리를 1부터 시작하는 정수로 채워라
//전체 합계를 계산하여 화면에 출력하라



int main() {

	int num{ 0 };
	cin >> num;

	// int a[num]; -> 돌리고 나서 num이 확정나기에, 에러남

	int* p = new int[num]; //시스템매니저한테 메모리 요청, 단 자리 없으면 요청이 실패가능. 반환값으로는 메모리 시작위치를 알려줌. 크기는 이미 아니까 그 범위 안에서 자유롭게 읽고쓸수잇음. 단 넘어가면 꼬인다.


	for (int i = 0;i < num; ++i) {
		p[i] = i + 1;
	}

	//합계
	int sum{};

	for (int i = 0; i < num;++i)
		sum += p[i];
	cout << "1부터 " << num << "까지의 합계 = " << sum << endl;

	//num의 주소
	cout << "num의 주소        : " << addressof(num) << endl;

	//p에 저장되있는 주소 - free store 주소
	cout << "p에 저장된 주소값 : " << hex<<(&p[0]) << endl;



	save("소스.cpp");

}
