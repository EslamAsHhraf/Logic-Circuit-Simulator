#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "Actions\AddORgate2.h"
#include "Actions\AddNANDgate2.h"
#include "Actions\AddNORgate2.h"
#include "Actions\AddXNORgate2.h"
#include "Actions\AddXORgate2.h"
#include "Actions\AddINVgate.h"
#include "Actions\AddBuffgate.h"
#include "Actions\AddANDgate3.h"
#include "Actions\AddORgate3.h"
#include "Actions\AddNANDgate3.h"
#include "Actions\AddNORgate3.h"
#include "Actions\AddXNORgate3.h"
#include "Actions\AddXORgate3.h"
#include"Actions\AddGatesBar.h"
#include"Actions\ClearGatesBar.h"
#include"Actions\SELECT.h"
#include"Actions\Cut.h"
#include"Actions\Copy.h"
#include"Actions\Paste.h"
#include"Actions\Delete.h"
#include"Actions/Undo.h"
#include"Actions/Redo.h"
#include "Actions\AddSumlation.h"
#include "Actions\AddConnection.h"
#include"Actions\AddSwitch.h"
#include"Actions\AddLamp.h"
#include"Actions\Convert_Switch.h"
#include"Actions\AddCircuitProbing.h"
#include <algorithm>
#include "Actions\AddGatesBar.h"
#include "Actions\AddDesign.h"
#include "save.h"
#include "load.h"
# include"Actions\AddLabel.h"
# include "Actions\Edit_Label.h"
#include"Actions/Edit.h"
#include"Actions/CircuitValid.h"
ApplicationManager::ApplicationManager():ConstructGatesBar(-1), GatesBarPtr(NULL), SelectionCounter(0), ClipBoard(NULL), DeleteCompCount(0)
										 ,UndoCount(0), RedoCount(0), CurrentAction(NULL), DelCompCount(0), IsCut(0),forEdit(0), Conn_Label(NULL), Editconnection(0)
{
	
	Load = 0;
	IDS_COMP=1;
	Label = 0;
	EditLabel = 0;
	CompCount = 0;
	bar = false;
	Cir_Probing = false;
	for (int i = 0; i < MaxCompCount; i++)
	{
		CompList[i] = NULL;
		UndoAct[i] = NULL;
		RedoAct[i] = NULL;
		SelectedCompIndexes[i] = NULL;
	}
	WillDeleted = new Component * [MaxCompCount];
	for (int i = 0; i < MaxCompCount; i++)
	{
		WillDeleted[i] = NULL;
	}
	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;
	for (int i = 0; i < CompCount - 1; i++)
	{
		int minInd = i;
		for (int j = i + 1; j < CompCount; j++)
		{
			if (CompList[minInd]->INDEX > CompList[j]->INDEX)
			{
				minInd = j;
			}
		}
		Component* Temp = CompList[i];
		CompList[i] = CompList[minInd];
		CompList[minInd] = Temp;
	}
}
void ApplicationManager::DelComponent(int id)
{
	int index;
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->INDEX == id)
		{
			index = i;
		}
	}
	for (int i = 0; i < SelectionCounter; i++)
	{
		if (index == *SelectedCompIndexes[i])
		{
			for (int j = i + 1; j < SelectionCounter; j++)
			{
				*(SelectedCompIndexes[j - 1]) = *(SelectedCompIndexes[j]);
			}
			delete SelectedCompIndexes[SelectionCounter - 1];
			SelectionCounter--;
		}
	}
	Component* Temp = CompList[index];
	for (int i = index + 1; i < CompCount; i++)
	{
		CompList[i - 1] = CompList[i];
	}
	CompList[CompCount - 1] = Temp;
	delete CompList[CompCount - 1];
	CompCount--;
	DelCompCount++;
}
void ApplicationManager::AddGatesBarPtr(GatesBar* Gates_Bar)
{
	GatesBarPtr = Gates_Bar;
}

void ApplicationManager::AddToUndoAct()
{
	UndoAct[UndoCount++] = CurrentAction;
	//CurrentAction = NULL;
}

Action*& ApplicationManager::GetLastActionUndo()
{
	return UndoAct[UndoCount - 1];
}

Action*& ApplicationManager::GetLastActionRedo()
{
	return RedoAct[RedoCount - 1];
}

void ApplicationManager::RemoveUndoAct()
{
	if (!UndoCount)
	{
		return;
	}
	RedoAct[RedoCount++] = UndoAct[UndoCount - 1];
	UndoAct[--UndoCount] = NULL;
}

void ApplicationManager::RemoveRedoAct()
{
	if (!RedoCount)
	{
		return;
	}
	UndoAct[UndoCount++] = RedoAct[RedoCount - 1];
	RedoAct[--RedoCount] = NULL;
}

