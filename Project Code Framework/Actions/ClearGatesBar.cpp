#include "ClearGatesBar.h"

ClearGatesBar::ClearGatesBar(ApplicationManager* pApp) :Action(pApp)
{
}

ClearGatesBar::~ClearGatesBar(void)
{
}

void ClearGatesBar::ReadActionParameters()
{
}

void ClearGatesBar::Execute()
{
	
}

void ClearGatesBar::Undo()
{
}

void ClearGatesBar::Redo()
{
}

void ClearGatesBar::ClearGatesBar_(Output* pOut)
{
	pOut->ClearGatesBar();
}
