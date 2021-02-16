#pragma once
#include "component.h"
#include "InputPin.h"
#include "OutputPin.h"

class Connection : public Component
{
	Component*	SrcCmpnt;	//Connection source component
	Component*	DstCmpnt;	//Connection Destination component
	int		DstPinnumber;		//The Input pin to which this connection is linked
	OutputPin* SrcPin;	//The Source pin of this connection (an output pin of certain Component)
	InputPin* DstPin;	//The Destination pin of this connection (an input pin of certain Component)
public:
	Connection(const GraphicsInfo &r_GfxInfo, Component *pS=NULL,Component *pD=NULL, int Pin=0);
	~Connection();
	virtual void Operate();	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut, bool select);	//for each component to Draw itself
	

	virtual void ClearComp(Output* pOut);
	void setSourcePin(OutputPin* pSrcPin);
	void setDestPin(InputPin* pDstPin);
	OutputPin* getSourcePin();
	InputPin* getDestPin();
	virtual void set_string(string t);
	virtual string getLabel();
	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual void SAVE(ofstream &Infofile,int e) ;
	virtual void Get_String(Input* pIn,Output* pOut);
	virtual void setID(int id);
	
	virtual int get_ID();
	

	
	Component* GetSrcCmpnt();
	Component* GetDstCmpnt();
	int GetDstPinnumber();
	void ComponentLow(Output * POut);
};
