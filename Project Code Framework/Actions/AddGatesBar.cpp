#include "AddGatesBar.h"

AddGatesBar::AddGatesBar(ApplicationManager* pApp) :Action(pApp)
{
}

AddGatesBar::~AddGatesBar(void)
{
}

void AddGatesBar::ReadActionParameters()
{
}

void AddGatesBar::Execute()
{
	GatesBar* pA = new GatesBar;
	pManager->AddGatesBarPtr(pA);
}

void AddGatesBar::Undo()
{
}

void AddGatesBar::Redo()
{
}

void AddGatesBar::CreateGatesBar(Output* pOut)
{
	pOut->CreateGatesBar();
}

