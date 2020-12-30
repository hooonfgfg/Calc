#pragma once
#include "BaseCal.h"

// 사용자에게 키보드로 입력받은 값을 기준으로 계산기 기능을 후위연산방식으로 처리하여 콘솔로 출력하는 클래스
class MyCal : public BaseCal
{
private:
	int number=0;

public:
	int Calculation(std::string str);
};