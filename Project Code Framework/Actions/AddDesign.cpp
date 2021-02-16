#include "AddDesign.h"
#include "..\ApplicationManager.h"
AddDesign::AddDesign(ApplicationManager* pApp) :Action(pApp)
{
}

AddDesign::~AddDesign(void)
{
}

void  AddDesign::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMsg("Switch to design bar");




}

void  AddDesign::Execute()
{
	//print massage to the user
	ReadActionParameters();
	DesignBar *pA = new DesignBar;
	// make the Circuit unsumlate
	pManager->ConvertAll();
	// make the bool true to draw dseign bar
	pManager->setbar(true);
	//add deign bar
	pManager->addbar(pA);



}

void  AddDesign::Undo()
{}

void AddDesign::Redo()
{}