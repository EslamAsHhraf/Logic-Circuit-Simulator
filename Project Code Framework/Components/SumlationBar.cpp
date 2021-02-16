#include "SumlationBar.h"

void SumlationBar::Draw(Output * pOut)
{
	//Delete design Bar
	pOut->Clearbar();
	// Draw sumulation bar
	pOut->CreateSimulationToolBar();
}
