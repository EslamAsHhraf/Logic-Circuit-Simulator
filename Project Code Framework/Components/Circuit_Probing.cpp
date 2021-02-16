#include "Circuit_Probing.h"

CircuitProbing::CircuitProbing(GraphicsInfo  & r_GfxInfo, int  s)
{
	GInfo = r_GfxInfo;
	Status = s;
}

void CircuitProbing::Draw(Output * pOut)
{
	pOut->CircuitProbing(GInfo, Status);
}

void CircuitProbing::Clear(Output * pOut)
{
	pOut->ClearProbing(GInfo);
}
