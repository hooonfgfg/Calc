#pragma once
#include "BaseCal.h"

// 사용자에게 키보드로 입력받은 값을 기준으로 계산기 기능을 후위연산방식으로 처리하여 콘솔로 출력하는 클래스
class PostFix : public BaseCal
{
private:
	int finalNumber = 0; //숫자 최종추출값
	int lastLocation; //마지막 위치
	int ten; //자릿수 계산 변수(10단위)

	Cy_ListT <std::string> post; //후위 스택
	Cy_ListT <INT32> postNumberList; //숫자 저장-> 최종결과만 남는 리스트
	
protected:

	void DigitProcessing(int currentLocation); // 숫자 처리 메소드
	void OperatorProcessing(int currentLocation); // 연산자 처리 메소드
	void ParenthesisProcessing(int currentLocation); //괄호 처리 메소드

	void ReturnList(std::string oper); //후위스택 알고리즘 (정답 포함)
	
	int Calculation(std::string str);
};
