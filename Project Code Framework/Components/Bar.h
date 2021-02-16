#pragma once
#include "..\GUI\Output.h"
class Bar
{
public:
	virtual void Draw(Output* pOut)=0;// pure function to draw bar
};