void ApplicationManager::ClearGatesBarPtr()
{
	delete GatesBarPtr;
	GatesBarPtr = NULL;
}
void ApplicationManager::Selection(int x, int y)
{
	bool SelectionTest = 1;
	for (int i = 0; i < CompCount; i++)
	{
		int x1 = CompList[i]->GetCompCoordinates().x1;
		int x2= CompList[i]->GetCompCoordinates().x2;
		int y1 = CompList[i]->GetCompCoordinates().y1;
		int y2 = CompList[i]->GetCompCoordinates().y2;
		if (dynamic_cast<Connection*>(CompList[i]))
		{
			int m = (CompList[i]->GetCompCoordinates().x1 + CompList[i]->GetCompCoordinates().x2) / 2;

			if ((CompList[i]->GetCompCoordinates().x1 <= x && m >= x && CompList[i]->GetCompCoordinates().y1 - 2 <= y && CompList[i]->GetCompCoordinates().y1 + 2 >= y)
				|| (((CompList[i]->GetCompCoordinates().y1 <= y && CompList[i]->GetCompCoordinates().y2 >= y)
				|| (CompList[i]->GetCompCoordinates().y2 <= y && CompList[i]->GetCompCoordinates().y1 >= y)) && m - 2 <= x && m + 2 >= x)
				|| (m <= x && CompList[i]->GetCompCoordinates().x2 >= x && CompList[i]->GetCompCoordinates().y2 - 2 <= y && CompList[i]->GetCompCoordinates().y2 + 2 >= y))

			{
				SelectionTest = 0;
				SelectedCompIndexes[SelectionCounter++] = new int(i);
			}
		}
		else if (x > x1 && x<x2 && y>y1 && y < y2)
		{
			SelectionTest = 0;
			SelectedCompIndexes[SelectionCounter++] = new int(i);
			for (int k = 0; k < CompCount; k++)
			{
				int temp = CompList[i]->get_intm_Inputs();
			
				if (dynamic_cast<Connection*>(CompList[k]))
				{
					Connection* Temp = dynamic_cast<Connection*>(CompList[k]);
					if (temp == 3)
					{
						if (Temp->getDestPin() == CompList[i]->getm_InpPutpin(0) || Temp->getDestPin() == CompList[i]->getm_InpPutpin(1)|| Temp->getDestPin() == CompList[i]->getm_InpPutpin(2))
						{
							SelectedCompIndexes[SelectionCounter++] = new int(k);
						}
					}
					else if (temp == 2)
					{
						if (Temp->getDestPin() == CompList[i]->getm_InpPutpin(0) || Temp->getDestPin() == CompList[i]->getm_InpPutpin(1) )
						{
							SelectedCompIndexes[SelectionCounter++] = new int(k);
						}
					}
					else if(temp == 1)
					{
						if (Temp->getDestPin() == CompList[i]->getm_InpPutpin(0))
						{
							SelectedCompIndexes[SelectionCounter++] = new int(k);
						}
					}
				}
			}
			for (int k = 0; k < CompCount; k++)
			{
				if (dynamic_cast<Connection*>(CompList[k]))
				{
					Connection* Temp = dynamic_cast<Connection*>(CompList[k]);
					if (Temp->getSourcePin() == &CompList[i]->getm_outputpin())
					{
						SelectedCompIndexes[SelectionCounter++] = new int(k);
					}
				}
			}
			return;
		}
	}
	if (SelectionTest)
	{
		for (int i = 0; i < SelectionCounter; i++)
		{
			delete SelectedCompIndexes[i];
			SelectedCompIndexes[i] = NULL;
		}
		SelectionCounter = 0;
	}
}
int ApplicationManager::CountPasting = 0;
void ApplicationManager::Copying()
{
	if (SelectionCounter == 0)
	{
		return;
	}

	int Temp1 = *SelectedCompIndexes[SelectionCounter - 1];
	*SelectedCompIndexes[SelectionCounter - 1] = *SelectedCompIndexes[0];
	*SelectedCompIndexes[0] = Temp1;
	CountPasting = 0;
	AddToClipBoard();
	int Temp2 = *SelectedCompIndexes[SelectionCounter - 1];
	*SelectedCompIndexes[SelectionCounter - 1] = *SelectedCompIndexes[0];
	*SelectedCompIndexes[0] = Temp2;
}
Component*& ApplicationManager::Cutting()
{
	if (SelectionCounter == 0)
	{
		Component* Temp = NULL;
		return Temp;
	}
	Component* Temp;
	CountPasting = 0;
	IsCut = 1;
	int Temp1 = *SelectedCompIndexes[SelectionCounter - 1];
	*SelectedCompIndexes[SelectionCounter - 1] = *SelectedCompIndexes[0];
	*SelectedCompIndexes[0] = Temp1;
	AddToClipBoard();
	int Temp2 = *SelectedCompIndexes[SelectionCounter - 1];
	*SelectedCompIndexes[SelectionCounter - 1] = *SelectedCompIndexes[0];
	*SelectedCompIndexes[0] = Temp2;
	Deleting(1);
	return ClipBoard;

}

