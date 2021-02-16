#pragma once
#include "..\Defs.h"
#include "..\GUI\Output.h"

class GatesBar
{
public:
	virtual void Draw(Output* pOut);
	virtual void Clear(Output* pOut);
};