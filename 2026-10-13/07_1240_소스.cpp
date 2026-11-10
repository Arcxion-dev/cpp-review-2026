/*
------------------------------------------
2026. 2 화 34목34		화34  (3주 1일)
------------------------------------------
FILE I/O - 처리해야 할 자료가 플그램 밖의 파일에 있다,

중간소

------------------------------------------
*/


#include<iostream>
#include<fstream>
#include<random>
#include "save.h"
using namespace std;

default_random_engine dre;
uniform_int_distribution uid{ 1000'0000 };



int main() {
	save("소스.cpp");


	size_t num =  uid(dre) ;

	if (1000'0000 < num)
		num = 1000'0000;

	ofstream out{ "몇개인지모르는int" };
	for (int i = 0; i < num; ++i)
		out << uid(dre) << ' ';





}
