#include "SELECT.h"

Select::Select(ApplicationManager* pApp) :Action(pApp)
{
}

Select::~Select(void)
{
}

void Select::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(x, y);
}

void Select::Execute()
{
	ReadActionParameters();
	pManager->Selection(x, y);
}

void Select::Undo()
{
}

void Select::Redo()
{
}
