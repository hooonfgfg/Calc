#pragma once
#include "header.h"

// baseCal : ����ϴ� ������ ��� ���
class BaseCal
{
protected: //�ڽ�Ŭ���� ����

	Cy_ListT<std::string> list; //���Ŀ� ���� ��꿡 ���� ����Ʈ(���ù��)
	Cy_ListT<std::string>::iterator iter; //����Ʈ �����ϱ� ���� iterator ����

	std::string str_arr; // ��Ʈ���� ���� ���� �迭

public:
	BaseCal() { list.clear(); }
	~BaseCal() { list.clear();}

	int Operator(int num1, int num2, std::string getOper); //�����ڸ� �̿��ؼ� ����� �����ϴ� �Լ�
	int Operator(int num1, int num2, ACHAR getOper);

	virtual int Calculation(std::string str) = 0; // ����ϴ� �˰���
};