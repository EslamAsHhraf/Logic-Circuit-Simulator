#pragma once
#include "..\ApplicationManager.h"
class ApplicationManager; //forward class declaration
//Base class for all possible actions (abstract class)

class Action
{
protected:
	ApplicationManager *pManager;	//Actions needs AppMngr to do their job

public:
	int CID;//to save the index of the component added
	Action(ApplicationManager *pApp):CID(-1){ pManager = pApp; }	//constructor
	
	//Reads parameters required for action to execute
	virtual void ReadActionParameters()=0;
	
	//Execute action (code depends on action type)
	virtual void Execute()=0;

	//To undo this action (code depends on action type)
	virtual void Undo()=0;

	//To redo this action (code depends on action type)
	virtual void Redo()=0;
	//To save The num of the pin The connection connected to
	virtual void SetDisPinNum(int PinNum);
	// to return the coordinates of the Component added
	virtual GraphicsInfo GetCompcoor();
	//to change the coordinates the component will added in
	virtual void SetCompcoor(GraphicsInfo GxInfo);
	//to get the number of actions will deleted in deleteAct 
	virtual int GetCountDelComp();
	//to take the information of the components will deleted
	virtual void FillDeletedComponents(Component** DC, int Count);
	//to get the actions will deleted in deleteAct 
	virtual Action** GetDeletedActions();
	//destructor
	virtual ~Action();
};