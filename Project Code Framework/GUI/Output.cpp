#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = WHITE;

	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	ChangeTitle("Programming Techniques Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar

}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
bool Output::ValidDrawing(GraphicsInfo r_GfxInfo) const
{
	
	if ((r_GfxInfo.y1 > UI.ToolBarHeight && r_GfxInfo.y2 < UI.height-UI.StatusBarHeight))
	{
		
			return true;
		
	}
	return false;
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.height - UI.StatusBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(UI.MsgColor);
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[GATES];
	MenuItemImages[ITM_ADD_GATES] = "images\\16\\images (13) copy1.jpg";
	MenuItemImages[ITM_Switch] = "images\\Menu\\power-flow-through-switches22.jpg";
	MenuItemImages[ITM_Connection] = "images\\Menu\\3.jpg";
	MenuItemImages[ITM_lamp] = "images\\Menu\\ll.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";
	MenuItemImages[ITM_CUT] = "images\\WhatsApp Image 2021-01-11 at 11.41.03 PM.jpeg";
	MenuItemImages[ITM_COPY] = "images\\Menu\\copy.jpg";
	MenuItemImages[ITM_PASTE] = "images\\Menu\\paste.jpg";
	MenuItemImages[ITM_DEL] = "images\\Menu\\WhatsApp Image 2021-01-14 at 3.06.10 PM.jpeg";
	MenuItemImages[ITM_UNDO] = "images\\Menu\\left-turn-arrow-free-vectors-logos-icons-and-photos-undo-redo-icon-11553399854zed898ee35 copy.jpg";
	MenuItemImages[ITM_REDO] = "images\\Menu\\left-turn-arrow-free-vectors-logos-icons-and-photos-undo-redo-icon-11553399854zed898ee35 copy1.jpg";
	MenuItemImages[ITM_SIM_MODE] = "images\\Menu\\simulator.jpg";
		MenuItemImages[ITM_SAVE] = "images\\15\\download copy1.jpg";
	MenuItemImages[ITM_LOAD] = "images\\Menu\\load-icon-vector-20470882.jpg";
	
	MenuItemImages[ITM_LABEL] = "images\\Menu\\depositphotos_63832533-stock-illustration-rename-icon.jpg";
	MenuItemImages[ITM_EDITLABEL] = "images\\Menu\\download (1).jpg";
	MenuItemImages[ITM_EDITCONNECTION] = "images\\Menu\\editconnection-.jpg";
	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < GATES; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItmWidthDsign, 0, UI.ToolItmWidthDsign, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}

void Output::CreateGatesBar() const
{
	UI.IsGatesBarConstructed = true;
	string MenuItemImages[14];
	MenuItemImages[ITM_INV - GATES-1] = "images\\8\\180px-NOT_ANSI_Labelled.svg copy1.jpg";
	MenuItemImages[ITM_AND2 - GATES - 1] = "images\\1\\150px-AND_ANSI.svg copy2.jpg";
	MenuItemImages[ITM_OR2 - GATES - 1] = "images\\13\\389px-OR_ANSI_Labelled.svg copy111 copy.jpg";
	MenuItemImages[ITM_NOR2 - GATES - 1] = "images\\6\\180px-NOR_ANSI_Labelled.svg copy1 copy11.jpg";
	MenuItemImages[ITM_NAND2 - GATES - 1] = "images\\5\\180px-NAND_ANSI_Labelled.svg copy22.jpg";
	MenuItemImages[ITM_XOR2 - GATES - 1] = "images\\11\\180px-XOR_ANSI_Labelled.svg copy111 copy.jpg";
	MenuItemImages[ITM_XNOR2 - GATES - 2] = "images\\9\\180px-XNOR_ANSI_Labelled.svg copy1.jpg";
	MenuItemImages[ITM_BUFFER - GATES - 1] = "images\\3\\180px-Buffer_ANSI_Labelled.svg copy11.jpg";
	MenuItemImages[ITM_AND3 - GATES - 2] = "images\\2\\150px-AND_ANSI.svg copy1 copy2.jpg";
	MenuItemImages[ITM_OR3 - GATES - 2] = "images\\14\\389px-OR_ANSI_Labelled.svg copy11 copy.jpg";
	MenuItemImages[ITM_NOR3 - GATES - 2] = "images\\7\\180px-NOR_ANSI_Labelled.svg copy11 copy.jpg";
	MenuItemImages[ITM_NAND3 - GATES - 2] = "images\\4\\180px-NAND_ANSI_Labelled.svg copy11.jpg";
	MenuItemImages[ITM_XOR3 - GATES - 2] = "images\\12\\180px-XOR_ANSI_Labelled.svg copy11 copy.jpg";
	MenuItemImages[ITM_XNOR3 - GATES - 2] = "images\\10\\180px-XNOR_ANSI_Labelled.svg copy11 copy.jpg";
	string button = "images\\WhatsApp Image 2021-01-12 at 3.52.17 AM.jpeg";
	for (int i = 0; i < 7; i++)
		pWind->DrawImage(MenuItemImages[i], 0, (i + 1) * (5.25 * UI.ToolItemWidth / 6.0), UI.ToolItemWidth, 5 * UI.ToolBarHeight / 6.0);
	for (int i = 7; i < 14; i++)
	{
		pWind->DrawImage(MenuItemImages[i], UI.ToolItemWidth + 8, (i - 6) * (5.25 * UI.ToolItemWidth / 6.0), UI.ToolItemWidth, 5 * UI.ToolBarHeight / 6.0);
	}
	pWind->DrawImage(button, 2 * UI.ToolItemWidth + 4, 3.5 * UI.ToolItemWidth, UI.ToolItemWidth, UI.ToolBarHeight);
	pWind->SetPen(RED, 3);
	//pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

	pWind->DrawLine(UI.ToolBarHeight + 25, UI.ToolBarHeight, UI.ToolBarHeight + 25, UI.height - 50);
	pWind->DrawLine(2 * UI.ToolBarHeight + 55, UI.ToolBarHeight, 2 * UI.ToolBarHeight + 55, UI.height - 50);
}

