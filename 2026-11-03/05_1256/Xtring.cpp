#include<iostream>
#include<print>


#include "Xtring.h"

 //namespace 쓰지마라.

Xtring::Xtring()
	:len{ }, p{ nullptr }
{
	show("생성()");
}
Xtring::~Xtring()
{
	show("소멸()");

	if (p)
		delete[] p;
}

Xtring::Xtring(const char* s)
	: len{ strlen(s) }
{
	p = new char[len];
	memcpy(p, s, len);
	show("생성(*)");

};
	
Xtring::Xtring(const Xtring& other)
	: len{ other.len }
{
	p = new char[len];
	memcpy(p, other.p, len);
	show("복사생성");

}


Xtring& Xtring::operator=(const Xtring& other) {
	if (this == &other) {
		return *this;
	}

	//내가 확보했던 자원을 반환
	delete[] p;

	//other와 같은 내용으로 나를 만든다
	len = other.len;
	p = new char[len];
	memcpy(p, other.p, len);

	show("복사할당");

	return *this; //할당한 자신을 리턴

}

size_t Xtring::size() {
	return len;
}


void Xtring::show(const char* s) {
	std::print("{:8} {} {:<3} {}", s, (void*)/*void 포인터 = 주소로 보라는 뜻*/this, len, (void*)p);
	size_t num = 20;
	if (num < len)
		len = 20; // 교수님 num = 20이라 쓰셨는데 오타난듯? 아님말고
	std::cout.write(p ,num);
	std::cout << '\n';
}
