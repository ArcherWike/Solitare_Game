#pragma once
#include <windows.h>

struct TextColourChanger
{
	TextColourChanger(bool isSelected);
	~TextColourChanger();
private:
	HANDLE hConsole = NULL;
};