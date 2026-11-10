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


struct myData { 
	int x;
	int y; 

};


int main() {

	myData a;

	save("소스.cpp");

	//이때 mydata는 x , y각각해서 4 4 -> 8바이트
}
