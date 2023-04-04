#pragma once


class I_printable
{
public:
	virtual void Show_debug() const = 0;
	virtual void Show_user() const {};
};