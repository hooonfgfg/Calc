#include "header.h"

class MyGUICalc
{
private:
	HINSTANCE hInstance;
	HINSTANCE hPrevInstance;
	LPTSTR lpCmdLine;
	int nCmdShow;

public:
	MyGUICalc()
	{
		this->hInstance = hInstance;
		this->hPrevInstance = hPrevInstance;
		this->lpCmdLine = lpCmdLine;
		this->nCmdShow = nCmdShow;
	}
	int Calculation();
};