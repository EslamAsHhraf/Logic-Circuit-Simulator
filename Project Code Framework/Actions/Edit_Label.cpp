#include "Edit_Label.h"

Edit_Label::Edit_Label(ApplicationManager* pApp) :Action(pApp)
{

}

Edit_Label::~Edit_Label(void)
{
}

void Edit_Label::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("EditLabel: click at any gate to Edit it's label ");

	//Wait for User Input
	pIn->GetPointClicked(x, y);

	//Clear Status Bar
	pOut->ClearStatusBar();
}

void Edit_Label::Execute()
{
	ReadActionParameters();
	Component* Temp = pManager->IsClickGate(x, y);
	if (Temp)
	{
		pManager->SetEditLabel(1);
		pManager->SetLabelComp(Temp);

	}
}

void Edit_Label::Undo()
{
}

void Edit_Label::Redo()
{
}
