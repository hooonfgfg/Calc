#pragma once
#include "BaseCal.h"

// ����ڿ��� Ű����� �Է¹��� ���� �������� ���� ����� �������������� ó���Ͽ� �ַܼ� ����ϴ� Ŭ����
class MyCal : public BaseCal
{
private:
	int number=0;

public:
	int Calculation(std::string str);
};