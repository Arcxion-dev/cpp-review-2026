//------------------------------------------
//std :: string과 유사한 클래스
//
//
//
//2026년 11월 3일 - 파일 분리
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

	Xtring(Xtring&& other) = default;											//5 - 이동생성자
	Xtring& operator = (Xtring&&/*right value reference로 읽는다*/) = default;	//6 - 이동할당연산자

	size_t size();


	void show(const char*);																//모든 관찰가능한 내용을 다 적도록 하겠다.
private:
	size_t len;
	char* p;

};
