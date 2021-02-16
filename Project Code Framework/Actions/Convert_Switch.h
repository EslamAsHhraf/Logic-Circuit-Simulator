#pragma once
#include "Action.h"
class Convert_Switch :
    public Action
{


	private:
		
		int Cx, Cy;	//The coordinates of the user's click 
		
	public:
		Convert_Switch(ApplicationManager* pApp);
		virtual ~Convert_Switch(void);

		//Reads parameters required for action to execute
		virtual void ReadActionParameters();
		//Execute action (code depends on action type)
		virtual void Execute();

		virtual void Undo();
		virtual void Redo();


	};



