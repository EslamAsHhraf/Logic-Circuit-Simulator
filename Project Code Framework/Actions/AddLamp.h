#pragma once
#include "Action.h"
#include"..\Components\LAMP.h"
class AddLamp :
	public Action
{
private:
	//Parameters for rectangular area to be occupied by the lamp
	int Cx, Cy;	//Center point of the lamp
	GraphicsInfo GInfo;
public:
	AddLamp(ApplicationManager* pApp);
	virtual ~AddLamp(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	virtual GraphicsInfo GetCompcoor();
	virtual void SetCompcoor(GraphicsInfo GxInfo);

	virtual void Undo();
	virtual void Redo();


};