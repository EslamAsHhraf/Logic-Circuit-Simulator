#include "Copy.h"

Copy::Copy(ApplicationManager* pApp) :Action(pApp)
{
}

Copy::~Copy(void)
{
}

void Copy::ReadActionParameters()
{
}

void Copy::Execute()
{
	pManager->Copying();
}

void Copy::Undo()
{
}

void Copy::Redo()
{
}
