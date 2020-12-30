#include "MyCal.h"

int MyCal::Calculation(std::string str)
{
	str_arr = str;
	for (int i = 0; i < str_arr.size(); i++)
	{
		if (i + 2 >= str_arr.size())
		{
			break;
		}
		number = Operator(str_arr[i] - 48, str_arr[i + 2] - 48, str_arr[i + 1]);
		str_arr[i + 2] = number + 48;
		i++;
		continue;
	}
	//std::cout << number << '\n';
	return number;
}