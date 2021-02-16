#pragma once
#include "Action.h"
#include "..\Components\DesignBar.h"
class AddDesign :
	public Action
{
public:
	AddDesign(ApplicationManager* pApp);
	virtual ~AddDesign(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

