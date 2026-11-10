//------------------------------------------------------------------
// class - capsulization(캡슐화), 추상화
// access modifier - private: public: protected:
//
// private 멤버는 class 밖(main)에서 사용할 수 없다
//   a.name = "Mario";   → 컴파일 에러 (그래서 수업에서도 주석 처리)
// public 멤버는 밖에서 사용할 수 있다
//
// struct 와 class 의 차이 (숙제) → 시험 주의사항 부록 참고
//------------------------------------------------------------------

#include<iostream>
#include<string>

class Player {
private:
	std::string name;
	int hp;
	int age;
};

int main()
{
	Player a;

	//a.name = "Mario";		// private 이라 에러
}
