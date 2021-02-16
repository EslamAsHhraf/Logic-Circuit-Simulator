#pragma once
#include "action.h"
#include "..\Components\XOR2.h"
class AddXORgate2 : public Action
{
private:
	GraphicsInfo GInfo;
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
public:
	AddXORgate2(ApplicationManager* pApp);
	virtual ~AddXORgate2(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
	GraphicsInfo GetCompcoor();
	virtual void SetCompcoor(GraphicsInfo GxInfo);
};

