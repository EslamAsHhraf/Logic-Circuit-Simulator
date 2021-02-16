#pragma once
#include "action.h"
#include "..\Components\SumlationBar.h"

class AddSumlation : public Action
{

	
	
public:
	AddSumlation(ApplicationManager* pApp);
	virtual ~AddSumlation(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};


