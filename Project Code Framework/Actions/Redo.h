#pragma once
#include "Action.h"
class RedoAction :
    public Action
{
public:
	RedoAction(ApplicationManager* pApp);
	virtual ~RedoAction(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