void ApplicationManager::Pasting(const GraphicsInfo& GInfo)
{
	if (ClipBoard == NULL)
	{
		return ;
	}
	CountPasting++;
	if (CountPasting > 1)
	{
		AddToClipBoard();
	}
	ClipBoard->SetCompCoordinates(GInfo);
	AddComponent(ClipBoard);
	ClipBoard = NULL;
}
void ApplicationManager::Deleting(bool Cut)
{
	while (SelectionCounter > 0)
	{
		WillDeleted[DeleteCompCount++] = CompList[*SelectedCompIndexes[SelectionCounter - 1]];
		for (int j = *SelectedCompIndexes[SelectionCounter - 1] + 1; j < CompCount; j++)
		{
			CompList[j - 1] = CompList[j];
		}
		CompList[CompCount - 1] = NULL;
		CompCount--;
		for (int k = 0; k < SelectionCounter - 1; k++)
		{
			if (*SelectedCompIndexes[SelectionCounter - 1] < *SelectedCompIndexes[k])
			{
				(*SelectedCompIndexes[k])--;
			}
		}
		delete SelectedCompIndexes[SelectionCounter - 1];
		SelectionCounter--;
		if (IsCut)
		{
			if (NumOfConnectionsToGate + 1 == 0)
			{
				NumOfConnectionsToGate = 0;
				return;
			}
			NumOfConnectionsToGate--;
		}
	}
		
}

void ApplicationManager::DeleteWillDeletedList()
{
	if (!IsCut)
	{

		CurrentAction->FillDeletedComponents(WillDeleted, DeleteCompCount);
		

	}
	IsCut = 0;
	for (int i = 0; i < DeleteCompCount; i++)
	{
		delete WillDeleted[i];
	}
	DeleteCompCount = 0;
}

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction(); 	
}

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	CurrentAction = NULL;
	switch (ActType)
	{
	case ADD_AND_GATE_2:
		pAct = new AddANDgate2(this);
		CurrentAction = pAct;
		break;

	case ADD_AND_GATE_3:
		pAct = new AddANDgate3(this);
		CurrentAction = pAct;
		break;

	case ADD_OR_GATE_2:
		pAct = new AddORgate2(this);
		CurrentAction = pAct;
		break;

	case ADD_OR_GATE_3:
		pAct = new AddORgate3(this);
		CurrentAction = pAct;
		break;

	case ADD_INV:
		pAct = new AddINVgate(this);
		CurrentAction = pAct;
		break;

	case ADD_Buff:
		pAct = new AddBuffgate(this);
		CurrentAction = pAct;
		break;

	case ADD_NAND_GATE_2:
		pAct = new AddNANDgate2(this);
		CurrentAction = pAct;
		break;

	case ADD_NAND_GATE_3:
		pAct = new AddNANDgate3(this);
		CurrentAction = pAct;
		break;

	case ADD_NOR_GATE_2:
		pAct = new AddNORgate2(this);
		CurrentAction = pAct;
		break;

	case ADD_NOR_GATE_3:
		pAct = new AddNORgate3(this);
		CurrentAction = pAct;
		break;

	case ADD_XOR_GATE_2:
		pAct = new AddXORgate2(this);
		CurrentAction = pAct;
		break;

	case ADD_XOR_GATE_3:
		pAct = new AddXORgate3(this);
		CurrentAction = pAct;
		break;

	case ADD_XNOR_GATE_2:
		pAct = new AddXNORgate2(this);
		CurrentAction = pAct;
		break;

	case ADD_XNOR_GATE_3:
		pAct = new AddXNORgate3(this);
		CurrentAction = pAct;
		break;
	case ADD_GATES:
		ConstructGatesBar = 1;
		pAct = new AddGatesBar(this);
		CurrentAction = NULL;
		break;
	case EXITGATES:
		ConstructGatesBar = 0;
		pAct= new ClearGatesBar(this);
		CurrentAction = NULL;
		break;
	case SELECT:
		pAct = new Select(this);
		CurrentAction = NULL;
		break;
	case CUT:
		pAct = new Cut(this);
		CurrentAction = pAct;
		break;
	case COPY:
		pAct = new Copy(this);
		CurrentAction = NULL;
		break;
	case PASTE:
		pAct = new Paste(this);
		CurrentAction = NULL;
		break;
	case DEL:
		pAct = new Delete(this);
		CurrentAction = pAct;
		break;
	case UNDO:
		pAct = new UndoAction(this);
		CurrentAction = NULL;
		break;
	   case REDO:
		pAct = new RedoAction(this);
		CurrentAction = NULL;
		break;
	case ADD_CONNECTION:
		//TODO: Create AddConection Action here
		pAct = new AddConnection(this);
		CurrentAction = pAct;
		break;
	case ADD_LED:
		pAct = new AddLamp(this);
		CurrentAction = pAct;
		break;
	case ADD_Switch:
	    pAct = new AddSwitch(this);
		CurrentAction = pAct;
	    break;
	case SIM_MODE:
		pAct = new AddSumlation(this);
		break;
	case Change_Switch:
		pAct = new Convert_Switch(this);
		break;
	case Create_TruthTable:
		break;
		
	case Circuit_Probing:
		pAct = new AddCircuitProbing(this);
	    break;
	case ADD_Label:
		pAct = new AddLabel(this);
		break;
	case EDIT_Label:
		pAct = new Edit_Label (this);
		break;
	case Circuit_Valid:
		pAct = new CircuitValid(this);
		break;
	case EDIT_CONNECTION:
		pAct = new Edit (this);
		break;	
	case SAVE:
		pAct = new save(this);
		break;
	case LOAD:
		pAct = new load(this);
		break;
	case DSN_MODE:
		pAct = new AddDesign(this);
		break;
	case EXIT:
		break;
	}
	bool Is = 1;
	if (CurrentAction)
	{
		Is = 0;
		AddToUndoAct();
	}
	if (pAct && (!dynamic_cast<ClearGatesBar*>(pAct)))
	{
		pAct->Execute();
		if (Is)
		{
			delete pAct;
		}
		pAct = NULL;
	}
}

