//------------------------------------------
//std :: string과 유사한 클래스
//
//
//
//2026년 11월 3일 - 파일 분리
//2026년 11월 5일 - 객체 고유 번호 부여
//2026년 11월 5일 - 연산자 오버로딩 시작 + 
//2026년 11월 5일 - 출력연산자 오버로딩 - friend로 코딩한다
//2026년 11월 10일 - 멤버가 아닌 연산자 함수 - friend로 코딩한다
//2026년 11월 12일 - class 연산자 오버로딩 [] , ()
//2026년 11월 17일 - 이동문법 지원
//2026년 11월 19일 - 입력연산자
//-----------------------------------------


#pragma once

//헤더파일의 용도는 바깥세상에 이런 함수들이 있다고 보여주는거. cpp 내용은 안보여주는거다. 

class Xtring {
public:
	Xtring();																	// 1 - 디볼트 생성자
	~Xtring();																	// 2 - 소멸자

	Xtring(const char* s);


	Xtring(const Xtring& other);												// 3 - 복사생성자
	Xtring& operator=(const Xtring& other);										// 4 - 복사할당연산자

	Xtring(Xtring&& other);														// 5 - 이동생성자
	Xtring& operator = (Xtring&&/*right value reference로 읽는다*/);			// 6 - 이동할당연산자


	Xtring operator+(const Xtring& rhs) const;


	char operator[](size_t idx) const;
	char& operator[](size_t idx); //const 유무로 오버로딩을 구분한다


	size_t size() const;														//2026.11.17 const


	void show(const char*);														// 모든 관찰가능한 내용을 다 적도록 하겠다.
	
	

private:
	size_t len;
	char* p;
	
	int id;																		// object 생성시 부여

	static int gid;																// class static 맴버 찾아보세요

 
	friend std::ostream& operator<<(std::ostream& os, const Xtring& s); 
	// 2026.11. 19
	friend std::istream& operator>>(std::istream& is,  Xtring& s); 


	// 2026. 11. 30
	friend Xtring operator+(const char*, const Xtring&);
	
	
};
