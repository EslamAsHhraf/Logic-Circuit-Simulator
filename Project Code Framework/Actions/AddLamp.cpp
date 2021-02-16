#include "AddLamp.h"

AddLamp::AddLamp(ApplicationManager* pApp) :Action(pApp)
{

}

AddLamp::~AddLamp(void)
{
}

void AddLamp::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg(" Led : Click to add the Led");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddLamp::Execute()
{
	Output * pOut = pManager->GetOutput();
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	if (pOut->ValidDrawing(GInfo))
	{
	LAMP* pA = new LAMP(GInfo, AND2_FANOUT);
	CID = pA->INDEX;
	pManager->AddComponent(pA);
	pManager->SET_ID(pA);
	}
	else
		pOut->PrintMsg(" You Can't Draw in tool bar or status bar");
}

GraphicsInfo AddLamp::GetCompcoor()
{
	return GInfo;
}

void AddLamp::SetCompcoor(GraphicsInfo GxInfo)
{
	GInfo = GxInfo;
}

void AddLamp::Undo()
{
	pManager->DelComponent(CID);
}

void AddLamp::Redo()
{
	LAMP* pA = new LAMP(GInfo, AND2_FANOUT);
	pA->SetINDX(CID);
	pManager->AddComponent(pA);
}