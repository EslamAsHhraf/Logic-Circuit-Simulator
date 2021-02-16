#include "Gate.h"

//Gate Constructor
//Parameters:
//r_Inputs: no. of gate's input pins
//r_FanOut: Fan out of the gate's output pin
Gate::Gate(int r_Inputs, int r_FanOut):m_OutputPin(r_FanOut), currentinpp(0)
{
	INDEX = UI.Counter++;
	//Allocate number of input pins (equals r_Inputs)
	m_InputPins = new InputPin[r_Inputs];
	m_Inputs = r_Inputs;	//set no. of inputs of that gate
	
	//Associate all input pins to this gate
	for(int i=0; i<m_Inputs; i++)
		m_InputPins[i].setComponent(this);
}

void Gate::SetCompCoordinates(GraphicsInfo Coordinate)
{
	m_GfxInfo = Coordinate;
	inpp[0].x = m_GfxInfo.x1;
	inpp[0].y = m_GfxInfo.y1 + 15;
	inpp[1].x = m_GfxInfo.x1;
	inpp[1].y = m_GfxInfo.y1 + 50-15;
	outp.x = m_GfxInfo.x2;
	outp.y = m_GfxInfo.y2 - 25;
}
int Gate::get_intm_Inputs()
{
	return m_Inputs;
}
Gate::~Gate()
{
	delete []m_InputPins;
}