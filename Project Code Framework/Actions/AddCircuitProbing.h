#pragma once
#include "Action.h"
#include"..\Components\Circuit_Probing.h"
class AddCircuitProbing :
	public Action
{
private:
	
	int Cx, Cy;	//coordinates of click of user
	
public:
	AddCircuitProbing(ApplicationManager *pApp);
	virtual ~AddCircuitProbing(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};

