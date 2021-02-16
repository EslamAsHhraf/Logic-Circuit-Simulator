#pragma once
#include "Action.h"
#include"..\ApplicationManager.h"
//class Action;
//class ApplicationManager;
class ClearGatesBar : public Action
{
public:
	ClearGatesBar(ApplicationManager* pApp);
	~ClearGatesBar(void);
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
	virtual void ClearGatesBar_(Output* pOut);
};

