#include "AddSwitch.h"
AddSwitch::AddSwitch(ApplicationManager* pApp) :Action(pApp)
{

}

AddSwitch::~AddSwitch(void)
{
}

void AddSwitch::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Switch : Click to add the Switch");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddSwitch::Execute()
{
	Output * pOut = pManager->GetOutput();
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
	SWITCH* pA = new SWITCH(GInfo, AND2_FANOUT);
	CID = pA->INDEX;
	pA->getm_outputpin().setStatus(LOW);
	pManager->AddComponent(pA);
	pManager->SET_ID(pA);
	}
	else
		pOut->PrintMsg(" You Can't Draw in tool bar or status bar");
}

GraphicsInfo AddSwitch::GetCompcoor()
{
	return GInfo;
}

void AddSwitch::SetCompcoor(GraphicsInfo GxInfo)
{
	GInfo = GxInfo;
}

void AddSwitch::Undo()
{
	pManager->DelComponent(CID);
}


void AddSwitch::Redo()
{
	SWITCH* pA = new SWITCH(GInfo, AND2_FANOUT);
	pA->SetINDX(CID);
	pManager->AddComponent(pA);
}