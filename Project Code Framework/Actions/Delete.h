#pragma once
#include "action.h"
class Delete : public Action
{/*
	Component** DeletedComponents;*/
	int CountDelComp;
	Action*DeletedActions[MaxCompCount];
	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate
	//int IDs[MaxCompCount / 20];
public:
	Delete(ApplicationManager* pApp);
	virtual ~Delete(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	/*;
	virtual Component** GetDeletedComponents();
	*/
	virtual int GetCountDelComp();
	virtual void FillDeletedComponents(Component** WilldeletedComp, int Count);
	virtual Action** GetDeletedActions();
	virtual void Undo();
	virtual void Redo();
};