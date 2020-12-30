#pragma once
#include "header.h"

// baseCal : 계산하는 공통의 기능 담당
class BaseCal
{
protected: //자식클래스 참조

	Cy_ListT<std::string> list; //수식에 대한 계산에 사용될 리스트(스택방식)
	Cy_ListT<std::string>::iterator iter; //리스트 참조하기 위한 iterator 변수

	std::string str_arr; // 스트링형 수식 저장 배열

public:
	BaseCal() { list.clear(); }
	~BaseCal() { list.clear();}

	int Operator(int num1, int num2, std::string getOper); //연산자를 이용해서 계산결과 리턴하는 함수
	int Operator(int num1, int num2, ACHAR getOper);

	virtual int Calculation(std::string str) = 0; // 계산하는 알고리즘
};