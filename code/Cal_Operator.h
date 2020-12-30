#include "BaseCal.h"
//using namespace std;
/* getOper: 연산자 스트링, num1,num2: 피연산자 */

int BaseCal::Operator(int num1, int num2, std::string getOper)
{
	if (getOper == "*")
	{
		return num1 * num2;
	}
	else if (getOper == "/")
	{
		return num1 / num2;
	}
	else if (getOper == "+")
	{
		return num1 + num2;
	}
	else if (getOper == "-")
	{
		return num1 - num2;
	}
}

int BaseCal::Operator(int num1, int num2, ACHAR getOper)
{
	if (getOper == '*')
	{
		return num1 * num2;
	}
	else if (getOper == '/')
	{
		return num1 / num2;
	}
	else if (getOper == '+')
	{
		return num1 + num2;
	}
	else if (getOper == '-')
	{
		return num1 - num2;
	}
}