#pragma once
#include "Component.h"
#include "OutputPin.h"
#include "InputPin.h"

class SWITCH :	public Component
{
	pincoor outp;
	OutputPin m_OutputPin;
public:
	SWITCH(const GraphicsInfo &r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut, bool select); //for each component to Draw itself
	void convert();	//convert the switch state depend on the stauts of the state
	virtual  pincoor getouppcoor();//return the InPut Pin Coordinates  of the Component
	virtual OutputPin& getm_outputpin();//return the OutPutPin of the Component
	virtual void DoAllConnections(); //go to the outpin of the gate then operate all the connection connect to that gate
	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	int GetInputPinStatus(int n);
	void setInputPinStatus(int n, STATUS s);
	int get_intm_Inputs();
	SWITCH(const SWITCH& C); //copy construcor
	~SWITCH();

	///////////////////////////////////////////////////////////
	virtual void SAVE(ofstream &Infofile,int e);
	
	virtual void setID(int id);
	virtual int get_ID();
	
	virtual void Get_String(Input* pIn,Output* pOut);
	
	virtual void set_string(string t);
	virtual string getLabel();
	void SetCompCoordinates(GraphicsInfo Coordinate);
	
	void ComponentLow(Output * POut);//Make the outpin low when switch to design mode
	
};

