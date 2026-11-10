/*
------------------------------------------
2026. 2 화 34목34		화34  (3주 1일)
------------------------------------------
class - 6 special functions
------------------------------------------
*/


#include<iostream>
#include "save.h"
using namespace std;


class Dog {

public:
	Dog() {
		cout << "생성자 함수가 호출되었다" << endl;
	}
	~Dog() {
		cout << "소멸자 함수가 호출되었다" << endl;
	}


private:
	string name;
	int age;
};

int main()
{
	Dog dog;
	
	cout << "2026/10/20 " << endl;
	


	save("소스.cpp");

}
