#include "AddBuffgate.h"
AddBuffgate::AddBuffgate(ApplicationManager* pApp) :Action(pApp)
{
}
AddBuffgate::~AddBuffgate(void)
{
}

void AddBuffgate::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("BUFFER Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
}

void AddBuffgate::Execute()
{
	Output * pOut = pManager->GetOutput();
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	//GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	if (pOut->ValidDrawing(GInfo))
	{
	Buff* pA = new Buff(GInfo, AND2_FANOUT);
	CID = pA->INDEX;
	pManager->AddComponent(pA);
	pManager->SET_ID(pA);
	}
	else
		pOut->PrintMsg(" You Can't Draw in tool bar or status bar");
}

void AddBuffgate::Undo()
{
	pManager->DelComponent(CID);
}

void AddBuffgate::Redo()
{
	Buff* pA = new Buff(GInfo, AND2_FANOUT);
	pA->SetINDX(CID);
	pManager->AddComponent(pA);
}

GraphicsInfo AddBuffgate::GetCompcoor()
{
	return GInfo;
}

void AddBuffgate::SetCompcoor(GraphicsInfo GxInfo)
{
	GInfo = GxInfo;
}
