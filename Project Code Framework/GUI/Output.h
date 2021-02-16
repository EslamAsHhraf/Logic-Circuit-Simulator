#pragma once
#include "..\Defs.h"
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Output(); // Performs the Window Initialization
	Input* CreateInput() const; //creates a pointer to the Input object
	void ChangeTitle(string Title) const;
	
	void CreateDesignToolBar() const;	//Tool bar of the design mode
	void CreateGatesBar() const;
	void CreateSimulationToolBar() const;//Tool bar of the simulation mode
	void CreateStatusBar() const;	//Create Status bar

	void ClearStatusBar() const;		//Clears the status bar
	void ClearDrawingArea() const;	//Clears the drawing area
	void ClearGatesBar() const;
	window* CreateWind(int wd, int h, int x, int y) const; //Creates user interface window

	bool ValidDrawing(GraphicsInfo r_GfxInfo) const;
	// Draws 2-input AND gate
	void DrawAND2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawINV(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawBuff(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawNOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawNAND2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawXOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawSWITCH(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawLAMP(GraphicsInfo r_GfxInfo, bool selected = false) const;
	///////////////////
	void DrawAND3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawOR3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawNOR3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawNAND3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawXNOR3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawXOR3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	
	// Draws Connection
	void DrawConnection(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void ClearComponent(GraphicsInfo r_GfxInfo);
	void ClearConnection(GraphicsInfo);//fathi
	void PrintMsg(string msg) const;	//Print a message on Status bar
	
	void ConvertLamp(GraphicsInfo r_GfxInfo, STATUS s = LOW) const;
	void ConvertSwitch(GraphicsInfo r_GfxInfo, STATUS s = LOW) const;
	void  ConvertConnection(GraphicsInfo r_GfxInfo, STATUS s = LOW) const;
	void CircuitProbing(GraphicsInfo r_GfxInfo, int s = 0) const;
	void Clearbar() const;
	void ClearProbing(GraphicsInfo r_GfxInfo) const;
	
	

	~Output();
};
