#pragma once
#include "action.h"
class Cut : public Action
{
private:
	int x, y;
	Action* CuttedAction;//to save the cutted action
	GraphicsInfo GInfo;
public:
	Cut(ApplicationManager* pApp);
	virtual ~Cut(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void SetCompcoor(GraphicsInfo GxInfo);
	virtual GraphicsInfo GetCompcoor();
	virtual void Undo();
	virtual void Redo();
};



