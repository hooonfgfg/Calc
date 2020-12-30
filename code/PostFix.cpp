#include "PostFix.h"

void PostFix::ReturnList(std::string oper)
{
	if (postNumberList.empty()) //��������� ����
		return;
	int num2 = *postNumberList.back();
	postNumberList.pop_back();
	int num1 = *postNumberList.back();
	postNumberList.pop_back();
	int result = Operator(num1, num2, oper);
	postNumberList.push_back(result); //��� ��� ����

	post.push_back(*list.back());
	//std::cout << *list.back() << ' ';
	list.pop_back();
}

int PostFix::ReturnValue()
{
	return *postNumberList.back();
}

void PostFix::DigitProcessing(int currentLocation) // 0~9 ������ ������ ��� �ݺ��� ���ڸ� ����-> ���ڷ� ��ȯ�ϴ� �޼ҵ�
{
	ten = 1; //�ʱ�ȭ
	finalNumber = 0; //�ʱ�ȭ

	for (int j = currentLocation; cy_isdigit(str_arr[j]); j++) //���� �ƴҶ����� �ݺ�
		lastLocation = j;

	for (int j = lastLocation; j >= currentLocation; j--)
	{
		finalNumber = finalNumber + (ten*(str_arr[j] - 48)); //���� ������ ���ϱ�
		ten *= 10; //10������ ���ϱ�
	}

	currentLocation = lastLocation; //���ڸ�������ġ ���� -> �ǳʶٱ�
	std::string getNum = std::to_string(finalNumber);
	post.push_back(getNum);
	//std::cout << getNum << ' '; //�ǿ�����
	postNumberList.push_back(finalNumber);
}

void PostFix::OperatorProcessing(int currentLocation) // ��
{
	std::string getch(1, str_arr[currentLocation]); //�ѹ��� ��Ʈ����

	if (getch == "*" || getch == "/") // * / �� ���� �켱������ �����Ƿ� push
	{
		while (!list.empty()) //������ ����Ʈ ���
		{
			if (*list.back() == "*" || *list.back() == "/")
			{
				ReturnList(*list.back());
			}
			else
				break;
		}
		list.push_back(getch);
	}
	else //+�� -�϶�
	{
		while (!list.empty()) //������ ����Ʈ ���
		{
			if (*list.back() == "*" || *list.back() == "/")
			{
				ReturnList(*list.back());
			}
			else
				break;
		}
		list.push_back(getch);
	}
}

void PostFix::ParenthesisProcessing(int currentLocation)
{
	std::string getch(1, str_arr[currentLocation]);

	if (getch == "(") //�켱 PUSH
		list.push_back(getch);

	else if (getch == ")") // ')' -> '(' ���� POP�� ���(��ȣ�� ����)
	{
		while (*list.back() != "(")
		{ //�����ڹۿ� �ȳ���
			ReturnList(*list.back());
		}list.pop_back(); //(���� ����
	}
}

int PostFix::Calculation(std::string str)
{
	str_arr = str;

	int arr_len = cy_strlenA(str_arr.c_str());

	for (int i = 0; i < arr_len; i++) //�迭 ��ȸ
	{
		if (cy_isdigit(str_arr[i])) //�����̸�
			DigitProcessing(i);

		else if (cy_isOperator_hjh(str_arr[i])) //������
			OperatorProcessing(i);

		else if (cy_isParenthesis_hjh(str_arr[i])) //��ȣ
			ParenthesisProcessing(i);

		else  continue;	//�� ���� ���ڵ� ���ĺ��̳� Ư�̼��� (PASS)
	}

	while (!list.empty()) //������ ����Ʈ ��ȯ
		ReturnList(*list.back());

	//std::cout << ReturnValue() << std::endl;
	return ReturnValue();
}