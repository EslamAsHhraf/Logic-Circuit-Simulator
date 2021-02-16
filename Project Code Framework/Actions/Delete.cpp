#include "Delete.h"
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
#include "AddConnection.h"
#include "AddLamp.h"
#include"AddSwitch.h"
Delete::Delete(ApplicationManager* pApp) :Action(pApp)
{
	for (int i = 0; i < MaxCompCount; i++)
	{
		DeletedActions[i] = NULL;
	}
}

Delete::~Delete(void)
{
	for (int i = 0; i < CountDelComp; i++)
	{
		delete DeletedActions[i];
	}
}

//Delete::~Delete(void)
//{
//	for (int i = 0; i < CountDelComp; i++)
//	{
//		delete DeletedComponents[i];
//	}
//	delete DeletedComponents;
//}

void Delete::ReadActionParameters()
{
}

void Delete::Execute()
{
	pManager->Deleting();
}

//void Delete::FillDeletedComponents(Component** DC, int Count)
//{
//	DeletedComponents = DC;
//	CountDelComp = Count;
//}
//
//Component** Delete::GetDeletedComponents()
//{
//	return DeletedComponents;
//}
//
int Delete::GetCountDelComp()
{
	return CountDelComp;
}

void Delete::FillDeletedComponents(Component** WilldeletedComp, int Count)
{
	CountDelComp = Count;
	int DelCounter = 0;
	for (int TargetCompIndex = 0; TargetCompIndex < CountDelComp; TargetCompIndex++)
	{

		if (dynamic_cast<AND2*>(WilldeletedComp[TargetCompIndex]))
		{
			DeletedActions[DelCounter] = new AddANDgate2(pManager);
			DeletedActions[DelCounter]->CID = WilldeletedComp[TargetCompIndex]->INDEX;
			DeletedActions[DelCounter++]->SetCompcoor(WilldeletedComp[TargetCompIndex]->GetCompCoordinates());

		}
		else if (dynamic_cast<AND3*>(WilldeletedComp[TargetCompIndex]))
		{
			DeletedActions[DelCounter] = new AddANDgate3(pManager);
			DeletedActions[DelCounter]->CID = WilldeletedComp[TargetCompIndex]->INDEX;
			DeletedActions[DelCounter++]->SetCompcoor(WilldeletedComp[TargetCompIndex]->GetCompCoordinates());
		}
		else if (dynamic_cast<NAND2*>(WilldeletedComp[TargetCompIndex]))
		{
			DeletedActions[DelCounter] = new AddNANDgate2(pManager);
			DeletedActions[DelCounter]->CID = WilldeletedComp[TargetCompIndex]->INDEX;
			DeletedActions[DelCounter++]->SetCompcoor(WilldeletedComp[TargetCompIndex]->GetCompCoordinates());
		}
		else if (dynamic_cast<NAND3*>(WilldeletedComp[TargetCompIndex]))
		{
			DeletedActions[DelCounter] = new AddNANDgate3(pManager);
			DeletedActions[DelCounter]->CID = WilldeletedComp[TargetCompIndex]->INDEX;
			DeletedActions[DelCounter++]->SetCompcoor(WilldeletedComp[TargetCompIndex]->GetCompCoordinates());
		}
		else if (dynamic_cast<OR2*>(WilldeletedComp[TargetCompIndex]))
		{
			DeletedActions[DelCounter] = new AddORgate2(pManager);
			DeletedActions[DelCounter]->CID = WilldeletedComp[TargetCompIndex]->INDEX;
			DeletedActions[DelCounter++]->SetCompcoor(WilldeletedComp[TargetCompIndex]->GetCompCoordinates());
		}
		else if (dynamic_cast<OR3*>(WilldeletedComp[TargetCompIndex]))
		{
			DeletedActions[DelCounter] = new AddORgate3(pManager);
			DeletedActions[DelCounter]->CID = WilldeletedComp[TargetCompIndex]->INDEX;
			DeletedActions[DelCounter++]->SetCompcoor(WilldeletedComp[TargetCompIndex]->GetCompCoordinates());
		}
		else if (dynamic_cast<NOR2*>(WilldeletedComp[TargetCompIndex]))
		{
			DeletedActions[DelCounter] = new AddNORgate2(pManager);
			DeletedActions[DelCounter]->CID = WilldeletedComp[TargetCompIndex]->INDEX;
			DeletedActions[DelCounter++]->SetCompcoor(WilldeletedComp[TargetCompIndex]->GetCompCoordinates());
		}
		else if (dynamic_cast<NOR3*>(WilldeletedComp[TargetCompIndex]))
		{
			DeletedActions[DelCounter] = new AddNORgate3(pManager);
			DeletedActions[DelCounter]->CID = WilldeletedComp[TargetCompIndex]->INDEX;
			DeletedActions[DelCounter++]->SetCompcoor(WilldeletedComp[TargetCompIndex]->GetCompCoordinates());
		}
		else if (dynamic_cast<XOR2*>(WilldeletedComp[TargetCompIndex]))
		{
			DeletedActions[DelCounter] = new AddXORgate2(pManager);
			DeletedActions[DelCounter]->CID = WilldeletedComp[TargetCompIndex]->INDEX;
			DeletedActions[DelCounter++]->SetCompcoor(WilldeletedComp[TargetCompIndex]->GetCompCoordinates());
		}
		else if (dynamic_cast<XOR3*>(WilldeletedComp[TargetCompIndex]))
		{
			DeletedActions[DelCounter] = new AddXORgate3(pManager);
			DeletedActions[DelCounter]->CID = WilldeletedComp[TargetCompIndex]->INDEX;
			DeletedActions[DelCounter++]->SetCompcoor(WilldeletedComp[TargetCompIndex]->GetCompCoordinates());
		}
		else if (dynamic_cast<XNOR2*>(WilldeletedComp[TargetCompIndex]))
		{
			DeletedActions[DelCounter] = new AddXNORgate2(pManager);
			DeletedActions[DelCounter]->CID = WilldeletedComp[TargetCompIndex]->INDEX;
			DeletedActions[DelCounter++]->SetCompcoor(WilldeletedComp[TargetCompIndex]->GetCompCoordinates());
		}
		else if (dynamic_cast<XNOR3*>(WilldeletedComp[TargetCompIndex]))
		{
			DeletedActions[DelCounter] = new AddXNORgate3(pManager);
			DeletedActions[DelCounter]->CID = WilldeletedComp[TargetCompIndex]->INDEX;
			DeletedActions[DelCounter++]->SetCompcoor(WilldeletedComp[TargetCompIndex]->GetCompCoordinates());
		}
		else if (dynamic_cast<INV*>(WilldeletedComp[TargetCompIndex]))
		{
			DeletedActions[DelCounter] = new AddINVgate(pManager);
			DeletedActions[DelCounter]->CID = WilldeletedComp[TargetCompIndex]->INDEX;
			DeletedActions[DelCounter++]->SetCompcoor(WilldeletedComp[TargetCompIndex]->GetCompCoordinates());
		}
		else if (dynamic_cast<Buff*>(WilldeletedComp[TargetCompIndex]))
		{
			DeletedActions[DelCounter] = new AddBuffgate(pManager);
			DeletedActions[DelCounter]->CID = WilldeletedComp[TargetCompIndex]->INDEX;
			DeletedActions[DelCounter++]->SetCompcoor(WilldeletedComp[TargetCompIndex]->GetCompCoordinates());
		}
		else if (dynamic_cast<LAMP*>(WilldeletedComp[TargetCompIndex]))
		{
			DeletedActions[DelCounter] = new AddLamp(pManager);
			DeletedActions[DelCounter]->CID = WilldeletedComp[TargetCompIndex]->INDEX;
			DeletedActions[DelCounter++]->SetCompcoor(WilldeletedComp[TargetCompIndex]->GetCompCoordinates());
		}
		else if (dynamic_cast<SWITCH*>(WilldeletedComp[TargetCompIndex]))
		{
			DeletedActions[DelCounter] = new AddSwitch(pManager);
			DeletedActions[DelCounter]->CID = WilldeletedComp[TargetCompIndex]->INDEX;
			DeletedActions[DelCounter++]->SetCompcoor(WilldeletedComp[TargetCompIndex]->GetCompCoordinates());
		}
	}
	for (int TargetCompIndex = 0; TargetCompIndex < CountDelComp; TargetCompIndex++)
	{
		if (dynamic_cast<Connection*>(WilldeletedComp[TargetCompIndex]))
		{
			DeletedActions[DelCounter] = new AddConnection(pManager);
			DeletedActions[DelCounter]->CID = WilldeletedComp[TargetCompIndex]->INDEX;
			DeletedActions[DelCounter]->SetCompcoor(WilldeletedComp[TargetCompIndex]->GetCompCoordinates());
			DeletedActions[DelCounter++]->SetDisPinNum(WilldeletedComp[TargetCompIndex]->GetDstPinnumber());
		}
	}


}

Action** Delete::GetDeletedActions()
{
	return DeletedActions;
	// TODO: insert return statement here
}



void Delete::Undo()
{
	for (int i = 0; i < CountDelComp; i++)
	{
		DeletedActions[i]->Redo();
	}
	/*for (int i = 0; i < CountDelComp; i++)
	{
		pManager->AddComponent(DeletedComponents[i]);
	}*/

}

void Delete::Redo()
{
	UI.IsDeleteAct = 1;
	for (int i = CountDelComp - 1; i >= 0; i--)
	{
		DeletedActions[i]->Undo();
	}
	//pManager->RedoDeleteAct(CountDelComp); 
}
