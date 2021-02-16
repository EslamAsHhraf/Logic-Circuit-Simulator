#include "DesignBar.h"

void DesignBar::Draw(Output * pOut)
{
	//Delete Simulate Bar
	pOut->Clearbar();
	// Draw design bar
	pOut->CreateDesignToolBar();
}
