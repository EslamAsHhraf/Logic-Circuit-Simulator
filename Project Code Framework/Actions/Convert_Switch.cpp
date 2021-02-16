#include "Convert_Switch.h"
#include "..\ApplicationManager.h"
#include"../Components/SWITCH.h"
Convert_Switch::Convert_Switch(ApplicationManager* pApp) :Action(pApp)
{

}

Convert_Switch::~Convert_Switch(void)
{

}

void Convert_Switch::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Click on the switch to change it's statuas");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Convert_Switch::Execute()
{
	Output* pOut = pManager->GetOutput();
	//Get Center point of the Gate
	ReadActionParameters();
	GraphicsInfo click;
	click.x1 = Cx;
	click.y1 = Cy;
	Component* comp1 = NULL;
	if (pManager->ISSwitchValid(click, comp1))
	{

		comp1->convert();
		pManager->arrange();
		pOut->PrintMsg("Simulate the Circuit");


	}
	
	
}

void Convert_Switch::Undo()
{}

void Convert_Switch::Redo()
{}