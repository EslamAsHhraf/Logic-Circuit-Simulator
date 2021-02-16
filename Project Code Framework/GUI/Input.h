#pragma once

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "UI_Info.h"

class Output;
class Input		//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window

public:
	Input(window*);
	void GetPointClicked(int&, int&);	//Get coordinate where user clicks
	
	string GetSrting_old(Output*);		//Returns a string entered by the user
	string GetSrting(Output *pOut, GraphicsInfo r_GfxInfo); // Returns a string entered by the user and Draw sting according to GraphicsInfo
	string EditSrting(string old, Output* pOut, GraphicsInfo r_GfxInfo);
	ActionType GetUserAction() const; //Reads the user click and maps it to an action
	window* getwindow();

	~Input();
};

