/*
------------------------------------------
2026. 2 화 34목34		화34  (3주 1일)
------------------------------------------
FILE I/O - 처리해야 할 자료가 플그램 밖의 파일에 있다,

중간소

------------------------------------------
*/


#INCLUDE<IOSTREAM>
#INCLUDE<FSTREAM>
#INCLUDE "SAVE.H"
USING NAMESPACE STD;

INT MAIN() {
	SAVE("소스.CPP");

	//[문제] "소스.CPP" 파일에 있는 소문자를 모두 대문자로 바꾼 "소스대문자.CPP"를 만들어라.
	
	IFSTREAM IN{ "소스.CPP" };
	OFSTREAM OUT{ "소스대문자.CPP" };
	CHAR CH;
	IN >> NOSKIPWS;
	WHILE (IN >> CH) {
		IF (ISLOWER(CH)) {
			CH = TOUPPER(CH);
		}
		OUT << CH;
	}

}
