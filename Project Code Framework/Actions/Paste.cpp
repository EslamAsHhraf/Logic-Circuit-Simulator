#include "Paste.h"

Paste::Paste(ApplicationManager* pApp) :Action(pApp)
{
}

Paste::~Paste(void)
{
}

void Paste::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(x, y);
}

void Paste::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();

	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = x - Len / 2;
	GInfo.x2 = x + Len / 2;
	GInfo.y1 = y - Wdth / 2;
	GInfo.y2 = y + Wdth / 2;
	pOut->PrintMsg("Click at any point in drawing area to paste");
	pManager->Pasting(GInfo);
}

void Paste::Undo()
{
}

void Paste::Redo()
{
}
