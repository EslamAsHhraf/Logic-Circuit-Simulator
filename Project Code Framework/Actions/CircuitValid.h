#pragma once
#include "Action.h"
class CircuitValid : public Action
{
private:
	//int x, y;
public:
	CircuitValid(ApplicationManager* pApp);
	virtual ~CircuitValid(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

