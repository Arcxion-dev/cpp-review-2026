//------------------------------------------------------------------
// qsort 를 사용하여 s 를 오름차순으로 정렬하라.
// s 는 s[0] 부터 s[s.size()-1] 까지의 contiguous 메모리에 문자를 저장하고 있다
// 버그 : sizeof(string) → sizeof(char) / 포인터끼리 빼기 → 가리키는 문자끼리 빼기
//        개수를 s.size() - 1 로 해서 마지막 'g' 가 빠짐 → 개수는 s.size()
//------------------------------------------------------------------

#include<iostream>
#include<string>

int cmp(const void*, const void*);

int main()
{
	std::string s{ "The quick brown fox jumps over the lazy dog" };
	std::cout << s << std::endl;

	qsort(&s[0], s.size(), sizeof(char), cmp);
	std::cout << s << std::endl;
}

int cmp(const void* a, const void* b)
{
	return *(char*)a - *(char*)b;
}
