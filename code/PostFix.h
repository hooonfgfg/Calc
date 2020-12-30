#pragma once
#include "BaseCal.h"

// ����ڿ��� Ű����� �Է¹��� ���� �������� ���� ����� �������������� ó���Ͽ� �ַܼ� ����ϴ� Ŭ����
class PostFix : public BaseCal
{
private:
	int finalNumber = 0; //���� �������Ⱚ
	int lastLocation; //������ ��ġ
	int ten; //�ڸ��� ��� ����(10����)

	Cy_ListT <std::string> post; //���� ����
	Cy_ListT <INT32> postNumberList; //���� ����-> ��������� ���� ����Ʈ
	
protected:

	void DigitProcessing(int currentLocation); // ���� ó�� �޼ҵ�
	void OperatorProcessing(int currentLocation); // ������ ó�� �޼ҵ�
	void ParenthesisProcessing(int currentLocation); //��ȣ ó�� �޼ҵ�

	void ReturnList(std::string oper); //�������� �˰��� (���� ����)
	
	int ReturnValue(); //�� ����
	int Calculation(std::string str);
};