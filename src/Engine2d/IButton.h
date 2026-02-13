#pragma once

class IButton
{
public:
	virtual void IsPressed() = 0;

	virtual void Action() = 0;
};