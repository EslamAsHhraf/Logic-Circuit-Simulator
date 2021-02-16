#pragma once
#include "Action.h"
# include"..\Components\SWITCH.h"

class AddSwitch : public Action
{

private:
	//Parameters for rectangular area to be occupied by the switch
	int Cx, Cy;	//Center point of the switch
	GraphicsInfo GInfo;
public:
	AddSwitch(ApplicationManager* pApp);
	virtual ~AddSwitch(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	virtual GraphicsInfo GetCompcoor();
	virtual void SetCompcoor(GraphicsInfo GxInfo);
	virtual void Undo();
	virtual void Redo();


};