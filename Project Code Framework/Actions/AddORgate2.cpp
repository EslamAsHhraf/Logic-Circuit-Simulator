#include "AddORgate2.h"

AddORgate2::AddORgate2(ApplicationManager* pApp):Action(pApp)
{
}

AddORgate2::~AddORgate2(void)
{
}

void AddORgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input OR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
}

void AddORgate2::Execute()
{
	Output * pOut = pManager->GetOutput();
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;
	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	//Gfx info to be used to construct the AND2 gate
	if (pOut->ValidDrawing(GInfo))
	{
	OR2* pA = new OR2(GInfo, AND2_FANOUT);
	CID = pA->INDEX;
	pManager->AddComponent(pA);
	pManager->SET_ID(pA);
    }
	else
	pOut->PrintMsg(" You Can't Draw in tool bar or status bar");
}

void AddORgate2::Undo()
{
	pManager->DelComponent(CID);
}

void AddORgate2::Redo()
{
	OR2* pA = new OR2(GInfo, AND2_FANOUT);
	pA->SetINDX(CID);
	pManager->AddComponent(pA);
	pManager->SET_ID(pA);
}

GraphicsInfo AddORgate2::GetCompcoor()
{
	return GInfo;
}

void AddORgate2::SetCompcoor(GraphicsInfo GxInfo)
{
	GInfo = GxInfo;
}
