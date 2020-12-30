#include "BaseCal.h"
#include "PostFix.h"
#include "MyCal.h"
#include "MyGUICalc.h"
#include <tchar.h>

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	BaseCal *basecal;
	
	basecal = new MyCal;
	basecal->Calculation("3+6+4/2");
	delete basecal;
	
	basecal = new PostFix;
	basecal->Calculation("(2*(3+6/2)+2)/4+33+3+2*3");
	delete basecal;

	return 0;
}