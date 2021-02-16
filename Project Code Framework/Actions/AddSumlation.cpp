#include "..\ApplicationManager.h"
# include"AddSumlation.h"
AddSumlation::AddSumlation(ApplicationManager* pApp) :Action(pApp)
{
}

 AddSumlation::~AddSumlation(void)
{
}

void  AddSumlation::ReadActionParameters()
{
	
	
	
	
}

void  AddSumlation::Execute()
{
	Output* pOut = pManager->GetOutput();
	
	if (pManager->IsCircuitValid())
	{
		SumlationBar *pA = new SumlationBar;
		// sumlate the circuit
		pManager->arrange();
		// make the bool true to draw dseign bar
		pManager->setbar(true);
		//add deign bar
		pManager->addbar(pA);
		pOut->PrintMsg("Switch to sumaltion bar");
	}
	else 
	pOut->PrintMsg("The circuit is not valid so you can't switch to sumaltion bar");


}

void  AddSumlation::Undo()
{}

void  AddSumlation::Redo()
{}