////////////////////////////////////////////////////////////////////
void ApplicationManager::ConvertAll()
{
	for (int i = 0; i < CompCount; i++)
	{
	CompList[i]->ComponentLow(OutputInterface);
	}
}
void ApplicationManager::set_IDS_COMP(int t)
{
	IDS_COMP = t;
}
void ApplicationManager::UpdateInterface()
{

	if (Cir_Probing) {
		int x, y;//Get the click from the user
		NewProbing->Draw(OutputInterface);// Draw the circuit probring
		OutputInterface->PrintMsg("Click any where to delete the value");
		// wait the click
		InputInterface->GetPointClicked(x, y);
		NewProbing->Clear(OutputInterface);
		OutputInterface->ClearStatusBar();
		Cir_Probing = false;
	}
	if (forEdit)
	{
		OutputInterface->ClearConnection(foredit);
		forEdit = 0;
	}
	if (Editconnection)
	{
		GraphicsInfo temp = Conn_Label->GetCompCoordinates();
		temp.x1 = 10 + (Conn_Label->GetCompCoordinates().x1 + Conn_Label->GetCompCoordinates().x2) / 2;
		if (Conn_Label->GetCompCoordinates().y1 > Conn_Label->GetCompCoordinates().y2)
			temp.y1 = 25 + Conn_Label->GetCompCoordinates().y2 - 20;
		else
		{
			temp.y1 = 25 + Conn_Label->GetCompCoordinates().y1 - 20;
		}
		InputInterface->getwindow()->SetPen(UI.MsgColor);
		InputInterface->getwindow()->DrawString(temp.x1, temp.y1, Conn_Label->getLabel());
		Editconnection = 0;

	}
	if (bar)
	{
		NewBar->Draw(OutputInterface);
		bar = false;
	}
	if (Load)
	{
		for (int k = 0; k < CompCount; k++)
		{
			if (!dynamic_cast<Connection*>(CompList[k]))
				InputInterface->getwindow()->DrawString(CompList[k]->GetCompCoordinates().x1 - 10, CompList[k]->GetCompCoordinates().y1 - 25, CompList[k]->getLabel());

		}
		Load = false;
	}
	if (Label)
	{
		GraphicsInfo temp = Comp_Label->GetCompCoordinates();
		if (dynamic_cast<Connection*>(Comp_Label))
		{
			temp.x1 = 10 + (Comp_Label->GetCompCoordinates().x1 + Comp_Label->GetCompCoordinates().x2) / 2;
			if (Comp_Label->GetCompCoordinates().y1 >= Comp_Label->GetCompCoordinates().y2)
				temp.y1 = 25 + Comp_Label->GetCompCoordinates().y2 - 20;
			else
				temp.y1 = 25 + Comp_Label->GetCompCoordinates().y1 - 20;
		}

		Comp_Label->set_string((InputInterface->GetSrting(OutputInterface, temp)));

		Label = false;
	}
	if (EditLabel)
	{
		GraphicsInfo temp = Comp_Label->GetCompCoordinates();
		if (dynamic_cast<Connection*>(Comp_Label))
		{
			temp.x1 = 10 + (Comp_Label->GetCompCoordinates().x1 + Comp_Label->GetCompCoordinates().x2) / 2;
			if (Comp_Label->GetCompCoordinates().y1 > Comp_Label->GetCompCoordinates().y2)
				temp.y1 = 25 + Comp_Label->GetCompCoordinates().y2 - 20;
			else
				temp.y1 = 25 + Comp_Label->GetCompCoordinates().y1 - 20;
		}

		Comp_Label->set_string((InputInterface->EditSrting(Comp_Label->getLabel(), OutputInterface, temp)));

		EditLabel = false;
	}
	if (ConstructGatesBar == 1)
	{
		GatesBarPtr->Draw(OutputInterface);
	}
	else if (ConstructGatesBar == 0)
	{
		GatesBarPtr->Clear(OutputInterface);
		delete GatesBarPtr;
		ConstructGatesBar = -1;
	}
	if (DeleteCompCount != 0)
	{
		for (int i = 0; i < DeleteCompCount; i++)
		{
			WillDeleted[i]->ClearComp(OutputInterface);
		}
		DeleteWillDeletedList();
	}
	for (int i = 0; i < CompCount; i++)
	{
		bool SelectionTest = 1;
		for (int j = 0; j < SelectionCounter; j++)
		{
			if (i == *SelectedCompIndexes[j])
			{
				CompList[i]->Draw(OutputInterface, true);
				SelectionTest = 0;
				break;
			}
		}
		if (SelectionTest)
		{
			CompList[i]->Draw(OutputInterface, false);
		}
	}
	if (DelCompCount == 1 && !UI.IsDeleteAct && !UI.IsRedoCut)
	{
		GraphicsInfo GfxInfo = RedoAct[RedoCount - 1]->GetCompcoor();
		if (dynamic_cast<AddConnection*>(RedoAct[RedoCount - 1]))
		{
			OutputInterface->ClearConnection(GfxInfo);
		}
		else
		{
			OutputInterface->ClearComponent(GfxInfo);
		}
		DelCompCount = 0;
	}
	else if (UI.IsDeleteAct)
	{
		Action** Temp = UndoAct[UndoCount - 1]->GetDeletedActions();
		int count = UndoAct[UndoCount - 1]->GetCountDelComp();
		for (int i = 0; i < count; i++)
		{
			GraphicsInfo GfxInfo = Temp[i]->GetCompcoor();

			if (dynamic_cast<AddConnection*>(Temp[i]))
			{
				OutputInterface->ClearConnection(GfxInfo);
			}
			else
			{
				OutputInterface->ClearComponent(GfxInfo);
			}
		}
		DelCompCount = 0;
		UI.IsDeleteAct = 0;
	}
	else if (UI.IsRedoCut)
	{
		Action* Temp = UndoAct[UndoCount - 1];
		GraphicsInfo GfxInfo = Temp->GetCompcoor();
		OutputInterface->ClearComponent(GfxInfo);
		UI.IsRedoCut = 0;
	}
}
////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

