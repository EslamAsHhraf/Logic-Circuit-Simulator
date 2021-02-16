#pragma once
#include "action.h"
#include "..\Components\NOR3.h"
class AddNORgate3 : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	GraphicsInfo GInfo;
public:
	AddNORgate3(ApplicationManager* pApp);
	virtual ~AddNORgate3(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
	GraphicsInfo GetCompcoor();
	virtual void SetCompcoor(GraphicsInfo GxInfo);
};
