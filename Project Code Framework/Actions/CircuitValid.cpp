#include "CircuitValid.h"

CircuitValid::CircuitValid(ApplicationManager* pApp):Action(pApp)
{
}

CircuitValid::~CircuitValid(void)
{
}

void CircuitValid::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Chiking Validation");

	//Clear Status Bar
	pOut->ClearStatusBar();
}

void CircuitValid::Execute()
{
	Output* pOut = pManager->GetOutput();
	if(pManager->IsCircuitValid()==true)
		pOut->PrintMsg("Circuit is valid now You can enter Simulation mode");
	else
		pOut->PrintMsg("Circuit is Invalid make sure that every pin is connected");
}

void CircuitValid::Undo()
{
}

void CircuitValid::Redo()
{
}
