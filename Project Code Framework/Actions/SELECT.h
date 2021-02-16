#pragma once
#include "action.h"
class Select:public Action
{
private:
	int x, y;
public:
	Select(ApplicationManager* pApp);
	virtual ~Select(void);
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();

};