////////////////////////////////////////////////////////////////////

bool ApplicationManager::ISConnectionValid(GraphicsInfo* p, Component*& comp1, Component*& comp2)
{
	bool done = false;
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->GetCompCoordinates().x1 <= p->x1 && CompList[i]->GetCompCoordinates().x2 >= p->x1 &&
			CompList[i]->GetCompCoordinates().y1 <= p->y1 && CompList[i]->GetCompCoordinates().y2 >= p->y1
			&& dynamic_cast<Connection*>(CompList[i]) == NULL)
		{
			//pIn->GetPointClicked(x2, y2);
			for (int j = 0; j < CompCount; j++)
			{
				if (CompList[j]->GetCompCoordinates().x1 <= p->x2 && CompList[j]->GetCompCoordinates().x2 >= p->x2 &&
					CompList[j]->GetCompCoordinates().y1 <= p->y2 && CompList[j]->GetCompCoordinates().y2 >= p->y2
					&& dynamic_cast<Connection*>(CompList[j]) == NULL && CompList[j] != CompList[i])
				{
					comp1 = CompList[i]; comp2 = CompList[j];

					done = true;
					break;
				}

			}
		}
		if (done)
		{
			break;
		}
	}
	if (done)
		return true;
	return false;
	
}

Component* ApplicationManager::IsClickGate(int x, int y)
{
	for (int i = 0; i < CompCount; i++)
	{
		if (x >= CompList[i]->GetCompCoordinates().x1 && y >= CompList[i]->GetCompCoordinates().y1 && x <= CompList[i]->GetCompCoordinates().x2 && y <= CompList[i]->GetCompCoordinates().y2&&dynamic_cast<Connection*>(CompList[i]) == NULL)
			return CompList[i];
		bool done = false;
		for (int i = 0; i < CompCount; i++)
		{

			if (dynamic_cast<Connection*>(CompList[i]) != NULL)
			{
				int m = (CompList[i]->GetCompCoordinates().x1 + CompList[i]->GetCompCoordinates().x2) / 2;

				if ((CompList[i]->GetCompCoordinates().x1 <= x && m >= x && CompList[i]->GetCompCoordinates().y1 - 4<= y && CompList[i]->GetCompCoordinates().y1 + 4 >= y)
					|| (((CompList[i]->GetCompCoordinates().y1 <= y && CompList[i]->GetCompCoordinates().y2 >= y) || (CompList[i]->GetCompCoordinates().y2 <= y && CompList[i]->GetCompCoordinates().y1 >= y)) && m - 4 <= x && m + 4 >= x)
					|| (m <= x && CompList[i]->GetCompCoordinates().x2 >= x && CompList[i]->GetCompCoordinates().y2 - 4 <= y && CompList[i]->GetCompCoordinates().y2 + 4>= y))

				{
					return CompList[i];

					done = true;
					break;
				}
			}
		}
	}
	return NULL;
}

