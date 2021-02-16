#include "AddCircuitProbing.h"
#include "..\ApplicationManager.h"

AddCircuitProbing::AddCircuitProbing(ApplicationManager *pApp) :Action(pApp)
{

}

AddCircuitProbing ::~AddCircuitProbing(void)
{
}

void  AddCircuitProbing::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Click on the connection to know the status");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void  AddCircuitProbing::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	ReadActionParameters();
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;
	GraphicsInfo GInfo;
	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	
	
	
	Component* comp = NULL;
	if (pOut->ValidDrawing(GInfo))
	{
	if (pManager->Probing(comp, Cx, Cy))
	{
		CircuitProbing * Prob = new CircuitProbing(GInfo, comp->GetOutPinStatus());
		pManager->addProbing(Prob);
		pManager->setProbing(true);
	
	}
	}
	else
		pOut->PrintMsg(" You Can't Draw in tool bar or status bar");
}

void AddCircuitProbing::Undo()
{}

void  AddCircuitProbing::Redo()
{}

