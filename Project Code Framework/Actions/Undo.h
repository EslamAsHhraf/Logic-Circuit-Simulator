#pragma once
#include "Action.h"
class UndoAction :
    public Action
{
public:
	UndoAction(ApplicationManager* pApp);
	virtual ~UndoAction(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