//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	UI.AppMode = SIMULATION;	//Simulation Mode
	string MenuItemImages[ITM_SIM_CNT];
//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)
	MenuItemImages[ITM_SIM] = "images\\Menu\\Switch_Debounce_1.jpg";
	MenuItemImages[ITM_TRUTH] = "images\\Menu\\unnamed.jpg";
	MenuItemImages[ITM_CIRVALID] = "images\\Menu\\check-cert.jpg";
	MenuItemImages[ITM_CIRPROB] = "images\\Menu\\location.jpg";
	MenuItemImages[ITM_SWITCHTO] = "images\\Menu\\design-icon.jpg";
MenuItemImages[ITM_EXIT2] = "images\\Menu\\Menu_Exit.jpg";
	for (int i = 0; i < ITM_SIM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.ToolItmWidthDsign, 0, UI.ToolItmWidthDsign, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);


	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)


}

void Output::ClearGatesBar() const
{
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight + 3, 3 * UI.ToolItemWidth + 4, UI.height - UI.StatusBarHeight);
	UI.IsGatesBarConstructed = 0;
}
//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//



//TODO: Add similar functions to draw all components

void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\1\\150px-AND_ANSI.svg copy.jpg";
	else
		GateImage = "Images\\1\\150px-AND_ANSI.jpg";

	
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\13\\389px-OR_ANSI_Labelled.svg copy111.jpg";
	else
		GateImage = "images\\13\\389px-OR_ANSI_Labelled.svg copy.jpg";

	
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawINV(GraphicsInfo r_GfxInfo, bool selected) const
{

	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\8\\180px-NOT_ANSI_Labelled.svg copy11.jpg";
	else
		GateImage = "images\\8\\180px-NOT_ANSI_Labelled.jpg";

	
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawBuff(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\3\\180px-Buffer_ANSI_Labelled.svg copy.jpg";
	else
		GateImage = "images\\3\\180px-Buffer_ANSI_Labelled.svg copy1.jpg";

	
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\6\\180px-NOR_ANSI_Labelled.svg copy1.jpg";
	else
		GateImage = "images\\6\\180px-NOR_ANSI_Labelled.svg copy.jpg";

	
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\5\\180px-NAND_ANSI_Labelled.svg copy222.jpg";
	else
		GateImage = "images\\5\\180px-NAND_ANSI_Labelled.svg copy2.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\9\\180px-XNOR_ANSI_Labelled.svg copy.jpg";
	else
		GateImage = "images\\9\\180px-XNOR_ANSI_Labelled.svg copy11.jpg";

	
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\11\\180px-XOR_ANSI_Labelled.svg copy111.jpg";
	else
		GateImage = "images\\11\\180px-XOR_ANSI_Labelled.svg copy.jpg";

	
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawSWITCH(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "images\\Menu\\SelectLOWswithc.jpg";
	

	
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\2\\150px-AND_ANSI.svg copy11.jpg";
	else
		GateImage = "Images\\2\\150px-AND_ANSI.svg copy1.jpg";

	
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\14\\389px-OR_ANSI_Labelled.svg copy11.jpg";
	else
		GateImage = "images\\14\\389px-OR_ANSI_Labelled.svg copy1.jpg";

	
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\7\\180px-NOR_ANSI_Labelled.svg copy11.jpg";
	else
		GateImage = "images\\7\\180px-NOR_ANSI_Labelled.svg copy111.jpg";

	
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawNAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\4\\180px-NAND_ANSI_Labelled.svg copy.jpg";
	else
		GateImage = "images\\4\\180px-NAND_ANSI_Labelled.svg copy1.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawXNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\10\\180px-XNOR_ANSI_Labelled.svg copy11.jpg";
	else
		GateImage = "images\\10\\180px-XNOR_ANSI_Labelled.svg copy1.jpg";

	
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\12\\180px-XOR_ANSI_Labelled.svg copy11.jpg";
	else
		GateImage = "images\\12\\180px-XOR_ANSI_Labelled.svg copy1.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}



void Output::DrawLAMP(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Menu\\selectLamp.jpg";
	

	
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected) const
{
	if (selected) {
		pWind->SetPen(BLUE, 4);
		pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, (r_GfxInfo.x2 + r_GfxInfo.x1) / 2, r_GfxInfo.y1);
		pWind->DrawLine((r_GfxInfo.x2 + r_GfxInfo.x1) / 2, r_GfxInfo.y1, (r_GfxInfo.x2 + r_GfxInfo.x1) / 2, r_GfxInfo.y2);
		pWind->DrawLine((r_GfxInfo.x2 + r_GfxInfo.x1) / 2, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);
	}
	
	
}

void Output::ClearComponent(GraphicsInfo r_GfxInfo)
{
	
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(r_GfxInfo.x1 - 10, r_GfxInfo.y1 - 23, r_GfxInfo.x2 + 10, r_GfxInfo.y2 + 10);
	
	
}

void Output::ClearConnection(GraphicsInfo r_GfxInfo)
{
	pWind->SetPen(WHITE, 4);
	pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, (r_GfxInfo.x2 + r_GfxInfo.x1) / 2, r_GfxInfo.y1);
	pWind->DrawLine((r_GfxInfo.x2 + r_GfxInfo.x1) / 2, r_GfxInfo.y1, (r_GfxInfo.x2 + r_GfxInfo.x1) / 2, r_GfxInfo.y2);
	pWind->DrawLine((r_GfxInfo.x2 + r_GfxInfo.x1) / 2, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);

	pWind->SetPen(WHITE,1);
	pWind->SetBrush(WHITE);
	r_GfxInfo.x1 = 10 + (r_GfxInfo.x1 + r_GfxInfo.x2) / 2;
	if (r_GfxInfo.y1 >= r_GfxInfo.y2)
	{
		r_GfxInfo.y1 = 25 + r_GfxInfo.y2 - 20;
		pWind->DrawRectangle(r_GfxInfo.x1 - 10, r_GfxInfo.y1, r_GfxInfo.x1 + 30, r_GfxInfo.y1 - 25);
	}
	else
	{
		r_GfxInfo.y1 = 25 + r_GfxInfo.y1 - 20;
		pWind->DrawRectangle(r_GfxInfo.x1-10, r_GfxInfo.y1, r_GfxInfo.x1 + 30, r_GfxInfo.y1 - 25);
	}
	}

void Output::ConvertLamp(GraphicsInfo r_GfxInfo, STATUS s) const
{
	string GateImage;
	if (s == HIGH)	//use image in the highlighted case
		GateImage = "Images\\Menu\\power-flow-through-switches.jpg";
	else
		GateImage = "images\\Menu\\WhatsApp Image 2021-01-14 at 6.01.55 PM.jpeg";

	
	
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void  Output::ConvertSwitch(GraphicsInfo r_GfxInfo, STATUS s) const
{
	string GateImage;
	if (s == HIGH)	//use image in the highlighted case
		GateImage = "Images\\Menu\\HIGH_Switch.jpg";
	else
		GateImage = "images\\Menu\\power-flow-through-switches22.jpg";

	
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);

}
void  Output::CircuitProbing(GraphicsInfo r_GfxInfo, int s) const
{
	string GateImage;
	if (s == 1)	//use image in the highlighted case
		GateImage = "Images\\Menu\\one.jpg";
	else
		GateImage = "images\\Menu\\download.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);

}

void Output::ClearProbing(GraphicsInfo r_GfxInfo) const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2);

}
void  Output::ConvertConnection(GraphicsInfo r_GfxInfo, STATUS s) const
{
	string GateImage;
	if (s == HIGH)	//use image in the highlighted case
	{
		pWind->SetPen(SEAGREEN, 4);
		pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, (r_GfxInfo.x2 + r_GfxInfo.x1) / 2, r_GfxInfo.y1);
		pWind->DrawLine((r_GfxInfo.x2 + r_GfxInfo.x1) / 2, r_GfxInfo.y1, (r_GfxInfo.x2 + r_GfxInfo.x1) / 2, r_GfxInfo.y2);
		pWind->DrawLine((r_GfxInfo.x2 + r_GfxInfo.x1) / 2, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);
	}
	else
	{
		pWind->SetPen(BLACK, 4);
		pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, (r_GfxInfo.x2 + r_GfxInfo.x1) / 2, r_GfxInfo.y1);
		pWind->DrawLine((r_GfxInfo.x2 + r_GfxInfo.x1) / 2, r_GfxInfo.y1, (r_GfxInfo.x2 + r_GfxInfo.x1) / 2, r_GfxInfo.y2);
		pWind->DrawLine((r_GfxInfo.x2 + r_GfxInfo.x1) / 2, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);
	}

}
void Output::Clearbar() const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}

Output::~Output()
{
	delete pWind;
}
