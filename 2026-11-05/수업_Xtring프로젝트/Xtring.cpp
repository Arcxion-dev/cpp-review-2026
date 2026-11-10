#include<iostream>
#include<print>
#include "Xtring.h"

//------------------------------------------
//std :: string과 유사한 클래스
//
//
//
//2026년 11월 3일 - 파일 분리
//2026년 11월 5일 - id 부여
//2026년 11월 5일 - operator+
//-----------------------------------------


bool 관찰 { false };

int Xtring::gid{ 0 };



Xtring::Xtring()
	:id{++gid}, len {}, p{ nullptr }
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
	:id{ ++gid }, len{ strlen(s) }
{
	p = new char[len];
	memcpy(p, s, len);
	show("생성(*)");

};
	
Xtring::Xtring(const Xtring& other)
	:id{ ++gid }, len{ other.len }
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

Xtring Xtring::operator+(const Xtring& rhs) const {
	Xtring temp;

	temp.len = len + rhs.len;
	temp.p = new char[temp.len];
	memcpy(temp.p, this->p, this->len);
	memcpy(temp.p + this->len, rhs.p, rhs.len);
	
	return temp;

};


size_t Xtring::size() {
	return len;
}



void Xtring::show(const char* s){

	if (관찰 != true)
		return;
	std::print("[{:>5}]{:8} - 객체주소:{:<16} 글자수:{:<3} 글자주소{:<16}",id, s, (void*)/*void 포인터 = 주소로 보라는 뜻*/this, len, (void*)p);
	size_t num = len;
	if (20<num)
		num = 20; 
	std::cout << '\"';
	std::cout.write(p ,num);
	std::cout << "\"\n";
}

std::ostream& operator<<(std::ostream& os, const Xtring& s)  // 8바이트 이상이면 레퍼런스 달아야한데 istream 너무 크데 // 얜 멤버함수가 아니지만?! 멤버함수처럼??!  친구래 친구. 허헣헣 굉장히 
{
	os.write(s.p, s.len);
	return os;
}