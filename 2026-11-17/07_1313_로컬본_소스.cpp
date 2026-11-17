/*
------------------------------------------
2026. 2 화 34목34		화34  (11주 1일)
------------------------------------------
class -  move semantic 구현 - () 오버로딩 - 이동이 어떻게 사용되나
------------------------------------------
*/

#include<iostream>
#include<string>
#include "save.h"
#include <algorithm> // std::sort 사용을 위해 필요
#include "Xtring.h"

using namespace std;
extern bool 관찰;


class Dog {
public: 
	void operator()(int n) {
		for(int i= 0; i < n; ++i)
			cout << "부르셨나요?" << endl;
	}

	bool operator() (int a, int  b) {
		return a > b;
	}

};

int main()
{
	Dog dog; // 호출가능 객체 - function object ** c++ 표준에서 function object를 functor라고 부르면 안된다.  **
	dog(3);


	int a[]{ 1,2,9,8,5,6,3,6,7,8,123,10 };
	sort(begin(a), end(a), dog);

	for (int num : a)
		cout << num << " ";

	cout << endl;
	save("save.cpp");

}
