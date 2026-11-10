//------------------------------------------------------------------
// 사용자 정의 자료형 - struct
// Point2D 100개에 [-100, 100] 랜덤 좌표를 넣고 모두 출력
// [문제] 원점에서 폭탄이 터졌다. 반경 20 이하의 점들은 영향을 받는다
//        어떤 점들이 영향을 받았나 출력하라
//
// 버그 : Point2D points[1000] 을 만들고 100개만 채움 → 나머지 900개는 쓰레기값인데 range-for 로 다 출력
//        sqrt(...) < 20 → "이하" 이므로 <= 이고, 제곱끼리 비교하면 sqrt 가 필요 없다
//        cnt++ → ++cnt
//
// 메모리 그림 (points, this.png)
// · 스택에 8바이트(x 4 + y 4)짜리 Point2D 가 연달아 100개. points 는 그 시작 번지
// · show 는 CODE 에 하나만 있다 (객체마다 따로 있지 않음 → sizeof(Point2D) 는 8)
// · points[i].show() 를 부르면 숨은 인자로 points[i] 의 시작 번지가 전달된다 → this pointer
//   show 안의 x 는 this->x 와 같다
//------------------------------------------------------------------

#include<iostream>
#include<random>
#include<print>

std::default_random_engine dre;
std::uniform_int_distribution uid{ -100, 100 };

struct Point2D {
	//멤버 변수
	int x;
	int y;

	//멤버 함수
	void show() {
		std::println("( {:4}, {:4} )", x, y);		// this->x, this->y 와 같다
	}
};

int main()
{
	Point2D points[100];

	for (int i = 0; i < 100; ++i) {
		points[i].x = uid(dre);
		points[i].y = uid(dre);
	}

	for (Point2D point : points) {
		point.show();
	}

	std::cout << std::endl;

	size_t cnt{};
	for (int i = 0; i < 100; ++i) {
		if (points[i].x * points[i].x + points[i].y * points[i].y <= 20 * 20) {
			std::cout << i << "번째		";
			points[i].show();
			++cnt;
		}
	}

	std::cout << cnt << " 개" << std::endl;
}
