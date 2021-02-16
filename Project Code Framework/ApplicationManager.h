#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H
#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Components\Component.h"
#include "Components\GatesBar.h"
#include "Actions\Action.h"
#include "Components\Bar.h"
#include "Components\Circuit_Probing.h"
class Action;
class ApplicationManager
{

private:

	int CompCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)
	int* SelectedCompIndexes[MaxCompCount];
	int SelectionCounter;
	int ConstructGatesBar;
	GatesBar* GatesBarPtr;
	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface
	Component* ClipBoard;
	static int CountPasting;
	int DeleteCompCount;
	Component** WillDeleted;
	bool IsCut;
	bool Load;
	Action* CurrentAction;
	Action *UndoAct[MaxCompCount];
	Action *RedoAct[MaxCompCount];
	int UndoCount;
	int RedoCount;
	int DelCompCount;
	int IDS_COMP;
	bool bar;// bool to know draw the bar or not
	Bar* NewBar;
	CircuitProbing* NewProbing;
	bool Cir_Probing; // bool to know Probing the bar or not
	bool Label, EditLabel;
	Component* Comp_Label;
	int NumOfConnectionsToGate;
	bool Editconnection;
	Connection* Conn_Label;
	bool forEdit;
	GraphicsInfo foredit;
public:	
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();
	
	//Adds a new component to the list of components
	void AddComponent(Component* pComp);
	void DelComponent(int id);
	void AddGatesBarPtr(GatesBar* Gates_Bar);
	void AddToUndoAct();
	Action*& GetLastActionUndo();
	Action*& GetLastActionRedo();
	//void AddToRedoAct();
	void RemoveUndoAct();
	void RemoveRedoAct();
	void ClearGatesBarPtr();
	void Selection(int x, int y);
	void Copying();
	Component*& Cutting();
	void Pasting(const GraphicsInfo &GInfo);
	void Deleting(bool Cut = 0);
	void AddToClipBoard();
	void DeleteWillDeletedList();
	bool ISConnectionValid(GraphicsInfo* p, Component*& comp1, Component*& comp2);//fathi
	bool ISSwitchValid(GraphicsInfo p, Component*& comp1);
	void arrange();
	bool Probing(Component*& c, int x, int y);
	int Get_CompCount();
	void SAVE_ALL(ofstream &Infofile);
	
	Component ** get_comp_list();
	void SET_ID(Component* idcomp);

	void addbar(Bar* b);// add design bar or sumlation bar tp the pointer to draw
	void setbar(bool b);
	void setProbing(bool p);
	void addProbing(CircuitProbing* p);// add probing to the pointer to draw
	int NumConnections();
	
	~ApplicationManager();
	void RedoConnection(GraphicsInfo GInfo, int PinNum, int& id);
	void SetLabel(bool l);
	void SetEditLabel(bool l);
	void SetLabelComp(Component* l);
	Component* IsClickGate(int x, int y);//label
	void setload(bool l);
	void SetEditConnLabel(bool l);
	void SetConnlabel(Connection* l);
	Component* GetlastSelected();
	void Delete_Conn(bool Cut = 0);
	bool IsCircuitValid();
	void ConvertAll();// Make all Compnent Low
	void set_IDS_COMP(int t);
};

#endif