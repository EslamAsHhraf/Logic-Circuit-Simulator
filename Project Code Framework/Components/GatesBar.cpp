#include "GatesBar.h"

void GatesBar::Draw(Output* pOut)
{
	pOut->CreateGatesBar();
}

void GatesBar::Clear(Output* pOut)
{
	pOut->ClearGatesBar();
}
