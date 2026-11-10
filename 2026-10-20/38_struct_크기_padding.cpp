//------------------------------------------------------------------
// struct 의 크기와 padding
//
// MyData1 { int x; int y; }   → 4 + 4 = 8 바이트
// MyData2 { char x; int y; }  → 1 + 4 = 5 가 아니라 8 바이트
//   [ 1:x ][ 빈공간 3 ][     4:y     ]   ← 빈공간을 padding 이라고 한다
// MyData3 alignas(16)          → 16 바이트 (맞춤을 16 으로 키우면 padding 이 늘어난다)
//------------------------------------------------------------------

#include<iostream>

struct MyData1 {
	int x;
	int y;
};

struct MyData2 {
	char x;
	int y;
};

struct alignas(16) MyData3 {
	char x;
	int y;
};

int main()
{
	std::cout << "MyData1 - " << sizeof(MyData1) << std::endl;
	std::cout << "MyData2 - " << sizeof(MyData2) << std::endl;
	std::cout << "MyData3 - " << sizeof(MyData3) << std::endl;
}
