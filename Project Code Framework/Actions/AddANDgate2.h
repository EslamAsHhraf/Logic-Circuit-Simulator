#ifndef _ADD_AND_GATE_H
#define _ADD_AND_GATE_H

#include "Action.h"
#include "..\Components\AND2.h"

class AddANDgate2 :	public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	GraphicsInfo GInfo; //to save the GraphicsInfo of the added gate ////used for undo and redo
	int Cx, Cy;	//Center point of the gate
public:
	AddANDgate2(ApplicationManager *pApp);
	virtual ~AddANDgate2(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
	GraphicsInfo GetCompcoor();
	virtual void SetCompcoor(GraphicsInfo GxInfo);
};

#endif