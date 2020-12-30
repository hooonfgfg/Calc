#include "PostFix.h"

void PostFix::ReturnList(std::string oper)
{
	if (postNumberList.empty()) //비어있으면 종료
		return;
	int num2 = *postNumberList.back();
	postNumberList.pop_back();
	int num1 = *postNumberList.back();
	postNumberList.pop_back();
	int result = Operator(num1, num2, oper);
	postNumberList.push_back(result); //계산 결과 저장

	post.push_back(*list.back());
	//std::cout << *list.back() << ' ';
	list.pop_back();
}

int PostFix::ReturnValue()
{
	return *postNumberList.back();
}

void PostFix::DigitProcessing(int currentLocation) // 0~9 사이의 문자일 경우 반복된 문자를 추출-> 숫자로 변환하는 메소드
{
	ten = 1; //초기화
	finalNumber = 0; //초기화

	for (int j = currentLocation; cy_isdigit(str_arr[j]); j++) //숫자 아닐때까지 반복
		lastLocation = j;

	for (int j = lastLocation; j >= currentLocation; j--)
	{
		finalNumber = finalNumber + (ten*(str_arr[j] - 48)); //최종 정수값 구하기
		ten *= 10; //10단위로 곱하기
	}

	currentLocation = lastLocation; //숫자마지막위치 저장 -> 건너뛰기
	std::string getNum = std::to_string(finalNumber);
	post.push_back(getNum);
	//std::cout << getNum << ' '; //피연산자
	postNumberList.push_back(finalNumber);
}

void PostFix::OperatorProcessing(int currentLocation) // 문
{
	std::string getch(1, str_arr[currentLocation]); //한문자 스트링형

	if (getch == "*" || getch == "/") // * / 은 가장 우선순위가 높으므로 push
	{
		while (!list.empty()) //나머지 리스트 출력
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
	else //+나 -일때
	{
		while (!list.empty()) //나머지 리스트 출력
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

	if (getch == "(") //우선 PUSH
		list.push_back(getch);

	else if (getch == ")") // ')' -> '(' 까지 POP후 출력(괄호는 버림)
	{
		while (*list.back() != "(")
		{ //연산자밖에 안남음
			ReturnList(*list.back());
		}list.pop_back(); //(까지 제거
	}
}

int PostFix::Calculation(std::string str)
{
	str_arr = str;

	int arr_len = cy_strlenA(str_arr.c_str());

	for (int i = 0; i < arr_len; i++) //배열 순회
	{
		if (cy_isdigit(str_arr[i])) //숫자이면
			DigitProcessing(i);

		else if (cy_isOperator_hjh(str_arr[i])) //연산자
			OperatorProcessing(i);

		else if (cy_isParenthesis_hjh(str_arr[i])) //괄호
			ParenthesisProcessing(i);

		else  continue;	//그 밖의 문자들 알파벳이나 특이숫자 (PASS)
	}

	while (!list.empty()) //나머지 리스트 반환
		ReturnList(*list.back());

	//std::cout << ReturnValue() << std::endl;
	return ReturnValue();
}