void ApplicationManager::setload(bool l)
{
	Load = l;
}



void ApplicationManager::arrange() 
{
	Component* COMP[MaxCompCount];
	int Numswitch = 0;
	int NumLamp = 0;
	int total = 0;
	for (int i = 0; i < CompCount; i++)
	{
		if (dynamic_cast<Connection*>(CompList[i]) == NULL)
		{
			COMP[total] = CompList[i];
			total++;
		}
	}
	for (int i = 0; i < total; i++)
	{
		if (dynamic_cast<SWITCH*>(COMP[i]) != NULL)
		{
			COMP[i]->DoAllConnections();
			swap(COMP[i], COMP[Numswitch]);
			Numswitch++;
		}
	}
	for (int i = Numswitch; i < total - NumLamp; i++)
	{
		if (dynamic_cast<LAMP*>(COMP[i]) != NULL)
		{
			swap(COMP[i], COMP[total - NumLamp -1]);
			NumLamp++;
		}
	}

	int smallest_xI;
	for (int i = Numswitch; i < total - NumLamp -1; i++)
	{
			smallest_xI = i;

			for (int j = i + 1; j < total - NumLamp; j++)
			{
				{
					if (COMP[smallest_xI]->GetCompCoordinates().x1 > COMP[j]->GetCompCoordinates().x1)
						smallest_xI = j;
				}
				
			}
			swap(COMP[i], COMP[smallest_xI]);
	}
	/////////////////////operate the gates

	for (int i = Numswitch; i < total - NumLamp; i++)
	{
		COMP[i]->Operate();
		COMP[i]->DoAllConnections();
		
	}
	//////// operate the Lamp
	for (int i = total - NumLamp; i < total; i++)
	{
		COMP[i]->Draw(OutputInterface,0);
		
	}
	
}
bool ApplicationManager::ISSwitchValid(GraphicsInfo p, Component*& comp1)
{
	bool done = false;
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->GetCompCoordinates().x1 <= p.x1 && CompList[i]->GetCompCoordinates().x2 >= p.x1 &&
			CompList[i]->GetCompCoordinates().y1 <= p.y1 && CompList[i]->GetCompCoordinates().y2 >= p.y1 && dynamic_cast<SWITCH*>(CompList[i]) != NULL)
		{
			comp1 = CompList[i];

			done = true;
			break;
		}
	}
	return done;

}
bool  ApplicationManager::Probing(Component*& c, int x, int y)
{
	bool done = false;
	for (int i = 0; i < CompCount; i++)
	{

		if (dynamic_cast<Connection*>(CompList[i]) != NULL)
		{
			int m = (CompList[i]->GetCompCoordinates().x1 + CompList[i]->GetCompCoordinates().x2) / 2;

			if ((CompList[i]->GetCompCoordinates().x1 <= x && m >= x && CompList[i]->GetCompCoordinates().y1 - 4 <= y && CompList[i]->GetCompCoordinates().y1 + 4 >= y)
				|| (((CompList[i]->GetCompCoordinates().y1 <= y && CompList[i]->GetCompCoordinates().y2 >= y) || (CompList[i]->GetCompCoordinates().y2 <= y && CompList[i]->GetCompCoordinates().y1 >= y)) && m - 4<= x && m + 4 >= x)
				|| (m <= x && CompList[i]->GetCompCoordinates().x2 >= x && CompList[i]->GetCompCoordinates().y2 - 4 <= y && CompList[i]->GetCompCoordinates().y2 + 4>= y))

			{
				c = CompList[i];

				done = true;
				break;
			}
		}
	}
	return done;

}
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < CompCount; i++)
	{
		if (dynamic_cast<Connection*>(CompList[i]))
		{
			Component* Temp = CompList[i];
			for (int k = i + 1; k < CompCount; k++)
			{
				CompList[k - 1] = CompList[k];
			}
			CompList[CompCount - 1] = Temp;
			delete CompList[CompCount - 1];
			CompCount--;
			i--;
		}
	}
	for (int i = 0; i < CompCount; i++)
	{
		delete CompList[i];
	}
	for (int i = 0; i < UndoCount; i++)
	{
		delete UndoAct[i];
	}
	for (int i = 0; i < RedoCount; i++)
	{
		delete RedoAct[i];
	}
	delete[] WillDeleted;
	delete OutputInterface;
	delete InputInterface;
	if (!GatesBarPtr)
	{
		delete GatesBarPtr;
	}
	for (int i = 0; i < SelectionCounter; i++)
		delete SelectedCompIndexes[i];
	delete ClipBoard;

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ApplicationManager::SET_ID(Component* idcomp)
{
	//IDS_COMP=1;
	idcomp->setID(IDS_COMP);
	IDS_COMP++;

}

