#include "load.h"
//#include <sstream> 
load::load(ApplicationManager* pApp) :Action(pApp)
{
}

//Reads parameters required for action to execute
void load::ReadActionParameters() {}
//Execute action (code depends on action type)
void load::Execute()
{
	pManager->setload(true);
	//char *name=new char[30];
	(pManager->GetOutput())->PrintMsg("Please enter the file name to be loaded with extend(.txt): ");
	string file_name = pManager->GetInput()->GetSrting_old(pManager->GetOutput());
	ifstream gfile(file_name);

	
	Component *PAA;
	int cmp;//the result of comparison between the string in the txt and "Connection"
	char *p = new char[6];//container of the type of component               
	int nc;//Number of Components without Connections
	int idc;//ID of the component
	
	string labee;//container of the component label 
	GraphicsInfo GInfoo;
	
	int com_id1, com_id2;
	Component * com_p1;//The sorce component of the connection
	Component * com_p2;//The destination component of the connection
	int pinee;//the number of pin of dest comp that the connection connect to , start from 0
	pincoor *inp_p;
	pincoor out_p;
	
	int check;
	gfile >> nc;
	pManager->set_IDS_COMP(nc+1);
	Component **COMP_P;//= new Component*[nc];
	//to avoid the error happen some time if the program can not close the file, we will use onther bool
	bool file_Open = gfile.is_open();
	while (file_Open)
	{
		//labee = new char[20];			
		gfile >> p;
		cmp = strncmp(p, "C", 1);
		if (cmp > 0 || cmp < 0)// if we do not in the line "Connections" 
		{
			gfile >> idc;
			gfile >> labee;
			//check if what readed is a label or not
			check = labee[0];
			if (check >= 48 && check <= 57)
			{
				//if there is no label for the component then what readed is GInfoo.x1
				//so we will convert this string to int 
				stringstream convert(labee);
				GInfoo.x1 = 0;
				convert >> GInfoo.x1;
								
				labee = "No Label";
				
			}
			else
			{
				gfile >> GInfoo.x1;
			}
			gfile >> GInfoo.y1;
			GInfoo.x2 = GInfoo.x1 + 50;
			GInfoo.y2 = GInfoo.y1 + 50;
			//strncmp return 0 if the two strings is equal so we take the inverter 
			//as the invwerter equals 0 if they are not totaly equal 
			if (!(strncmp(p, "AND2", 4)))
			{
				

				PAA = new AND2(GInfoo, AND2_FANOUT);
				PAA->set_string(labee);
				PAA->setID(idc);
				
			}

			else if (!(strncmp(p, "AND3", 4)))
			{
				PAA = new AND3(GInfoo, AND2_FANOUT);
				PAA->setID(idc);
				PAA->set_string(labee);
			}
			else if (!(strncmp(p, "NAND2", 5)))
			{
				PAA = new NAND2(GInfoo, AND2_FANOUT);
				PAA->setID(idc);
				PAA->set_string(labee);
			}

			else if (!(strncmp(p, "NAND3", 5)))
			{
				PAA = new NAND3(GInfoo, AND2_FANOUT);
				PAA->setID(idc);
				PAA->set_string(labee);
			}
			else if (!(strncmp(p, "OR2", 3)))
			{
				PAA = new OR2(GInfoo, AND2_FANOUT);
				PAA->setID(idc);
				PAA->set_string(labee);

			}
			else if (!(strncmp(p, "OR3", 3)))
			{
				PAA = new OR3(GInfoo, AND2_FANOUT);
				PAA->setID(idc);
				PAA->set_string(labee);
			}
			else if (!(strncmp(p, "NOR2", 4)))
			{
				PAA = new NOR2(GInfoo, AND2_FANOUT);
				PAA->setID(idc);
				PAA->set_string(labee);
			}
			else if (!(strncmp(p, "NOR3", 4)))
			{
				PAA = new NOR3(GInfoo, AND2_FANOUT);
				PAA->setID(idc);
				PAA->set_string(labee);
			}
			else if (!(strncmp(p, "XOR2", 4)))
			{
				PAA = new XOR2(GInfoo, AND2_FANOUT);
				PAA->setID(idc);
				PAA->set_string(labee);
			}
			else if (!(strncmp(p, "XOR3", 4)))
			{
				PAA = new XOR3(GInfoo, AND2_FANOUT);
				PAA->setID(idc);
				PAA->set_string(labee);
			}
			else if (!(strncmp(p, "XNOR2", 5)))
			{
				PAA = new XNOR2(GInfoo, AND2_FANOUT);
				PAA->setID(idc);
				PAA->set_string(labee);
			}
			else if (!(strncmp(p, "XNOR3", 5)))
			{
				PAA = new XNOR3(GInfoo, AND2_FANOUT);
				PAA->setID(idc);
				PAA->set_string(labee);
			}
			else if (!(strncmp(p, "NOT", 3)))
			{
				PAA = new INV(GInfoo, AND2_FANOUT);
				PAA->setID(idc);
				PAA->set_string(labee);
			}
			else if (!(strncmp(p, "BU", 2)))
			{
				PAA = new Buff(GInfoo, AND2_FANOUT);
				PAA->setID(idc);
				PAA->set_string(labee);
			}
			else if (!(strncmp(p, "SW", 2)))
			{
				PAA = new SWITCH(GInfoo, AND2_FANOUT);
				PAA->setID(idc);
				PAA->set_string(labee);
			}
			else if (!(strncmp(p, "LA", 2)))
			{
				PAA = new LAMP(GInfoo, AND2_FANOUT);
				PAA->setID(idc);
				PAA->set_string(labee);
			}		
			pManager->AddComponent(PAA);
			

		}
		else
		{
			COMP_P = pManager->get_comp_list();
			gfile >> com_id1;
			while (com_id1 != -1)
			{
				gfile >> com_id2;
				gfile >> pinee;
				for (int u = 0; u < nc; u++)
				{
					if (COMP_P[u]->get_ID() == com_id1)
					{
						
						com_p1 = COMP_P[u];
						out_p = COMP_P[u]->getouppcoor();
						GInfoo.x1 = out_p.x;
						GInfoo.y1 = out_p.y;
					}

				}
				for (int u = 0; u < nc; u++)
				{
					if (COMP_P[u]->get_ID() == com_id2)
					{

						com_p2 = COMP_P[u];
						//GInfoo.x2=COMP_P[u]->Get_ginfo().x1;

						inp_p = COMP_P[u]->getinppcoor();
						GInfoo.x2 = inp_p[pinee].x;
						GInfoo.y2 = inp_p[pinee].y;
					}

				}

				
				if (com_p2->freeinpp())
				{
					Connection* pA;
					pA = new Connection(GInfoo, com_p1, com_p2, pinee);

					if (com_p1->getm_outputpin().ConnectTo(pA))
					{
						pManager->AddComponent(pA);
					}

					else
					{
						delete pA;
					}

				}

				gfile >> com_id1;
				
			}
			
			gfile.close();//close file if the connections while loop ended
			file_Open = false;
		}

	}
	
}

void load::Undo() {}
void load::Redo() {}

load:: ~load(void) {}


