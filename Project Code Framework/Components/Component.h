#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\GUI\Output.h"
#include"OutputPin.h"//fathi
#include"InputPin.h"//fathi
#include <fstream>//samaa
using namespace std;//samaa
//Base class for classes Gate, Switch, and LED.
class Component
{
private:
	string m_Label;
protected:
	int ID;//samaa
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
public:
	int INDEX;
	void SetINDX(int id);
	Component(const GraphicsInfo &r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut, bool select) = 0;	//for each component to Draw itself
	
	
	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.
	virtual GraphicsInfo GetCompCoordinates();
	virtual void SetCompCoordinates(GraphicsInfo Coordinate);
	virtual void ClearComp(Output* pOut);
	virtual OutputPin& getm_outputpin();//return the OutPutPin of the Component
	virtual InputPin* getm_InpPutpin(int n);//return the InPutPin of the Component
	virtual pincoor* getinppcoor();//return the InPut Pin Coordinates  of the Component
	virtual pincoor getouppcoor();//return the InPut Pin Coordinates  of the Component
	virtual bool freeinpp();//bool function to see weather there is a free Input Pin (false = free , true = connected)
	virtual int getcurrentpin();//return the index of the free input pin
	virtual void setinpconn(int n, bool validation);//set the bool input pin to false in case of deleting
	virtual	int get_intm_Inputs();
	virtual void DoAllConnections();
	virtual void convert();
	Component();	
	
	//Destructor must be virtual
	virtual ~Component();

	virtual void setID(int id)=0;
	virtual void set_string(string t);
	virtual string getLabel();

	virtual int get_ID()=0;
	virtual void SAVE(ofstream &Infofile,int e) = 0;
	virtual void Get_String(Input* pIn,Output* pOut)=0;
	virtual int GetDstPinnumber();
	virtual void ComponentLow(Output * POut)=0;// make any component low when switch to design mode 
};

#endif
