#include <iostream>
#include <string>
#include "cy_stdlib.h"
#include "Cy_String.h"
#include "Cy_ArrayT.h"
#include "Cy_StringBase.h"
#pragma once
#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif