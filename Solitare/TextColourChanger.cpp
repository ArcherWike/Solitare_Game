#include "TextColourChanger.h"


TextColourChanger::TextColourChanger(bool isSelected)
{
	if (isSelected)
	{
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 11);
	}
}

TextColourChanger::~TextColourChanger()
{
	if (hConsole)
	{
		SetConsoleTextAttribute(hConsole, 15);
	}
	
}
