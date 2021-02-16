#pragma once
#include <iostream>
#include"Actions\Action.h"
#include <fstream>
#include "ApplicationManager.h"
using namespace std;
class save: public Action
{
public:
	
	public:
	save(ApplicationManager *pApp);
	virtual ~save(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

	
};

