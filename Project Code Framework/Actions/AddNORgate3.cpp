#include "AddNORgate3.h"
AddNORgate3::AddNORgate3(ApplicationManager* pApp) :Action(pApp)
{
}

AddNORgate3::~AddNORgate3(void)
{
}

void AddNORgate3::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("3-Input NOR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddNORgate3::Execute()
{
	Output* pOut = pManager->GetOutput();
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	//Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	if (pOut->ValidDrawing(GInfo))
	{
		NOR3* pA = new NOR3(GInfo, AND2_FANOUT);
		CID = pA->INDEX;
		pManager->AddComponent(pA);
		pManager->SET_ID(pA);
	}
	else 
		pOut->PrintMsg(" You Can't Draw in tool bar or status bar");
}

void AddNORgate3::Undo()
{
	pManager->DelComponent(CID);
}

void AddNORgate3::Redo()
{
	NOR3* pA = new NOR3(GInfo, AND2_FANOUT);
	pA->SetINDX(CID);
	pManager->AddComponent(pA);
	pManager->SET_ID(pA);
}

GraphicsInfo AddNORgate3::GetCompcoor()
{
	return GInfo;
}

void AddNORgate3::SetCompcoor(GraphicsInfo GxInfo)
{
	GInfo = GxInfo;
}