////////////////////////////////


void ApplicationManager::SAVE_ALL(ofstream &Infofile)
{
		for(int i=0; i<CompCount; i++)
			CompList[i]->SAVE(Infofile,0);
		Infofile<<"Connections"<<endl;
		for(int i=0; i<CompCount; i++)
			CompList[i]->SAVE(Infofile,1);
		
		//OutputInterface->PrintMsg("");

}
//////////////////////////////////

int ApplicationManager::Get_CompCount()
{
	return CompCount;		//Actual number of Components
}
/////////////////////////////////

Component ** ApplicationManager:: get_comp_list()
{
	return CompList;
}
void ApplicationManager::addbar(Bar * b)
{
	NewBar = b;
}

void ApplicationManager::setbar(bool b)
{
	bar = b;
}

void ApplicationManager::setProbing(bool p)
{
	Cir_Probing = p;
}

void ApplicationManager::addProbing(CircuitProbing * p)
{
	NewProbing = p;
}

int ApplicationManager::NumConnections()
{
	int numconne = 0;
	for (int i = 0; i < CompCount; i++)
	{
		if (dynamic_cast<Connection*>(CompList[i]))
			numconne++;
	}
	return numconne;
}
void ApplicationManager::SetLabel(bool l)
{
	Label = l;
}

void ApplicationManager::SetEditLabel(bool l)
{
	EditLabel = l;
}

void ApplicationManager::SetLabelComp(Component* l)
{
	Comp_Label = l;
}
void ApplicationManager::RedoConnection(GraphicsInfo GInfo, int PinNum, int& id)
{
	
		Component* Comp1 = NULL;
		Component* Comp2 = NULL;
		for (int i = 0; i < CompCount; i++)
		{
			if (!dynamic_cast<Connection*>(CompList[i]))
			{
				if (CompList[i]->getouppcoor().x == GInfo.x1 && CompList[i]->getouppcoor().y == GInfo.y1)
				{
					Comp1 = CompList[i];
					break;
				}
			}
		}
		for (int i = 0; i < CompCount; i++)
		{
			if (!dynamic_cast<Connection*>(CompList[i]))
			{
				if (dynamic_cast<Gate*>(CompList[i]))
				{
					
					if (CompList[i]->getinppcoor()[PinNum].x == GInfo.x2 && CompList[i]->getinppcoor()[PinNum].y == GInfo.y2)
					{
						Comp2 = CompList[i];
						break;
					}
				}
				else if (dynamic_cast<LAMP*>(CompList[i]))
				{
					LAMP* Temp = dynamic_cast<LAMP*>(CompList[i]);
					if (Temp->getinppcoor()->x == GInfo.x2 && Temp->getinppcoor()->y == GInfo.y2)
					{
						Comp2 = CompList[i];
						break;
					}
				}
			}
		}
		if (Comp1 != NULL && Comp2 != NULL)
		{
			if (Comp2->freeinpp())
			{
				Connection* pA = new Connection(GInfo, Comp1, Comp2, PinNum);

				if (Comp1->getm_outputpin().ConnectTo(pA))
				{
					pA->SetINDX(id);
					AddComponent(pA);
					
				}
				else
				{
					delete pA;
				}
			}
		}
	}

