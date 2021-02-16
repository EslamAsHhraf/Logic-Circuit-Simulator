#pragma once
#include "action.h"
#include "..\Components\NAND2.h"
class AddNANDgate2 : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	GraphicsInfo GInfo;
public:
	AddNANDgate2(ApplicationManager* pApp);
	virtual ~AddNANDgate2(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
	GraphicsInfo GetCompcoor();
	virtual void SetCompcoor(GraphicsInfo GxInfo);
};


