#pragma once
#include "..\GUI\Output.h"
class CircuitProbing
{
	GraphicsInfo GInfo;
	int Status;
public:
	CircuitProbing(GraphicsInfo & r_GfxInfo, int s);
	void Draw(Output* pOut);// draw the Circuit probing
	void Clear(Output* pOut);// clear the value
};

