#include <string>
#include <Windows.h>

int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char*, int nShowCmd)
{
	char buff[100];
	std::string s = "SAD";
	sprintf_s(buff, "I AM %s", s.c_str());
	MessageBox(NULL, buff, s.c_str(), MB_OK | MB_ICONQUESTION);
}