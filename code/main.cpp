#include "BaseCal.h"
#include "PostFix.h"
#include "MyCal.h"
#include "MyGUICalc.h"
#include <tchar.h>

int calc(BaseCal* basecal,std::string str)
{
	return basecal->Calculation(str);
}

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	BaseCal *basecal;
	
	basecal = new MyCal;
	std::cout<<calc(basecal, "3+6+4/2")<<std::endl;
	delete basecal;
	
	basecal = new PostFix;
	std::cout<<calc(basecal, "(2*(3+6/2)+2)/4+33+3+2*3")<<std::endl;
	delete basecal;

	return 0;
}
