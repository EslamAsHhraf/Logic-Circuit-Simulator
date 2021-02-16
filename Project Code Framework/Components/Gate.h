#ifndef _GATE_H
#define _GATE_H

/*
  Class Gate
  -----------
  - Base class for all types of gates
  - Each gate has n inputs pins and one output pin
*/


#include "InputPin.h"
#include "OutputPin.h"
#include "Component.h"

class Gate:public Component
{
protected:
	pincoor* inpp;
	pincoor outp;
	int currentinpp;
	InputPin* m_InputPins;	//Array of input pins of the Gate
	OutputPin m_OutputPin;	//The Gate output pin
	int m_Inputs;		//No. of input pins of that Gate.
	bool* inpconn;
public:
	Gate(int r_Inputs, int r_FanOut);
	void SetCompCoordinates(GraphicsInfo Coordinate);
	int get_intm_Inputs();
	~Gate();
};

#endif
