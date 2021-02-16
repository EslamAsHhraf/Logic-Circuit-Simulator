#pragma once
#include "Action.h"
#include"../Components/Component.h"
class Edit_Label :public Action
{
private:

	int x, y;	//Two start point of the label
public:
	Edit_Label(ApplicationManager* pApp);
	virtual ~Edit_Label(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

