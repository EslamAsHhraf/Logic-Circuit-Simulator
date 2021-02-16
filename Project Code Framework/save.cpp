#include "save.h"

save::save(ApplicationManager* pApp) :Action(pApp)
{
}

//Reads parameters required for action to execute
void save::ReadActionParameters() {}
//Execute action (code depends on action type)
void save::Execute()
{


	(pManager->GetOutput())->PrintMsg("Please enter the file name to be saved in with extend(.txt): ");
	string file_name = pManager->GetInput()->GetSrting_old(pManager->GetOutput());//take the name file from the user


	ofstream Infofile(file_name);//open the file



	//checking if the save action is done or not
	if (!(Infofile.is_open()))
	{
		cout << "errer";
	}

	else
		cout << "done";



	int numconnect = pManager->NumConnections();
	Infofile << (pManager->Get_CompCount() - numconnect) << endl;

	pManager->SAVE_ALL(Infofile);
	Infofile << "-1" << endl;//-1 is an endecate that the save action is finished
	Infofile.close();//you should close the file when you finish
	
}

void save::Undo() {}
void save::Redo() {}

save:: ~save(void) {}



