/*
------------------------------------------
2026. 2 화 34목34		화34  (3주 1일)
------------------------------------------
사용자 정의 자료형
------------------------------------------
*/




#include<iostream>
#include<random>
#include<print>
#include "save.h"
using namespace std;


default_random_engine dre;
uniform_int_distribution uid{ -100,100 };

//struct와 class의 차이점을 찾아보세요
struct Point2D { //괄호조심

	//멤버 변수
	int x;
	int y;

	//함수도 내가 만들수 있다. - 멤버 함수
	void show() {
		/*cout << "( " << x << ", " << y << " )" << endl;*/
		
		//멤버함수 숨겾ㄴ 인자가 있다
		//어떤 객체를 사용하여 show 멤버를 호출한 것인지 구분하기 위한 this pointer
		
		//println("( {:4}, {:4}) ", this ->x,this->y);
		println("( {:4}, {:4}) ", x,y);
		
	}
};


int main() {

	Point2D points[100];

	for (int i = 0; i < 100; ++i) {
		points[i].x = uid(dre);
		points[i].y = uid(dre);
	}

	for (Point2D point : points) {
		point.show();
	}

	//[문제] 원점에서 폭탄이 터졌다. 반경 20 이하의 점들은 영향을 받는다
	//어떤 점들이 영향을 받았나 출력하라


	size_t cnt{};
	for (int i = 0; i < 100; ++i) {
		if ((points[i].x * points[i].x + points[i].y * points[i].y) <= 20 * 20) {
			cout << i << "번쨰		";
			points[i].show();
			cout << endl;
			cnt++;
		}

	}

	cout << cnt << " 개" << endl;



	save("소스.cpp");


	//개념 : 스택에 크기 8짜리 공간 연달아 100개. points가 어디인지 알아야함. 
	//멤버함수는 어떤 함수가 호출했는지 시작번지를 받음. show 함수안에 this->x , 소
}
