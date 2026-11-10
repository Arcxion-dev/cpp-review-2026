#include<iostream>


#include "Xtring.h"


	Xtring::Xtring() :len{ }, p{ nullptr }
	{
	}
	Xtring::~Xtring()
	{
		if (p)
			delete[] p;
	}

	Xtring::Xtring(const char* s)
		: len{ strlen(s) }
	{
		p = new char[len];
		memcpy(p, s, len);

	};

	Xtring::Xtring(const Xtring& other)
		: len{ other.len }
	{
		p = new char[len];
		memcpy(p, other.p, len);
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

		return *this; //할당한 자신을 리턴

	}

	size_t Xtring::size() {
		return len;
	}


	void Xtring::show() {
	}
