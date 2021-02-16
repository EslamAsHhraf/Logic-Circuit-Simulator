#pragma once
#include "Component.h"
#include "InputPin.h"
class LAMP :public Component
{
	int currentinpp;
	pincoor inpp;
	InputPin m_InputPins;
	bool inpconn;
public:
	virtual void setinpconn(int n, bool validation);//set the bool input pin to false in case of deleting
	LAMP(const GraphicsInfo &r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut, bool select);	//for each component to Draw itself
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	virtual void setInputPinStatus(int n, STATUS s) ;	//set status of Inputpin # n, to be used by connection class.
	virtual  pincoor* getinppcoor();//return the InPut Pin Coordinates  of the Component
	virtual int getcurrentpin();//return the first free InPut Pin of the Component
	virtual bool freeinpp();//bool function to see weather there is a free Input Pin (false = free , true = connected)
	virtual InputPin* getm_InpPutpin(int n=0);;//return the InPutPin of the Component
	virtual void DoAllConnections();//go to the outpin of the gate then operate all the connection connect to that gate
	int get_intm_Inputs(); //retur number of inputs
	LAMP(const LAMP& C); //copy construcor
	int GetOutPinStatus();

	virtual void SAVE(ofstream &Infofile,int e);
	
	virtual void setID(int id);
	virtual int get_ID();
	virtual void Get_String(Input* pIn,Output* pOut);
	
	virtual void set_string(string t);
	virtual string getLabel();
	void SetCompCoordinates(GraphicsInfo Coordinate);
	
	~LAMP();
	void ComponentLow(Output * pOut);//Make the lamp low when switch to design mode
	
};

