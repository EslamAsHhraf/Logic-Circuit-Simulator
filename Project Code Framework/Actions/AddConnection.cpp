#include "AddConnection.h"

AddConnection::AddConnection(ApplicationManager* pApp) :Action(pApp), crconn(0)
{

}

AddConnection::~AddConnection(void)
{
}
void AddConnection::Execute()
{
	Component* comp1 = NULL;
	Component* comp2 = NULL;
	ReadActionParameters();
	if (pManager->ISConnectionValid(&coOr, comp1, comp2))
	{
		crconn = comp2->getcurrentpin();
		if (comp2->freeinpp())
		{
			coOr.x1 = comp1->getouppcoor().x;
			coOr.y1 = comp1->getouppcoor().y;
			coOr.x2 = comp2->getinppcoor()[crconn].x;
			coOr.y2 = comp2->getinppcoor()[crconn].y;
			Connection* pA = new Connection(coOr, comp1, comp2, crconn);

			if (comp1->getm_outputpin().ConnectTo(pA))
			{
				CID = pA->INDEX;
				pManager->AddComponent(pA);
				pManager->SET_ID(pA);
				
			}

			else
			{
				delete pA;
			}

		}
	}
}
void AddConnection::Undo()
{
	pManager->DelComponent(CID);
}
GraphicsInfo AddConnection::GetCompcoor()
{
	return coOr;
}
void AddConnection::SetCompcoor(GraphicsInfo GxInfo)
{
	coOr = GxInfo;
}
void AddConnection::SetDisPinNum(int PinNum)
{
	crconn = PinNum;
}
void AddConnection::Redo()
{
	pManager->RedoConnection(coOr, crconn, CID);
}
void AddConnection::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	pOut->PrintMsg("Add Connection: Click on the two gates you want to connect");
	pIn->GetPointClicked(coOr.x1, coOr.y1);
	pIn->GetPointClicked(coOr.x2, coOr.y2);
	pOut->ClearStatusBar();


}

