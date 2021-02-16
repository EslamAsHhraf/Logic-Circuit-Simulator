#pragma once
#include "action.h"
#include"..\ApplicationManager.h"
#include "..\Components\GatesBar.h"
//class ApplicationManager;
//class Action;
class AddGatesBar : public Action
{
public:
	AddGatesBar(ApplicationManager* pApp);
	~AddGatesBar(void);
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
	virtual void CreateGatesBar(Output* pOut);
	
};

