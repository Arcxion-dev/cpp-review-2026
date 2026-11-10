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


struct alignas(16) myData { 
	char x;
	int y; 

};


int main() {

	myData a;

	save("소스.cpp");

	//이때 mydata는 1바이트 4바이트하면 5바이트라 해야되는데 왜 마우스올려보면 8바이트라 뜰까? 
	// 64기계는 8바이트씩 움직이는게 더 편해서
	// 데이터 그림 [ 1:x][  빈공간][    4:y      ] 으로 그리면 된다. 네모나게. 빈공간을 padding이라고 한다. 빈공간을 16 64 등으로 얼마든지 맞출수 있고 조절할수 있다. 
	//그런데 이거 패딩하기 싫은데? 그럼 위처럼 alignas 쓰면됨
}
