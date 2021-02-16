#pragma once
#include "Action.h"
#include"../Components/Connection.h"
#include"../Components/SWITCH.h"
#include"../Components/LAMP.h"

class Edit :
    public Action
{
private:
	GraphicsInfo coOr;
	int x1, y1, x2, y2, x3, y3;
public:
	Edit(ApplicationManager* pApp);
	virtual ~Edit(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

