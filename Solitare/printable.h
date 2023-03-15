#pragma once
#include <iostream>

class I_printable
{
public:
	virtual void Show_debug() const = 0;
};