#include "Cut.h"
#include "AddANDgate2.h"
#include "AddORgate2.h"
#include "AddNANDgate2.h"
#include "AddNORgate2.h"
#include "AddXNORgate2.h"
#include "AddXORgate2.h"
#include "AddINVgate.h"
#include "AddBuffgate.h"
#include "AddANDgate3.h"
#include "AddORgate3.h"
#include "AddNANDgate3.h"
#include "AddNORgate3.h"
#include "AddXNORgate3.h"
#include "AddXORgate3.h"
#include "AddLamp.h"
#include"AddSwitch.h"
Cut::Cut(ApplicationManager* pApp) :Action(pApp)
{
}

Cut::~Cut(void)
{
}

void Cut::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
}

void Cut::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	Component* Comp = pManager->Cutting();
	if (Comp == NULL)
	{
		return;
	}
	pOut->PrintMsg("Click at Paste Icon to Paste");
	if (dynamic_cast<AND2*>(Comp))
	{
		CuttedAction = new AddANDgate2(pManager);
		CuttedAction->CID = Comp->INDEX;
		CuttedAction->SetCompcoor(Comp->GetCompCoordinates());
	}
	else if (dynamic_cast<AND3*>(Comp))
	{
		CuttedAction = new AddANDgate3(pManager);
		CuttedAction->CID = Comp->INDEX;
		CuttedAction->SetCompcoor(Comp->GetCompCoordinates());
	}
	else if (dynamic_cast<NAND2*>(Comp))
	{
		CuttedAction = new AddNANDgate2(pManager);
		CuttedAction->CID = Comp->INDEX;
		CuttedAction->SetCompcoor(Comp->GetCompCoordinates());
	}
	else if (dynamic_cast<NAND3*>(Comp))
	{
		CuttedAction = new AddNANDgate3(pManager);
		CuttedAction->CID = Comp->INDEX;
		CuttedAction->SetCompcoor(Comp->GetCompCoordinates());
	}
	else if (dynamic_cast<OR2*>(Comp))
	{
		CuttedAction = new AddORgate2(pManager);
		CuttedAction->CID = Comp->INDEX;
		CuttedAction->SetCompcoor(Comp->GetCompCoordinates());
	}
	else if (dynamic_cast<OR3*>(Comp))
	{
		CuttedAction = new AddORgate3(pManager);
		CuttedAction->CID = Comp->INDEX;
		CuttedAction->SetCompcoor(Comp->GetCompCoordinates());
	}
	else if (dynamic_cast<NOR2*>(Comp))
	{
		CuttedAction = new AddNORgate2(pManager);
		CuttedAction->CID = Comp->INDEX;
		CuttedAction->SetCompcoor(Comp->GetCompCoordinates());
	}
	else if (dynamic_cast<NOR3*>(Comp))
	{
		CuttedAction = new AddNORgate3(pManager);
		CuttedAction->CID = Comp->INDEX;
		CuttedAction->SetCompcoor(Comp->GetCompCoordinates());
	}
	else if (dynamic_cast<XOR2*>(Comp))
	{
		CuttedAction = new AddXORgate2(pManager);
		CuttedAction->CID = Comp->INDEX;
		CuttedAction->SetCompcoor(Comp->GetCompCoordinates());
	}
	else if (dynamic_cast<XOR3*>(Comp))
	{
		CuttedAction = new AddXORgate3(pManager);
		CuttedAction->CID = Comp->INDEX;
		CuttedAction->SetCompcoor(Comp->GetCompCoordinates());
	}
	else if (dynamic_cast<XNOR2*>(Comp))
	{
		CuttedAction = new AddXNORgate2(pManager);
		CuttedAction->CID = Comp->INDEX;
		CuttedAction->SetCompcoor(Comp->GetCompCoordinates());
	}
	else if (dynamic_cast<XNOR3*>(Comp))
	{
		CuttedAction = new AddXNORgate3(pManager);
		CuttedAction->CID = Comp->INDEX;
		CuttedAction->SetCompcoor(Comp->GetCompCoordinates());
	}
	else if (dynamic_cast<INV*>(Comp))
	{
		CuttedAction = new AddINVgate(pManager);
		CuttedAction->CID = Comp->INDEX;
		CuttedAction->SetCompcoor(Comp->GetCompCoordinates());
	}
	else if (dynamic_cast<Buff*>(Comp))
	{
		CuttedAction = new AddBuffgate(pManager);
		CuttedAction->CID = Comp->INDEX;
		CuttedAction->SetCompcoor(Comp->GetCompCoordinates());
	}
	else if (dynamic_cast<LAMP*>(Comp))
	{
		CuttedAction = new AddLamp(pManager);
		CuttedAction->CID = Comp->INDEX;
		CuttedAction->SetCompcoor(Comp->GetCompCoordinates());
	}
	else if (dynamic_cast<SWITCH*>(Comp))
	{
		CuttedAction = new AddSwitch(pManager);
		CuttedAction->CID = Comp->INDEX;
		CuttedAction->SetCompcoor(Comp->GetCompCoordinates());
	}
	GInfo = Comp->GetCompCoordinates();
}

void Cut::SetCompcoor(GraphicsInfo GxInfo)
{
	GInfo = GxInfo;
}

GraphicsInfo Cut::GetCompcoor()
{
	return GInfo;
}

void Cut::Undo()
{
	CuttedAction->Redo();
}

void Cut::Redo()
{
	UI.IsRedoCut = 1;
	CuttedAction->Undo();
}
