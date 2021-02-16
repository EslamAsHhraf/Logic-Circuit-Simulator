//#include "Input.h"
#include "Output.h"

Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}
////////////////////////////////////////////////////////////////////////////////////////////////////
string Input::GetSrting_old(Output *pOut)
{
	string label = " ";//virtual name
	char d;
	while (true)
	{
		pWind->WaitKeyPress(d);
		if (d == 27)
			return label;
		else if (d == 8)
		{
			if (label.size() != 0)
				label.resize(label.size() - 1);
			pOut->PrintMsg(label);
		}
		else if (d == 13)
			return label;
		else
		{
			label += d;
			pOut->PrintMsg(label);
			//pWind->DrawString(r_GfxInfo.x1-10, r_GfxInfo.y1-25, label);

		}
	}

}

string Input::GetSrting(Output *pOut, GraphicsInfo r_GfxInfo)
{
	pOut->PrintMsg("Set Component Name :");

		string label = " ";//virtual name
	char d;
	while (true)
	{
		pWind->WaitKeyPress(d);
		if (d == 27)
			return label;
		else if (d == 8)
		{
			
			
			if (label.size() != 0)
				label.resize(label.size() - 1);
			
			
			pWind->SetPen(WHITE, 1);
			pWind->SetBrush(WHITE);
			pWind->DrawRectangle(r_GfxInfo.x1-10, r_GfxInfo.y1-25, r_GfxInfo.x2+10, r_GfxInfo.y1);
			pOut->PrintMsg(label);
				pWind->DrawString(r_GfxInfo.x1 - 10, r_GfxInfo.y1 - 25,label);
		}
		else if (d == 13)
			return label;
		else
		{
			label += d;
			pOut->PrintMsg(label);
			pWind->DrawString(r_GfxInfo.x1-10, r_GfxInfo.y1-25, label);

		}
	}
	
}


//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
	int ClickedItemOrder = (x / UI.ToolItmWidthDsign);
	if (UI.AppMode == DESIGN)	//application is in design mode
	{
		
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			
			switch (ClickedItemOrder)
			{
				
			case ITM_ADD_GATES:return ADD_GATES;
			case ITM_lamp: return ADD_LED;
			case ITM_Switch: return ADD_Switch;
			case ITM_Connection:return ADD_CONNECTION;
			case ITM_CUT: return CUT;
			case ITM_COPY: return COPY;
			case ITM_PASTE: return PASTE;
			case ITM_DEL: return DEL;
			case ITM_UNDO: return UNDO;
			case ITM_REDO: return REDO;
			case ITM_LABEL: return ADD_Label;
			case ITM_EDITLABEL: return EDIT_Label;
			case ITM_EDITCONNECTION: return EDIT_CONNECTION;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD: return LOAD; 
			case ITM_EXIT: return EXIT;
			case ITM_SIM_MODE: return SIM_MODE;
				
			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}
		if (UI.IsGatesBarConstructed == 1)
		{
			if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight && x>3 * UI.ToolItemWidth + 4 && x < UI.width)
			{
				return SELECT;	//user want to select/unselect a component
			}
			else if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight && x < 3 * UI.ToolItemWidth + 4)
			{
				if (x > 2 * UI.ToolItemWidth + 4 && (y < 3.5 * UI.ToolItemWidth || y > 4.5 * UI.ToolItemWidth))
				{
					return SELECT;
				}
				else if (x > 2 * UI.ToolItemWidth + 4)
				{
					return EXITGATES;
				}
				else if (x < UI.ToolItemWidth + 3)
				{
					int ClickedItemOrder = ((y - UI.ToolBarHeight) / (5.25 * UI.ToolItemWidth / 6));
					//Divide x coord of the point clicked by the menu item width (int division)
					//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

					switch (ClickedItemOrder)
					{
					case ITM_AND2 - GATES - 1: return ADD_AND_GATE_2;
					case ITM_OR2 - GATES - 1: return ADD_OR_GATE_2;
					case ITM_INV - GATES - 1: return ADD_INV;
					case ITM_BUFFER - GATES - 1: return ADD_Buff;
					case ITM_NAND2 - GATES - 1: return ADD_NAND_GATE_2;
					case ITM_NOR2 - GATES - 1: return ADD_NOR_GATE_2;
					case ITM_XOR2 - GATES - 1: return ADD_XOR_GATE_2;

					}
				}
				else
				{
					int ClickedItemOrder = ((y - UI.ToolBarHeight) / (5.25 * UI.ToolItemWidth / 6));
					//Divide x coord of the point clicked by the menu item width (int division)
					//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

					switch (ClickedItemOrder)
					{
					case ITM_XNOR2 - GATES_3INPUTS - 1: return ADD_XNOR_GATE_2;
					case ITM_AND3 - GATES_3INPUTS - 1: return ADD_AND_GATE_3;
					case ITM_OR3 - GATES_3INPUTS - 1: return ADD_OR_GATE_3;
					case ITM_NAND3 - GATES_3INPUTS - 1: return ADD_NAND_GATE_3;
					case ITM_NOR3 - GATES_3INPUTS - 1: return ADD_NOR_GATE_3;
					case ITM_XOR3 - GATES_3INPUTS - 1: return ADD_XOR_GATE_3;
					case ITM_XNOR3 - GATES_3INPUTS - 1: return ADD_XNOR_GATE_3;
					}
				}
			}
		}
		else
		{
			//[2] User clicks on the drawing area
			if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
			{
				return SELECT;	//user want to select/unselect a component
			}
		}


		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{
	switch (ClickedItemOrder)
	{
	case	ITM_SIM: return Change_Switch;	//Simulate menu item
	case ITM_TRUTH: return Create_TruthTable;	//Truth table menu item
	case	ITM_CIRVALID: return Circuit_Valid;
	case 	ITM_CIRPROB: return Circuit_Probing;
	case	ITM_EXIT2: return EXIT;
	case  ITM_SWITCHTO: return  DSN_MODE;
	}
		//This should be changed after creating the compelete simulation bar 
	}
}
window * Input::getwindow()
{
	return pWind;
}
string Input::EditSrting(string old, Output* pOut, GraphicsInfo r_GfxInfo)
{
	
		//pOut->PrintMsg("Set Component Name :");

			//string label = " ";//virtual name

		string label = old;
		pOut->PrintMsg(label);
		char d;
		while (true)
		{
			pWind->WaitKeyPress(d);
			if (d == 27)
				return label;
			else if (d == 8)
			{
				if (label.size() != 0)
					label.resize(label.size() - 1);

				
				pWind->SetPen(WHITE, 1);
				pWind->SetBrush(WHITE);
				pWind->DrawRectangle(r_GfxInfo.x1 - 10, r_GfxInfo.y1 - 25, r_GfxInfo.x2 + 10, r_GfxInfo.y1);
				pOut->PrintMsg(label);
				pWind->DrawString(r_GfxInfo.x1 - 10, r_GfxInfo.y1 - 25, label);
				
			}
			else if (d == 13)
				return label;
			else
			{
				label += d;
				pOut->PrintMsg(label);
				pWind->DrawString(r_GfxInfo.x1 - 10, r_GfxInfo.y1 - 25, label);

			}
		}
	
}
Input::~Input()
{
}
