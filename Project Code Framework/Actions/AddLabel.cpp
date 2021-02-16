#include "AddLabel.h"

AddLabel::AddLabel(ApplicationManager* pApp) :Action(pApp)
{

}

AddLabel::~AddLabel(void)
{
}

void AddLabel::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Label: click at any gate to label it");

	//Wait for User Input
	pIn->GetPointClicked(x,y);

	//Clear Status Bar
	pOut->ClearStatusBar();
}

void AddLabel::Execute()
{
	ReadActionParameters();
	Component* Temp =pManager->IsClickGate(x, y);
	if (Temp)
	{
		pManager->SetLabel(1);
		pManager->SetLabelComp(Temp);

	}
}

void AddLabel::Undo()
{
}

void AddLabel::Redo()
{
}
