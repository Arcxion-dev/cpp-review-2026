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


//capsulization, 추상화, 
class Player {  
private :  // access modifier - private:public : protected
	string name;
	int hp;
	int age;

};


int main()
{

	//Player a;

	//a.name = "Mario";


	//a.name = "Coupa";

	save("소스.cpp");


}
