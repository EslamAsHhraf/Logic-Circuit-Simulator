#include "Edit.h"
Edit::Edit(ApplicationManager* pApp):Action(pApp)
{
}

Edit::~Edit(void)
{
}

void Edit::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Edit Connection: PlZ click on the gate that you want to change for the last selected connection");
	pIn->GetPointClicked(x1, y1);
	pOut->ClearStatusBar();
	pOut->PrintMsg("Edit Connection: PlZ click on the new gate that you want your connecection to attach to it ");
	//pOut->ClearStatusBar();

	//Wait for User Input
	pIn->GetPointClicked(x2, y2);
	

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Edit::Execute()
{
	ReadActionParameters();
	Component* Comp2 = NULL;
	Component* Comp3 = NULL;
	Comp2=pManager->IsClickGate(x1, y1);
	Comp3=pManager->IsClickGate(x2, y2);
	Connection*Connc = NULL;
	Connc = dynamic_cast<Connection*>(pManager->GetlastSelected());
	
	if (Connc && Comp2 && Comp3)
	{

		int NDstPin = Connc->GetDstPinnumber();
		if (Connc->GetSrcCmpnt() == Comp2&&dynamic_cast<LAMP*>(Comp3)==NULL&& dynamic_cast<Connection*>(Comp3)==NULL)
		{
			Component* TempDstComp = Connc->GetDstCmpnt();
			coOr.x2 = Connc->GetCompCoordinates().x2;
			coOr.y2 = Connc->GetCompCoordinates().y2;
			coOr.x1 = Comp3->getouppcoor().x;
			coOr.y1 = Comp3->getouppcoor().y;
			string temp1 = Connc->getLabel();
			pManager->Delete_Conn();
			if (TempDstComp->freeinpp())
			{

				Connection* pA = new Connection(coOr, Comp3, TempDstComp, NDstPin);
				pA->set_string(temp1);
				if (Comp3->getm_outputpin().ConnectTo(pA))
				{
					pManager->SetEditConnLabel(1);
					pManager->SetConnlabel(pA);
					
					pManager->AddComponent(pA);
				}
				else
				{
					delete pA;
					pA = NULL;
					coOr.x1 = Comp2->getouppcoor().x;
					coOr.y1 = Comp2->getouppcoor().y;
					pA = new Connection(coOr, Comp2, TempDstComp, NDstPin);
					pA->set_string(temp1);
					pManager->AddComponent(pA);
					pManager->SetEditConnLabel(1);
					pManager->SetConnlabel(pA);
				}
			
			}
		}
		NDstPin = Comp3->getcurrentpin();
	

		if (Connc->GetDstCmpnt() == Comp2 && dynamic_cast<SWITCH*>(Comp3)==NULL && dynamic_cast<Connection*>(Comp3)==NULL)
		{


			Component* TempSrcComp = Connc->GetSrcCmpnt();
			string temp1 = Connc->getLabel();

			coOr.x1 = Connc->GetCompCoordinates().x1;
			coOr.y1 = Connc->GetCompCoordinates().y1;
			coOr.x2 = Comp3->getinppcoor()[NDstPin].x;
			coOr.y2 = Comp3->getinppcoor()[NDstPin].y;
			pManager->Delete_Conn();
			if (Comp3->freeinpp())
			{

				Connection* pA = new Connection(coOr, TempSrcComp, Comp3, NDstPin);
				pA->set_string(temp1);
				pManager->SetEditConnLabel(1);
				pManager->SetConnlabel(pA);


				if (TempSrcComp->getm_outputpin().ConnectTo(pA))
				{

					pManager->AddComponent(pA);
				}
				else
				{
					delete pA;
					pA = NULL;
				}
			}
			else
			{
					NDstPin = Comp2->getcurrentpin();
					coOr.x2 = Comp2->getinppcoor()[NDstPin].x;
					coOr.y2 = Comp2->getinppcoor()[NDstPin].y;
					Connection* pA = new Connection(coOr, TempSrcComp, Comp2, NDstPin);
					pA->set_string(temp1);
					pManager->AddComponent(pA);
					pManager->SetEditConnLabel(1);
					pManager->SetConnlabel(pA);
			}

			

		}
	}
	

}

void Edit::Undo()
{
}

void Edit::Redo()
{
}