void ApplicationManager::AddToClipBoard()
{
	delete ClipBoard;
	int TargetCompIndex = *SelectedCompIndexes[SelectionCounter - 1];
	if (dynamic_cast<AND2*>(CompList[TargetCompIndex]))
	{
		AND2* temp = dynamic_cast<AND2*>(CompList[TargetCompIndex]);
		ClipBoard = new AND2(*temp);
	}
	else if (dynamic_cast<AND3*>(CompList[TargetCompIndex]))
	{
		AND3* temp = dynamic_cast<AND3*>(CompList[TargetCompIndex]);
		ClipBoard = new AND3(*temp);
	}
	else if (dynamic_cast<NAND2*>(CompList[TargetCompIndex]))
	{
		NAND2* temp = dynamic_cast<NAND2*>(CompList[TargetCompIndex]);
		ClipBoard = new NAND2(*temp);
	}
	else if (dynamic_cast<NAND3*>(CompList[TargetCompIndex]))
	{
		NAND3* temp = dynamic_cast<NAND3*>(CompList[TargetCompIndex]);
		ClipBoard = new NAND3(*temp);
	}
	else if (dynamic_cast<OR2*>(CompList[TargetCompIndex]))
	{
		OR2* temp = dynamic_cast<OR2*>(CompList[TargetCompIndex]);
		ClipBoard = new OR2(*temp);
	}
	else if (dynamic_cast<OR3*>(CompList[TargetCompIndex]))
	{
		OR3* temp = dynamic_cast<OR3*>(CompList[TargetCompIndex]);
		ClipBoard = new OR3(*temp);
	}
	else if (dynamic_cast<NOR2*>(CompList[TargetCompIndex]))
	{
		NOR2* temp = dynamic_cast<NOR2*>(CompList[TargetCompIndex]);
		ClipBoard = new NOR2(*temp);
	}
	else if (dynamic_cast<NOR3*>(CompList[TargetCompIndex]))
	{
		NOR3* temp = dynamic_cast<NOR3*>(CompList[TargetCompIndex]);
		ClipBoard = new NOR3(*temp);
	}
	else if (dynamic_cast<XOR2*>(CompList[TargetCompIndex]))
	{
		XOR2* temp = dynamic_cast<XOR2*>(CompList[TargetCompIndex]);
		ClipBoard = new XOR2(*temp);
	}
	else if (dynamic_cast<XOR3*>(CompList[TargetCompIndex]))
	{
		XOR3* temp = dynamic_cast<XOR3*>(CompList[TargetCompIndex]);
		ClipBoard = new XOR3(*temp);
	}
	else if (dynamic_cast<XNOR2*>(CompList[TargetCompIndex]))
	{
		XNOR2* temp = dynamic_cast<XNOR2*>(CompList[TargetCompIndex]);
		ClipBoard = new XNOR2(*temp);
	}
	else if (dynamic_cast<XNOR3*>(CompList[TargetCompIndex]))
	{
		XNOR3* temp = dynamic_cast<XNOR3*>(CompList[TargetCompIndex]);
		ClipBoard = new XNOR3(*temp);
	}
	else if (dynamic_cast<INV*>(CompList[TargetCompIndex]))
	{
		INV* temp = dynamic_cast<INV*>(CompList[TargetCompIndex]);
		ClipBoard = new INV(*temp);
	}
	else if (dynamic_cast<Buff*>(CompList[TargetCompIndex]))
	{
		Buff* temp = dynamic_cast<Buff*>(CompList[TargetCompIndex]);
		ClipBoard = new Buff(*temp);
	}
	else if (dynamic_cast<LAMP*>(CompList[TargetCompIndex]))
	{
		LAMP* temp = dynamic_cast<LAMP*>(CompList[TargetCompIndex]);
		ClipBoard = new LAMP(*temp);
	}
	else if (dynamic_cast<SWITCH*>(CompList[TargetCompIndex]))
	{
		SWITCH* temp = dynamic_cast<SWITCH*>(CompList[TargetCompIndex]);
		ClipBoard = new SWITCH(*temp);
	}

}
bool ApplicationManager::IsCircuitValid()
{
	bool Valid = true;
	for (int i = 0; i < CompCount; i++)
	{
		if (dynamic_cast<LAMP*>(CompList[i]) == NULL && dynamic_cast<Connection*>(CompList[i]) == NULL)
		{
			if (CompList[i]->getm_outputpin().getmconn() < 1)
			{
				Valid = false;
				return Valid;
			}

		}
		if (dynamic_cast<SWITCH*>(CompList[i]) == NULL && dynamic_cast<Connection*>(CompList[i]) == NULL)

		{
			if (CompList[i]->freeinpp() == true)
			{
				Valid = false;
				return Valid;
			}
		}
	}
	return Valid;

}
void ApplicationManager::SetEditConnLabel(bool l)
{
	Editconnection = l;
}
void ApplicationManager::SetConnlabel(Connection* l)
{
	Conn_Label = l;
}
Component* ApplicationManager::GetlastSelected()
{
	if (CompList[*SelectedCompIndexes[SelectionCounter - 1]])
		return CompList[*SelectedCompIndexes[SelectionCounter - 1]];
	return NULL;
}
void ApplicationManager::Delete_Conn(bool Cut)
{
	Connection* conn = dynamic_cast<Connection*>(CompList[*SelectedCompIndexes[SelectionCounter - 1]]);
	for (int j = *SelectedCompIndexes[SelectionCounter - 1] + 1; j < CompCount; j++)
	{
		CompList[j - 1] = CompList[j];
	}
	CompList[CompCount - 1] = conn;
	foredit = conn->GetCompCoordinates();
	delete conn;
	forEdit = 1;
	CompCount--;
	for (int k = 0; k < SelectionCounter - 1; k++)
	{
		if (*SelectedCompIndexes[SelectionCounter - 1] < *SelectedCompIndexes[k])
		{
			(*SelectedCompIndexes[k])--;
		}
	}
	delete SelectedCompIndexes[SelectionCounter - 1];
	SelectionCounter--;
}
//////////////////////////////////