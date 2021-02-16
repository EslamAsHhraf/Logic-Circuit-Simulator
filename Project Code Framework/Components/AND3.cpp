#include "AND3.h"

AND3::AND3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	inpp = new pincoor[3];
	inpp[0].x = r_GfxInfo.x1;
	inpp[0].y = r_GfxInfo.y1 + 12;
	inpp[1].x = r_GfxInfo.x1; 
	inpp[1].y = r_GfxInfo.y1 + 25;
	inpp[2].x = r_GfxInfo.x1;
	inpp[2].y = r_GfxInfo.y1 + 50-12;
	outp.x = r_GfxInfo.x2;
	outp.y = r_GfxInfo.y2 - 25;
	inpconn = new bool[3];
	for (int i = 0; i < 3; i++) { inpconn[i] = false; }

}


void AND3::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	int a1,a2,a3;
	a1=GetInputPinStatus(1);
	a2=GetInputPinStatus(2);
	a3=GetInputPinStatus(3);
	if (a1&&a2&&a3)
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);

}


// Function Draw
// Draws 3-input AND gate
void AND3::Draw(Output* pOut, bool select)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawAND3(m_GfxInfo, select);
}

//returns status of outputpin
int AND3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int AND3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void AND3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
////////////////////////////////////////////////////////////////////////////////////////////////////

pincoor AND3::getouppcoor()
{
	return outp;
}

pincoor* AND3::getinppcoor()
{
	return inpp;
}
OutputPin& AND3::getm_outputpin()
{
	return m_OutputPin;
}
////////////////

void AND3::setinpconn(int n, bool valid)
{
	inpconn[n] = valid;
}




bool AND3::freeinpp()
{
	for (int i = 0; i < 3; i++)
	{
		if (inpconn[i] == false)
		{
			inpconn[i] = true;
			
			return true;
		}
	}
	return false;
}

int AND3::getcurrentpin()
{
	for (int i = 0; i < 3; i++)
	{
		if (inpconn[i] == false)
		{

			currentinpp = i;
			break;
		}
	}
	return currentinpp;
}
InputPin* AND3::getm_InpPutpin(int n)
{
	return &m_InputPins[n];
}
void AND3::DoAllConnections()
{
	m_OutputPin.getAllConnection();
}

AND3::AND3(const AND3& C) :Gate(3, AND2_FANOUT)
{
	//currentinpp = 0;
	m_GfxInfo.x1 = C.m_GfxInfo.x1;
	m_GfxInfo.y1 = C.m_GfxInfo.y1;
	m_GfxInfo.x2 = C.m_GfxInfo.x2;
	m_GfxInfo.y2 = C.m_GfxInfo.y2;
	inpp = new pincoor[3];
	inpp[0].x = C.m_GfxInfo.x1;
	inpp[0].y = C.m_GfxInfo.y1 + 12;
	inpp[1].x = C.m_GfxInfo.x1; 
	inpp[1].y = C.m_GfxInfo.y1 + 25;
	inpp[2].x = C.m_GfxInfo.x1;
	inpp[2].y = C.m_GfxInfo.y1 + 50-12;
	outp.x = C.m_GfxInfo.x2;
	outp.y = C.m_GfxInfo.y2 - 25;
	inpconn = new bool[3];
	for (int i = 0; i < 3; i++) { inpconn[i] = false; }

}
AND3::~AND3()
{
	delete[]inpp;
	delete[]inpconn;
	
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
void AND3::Get_String(Input* pIn,Output* pOut)
{
	
	set_string(pIn->GetSrting(pOut,m_GfxInfo));
}

void AND3:: SAVE(ofstream &Infofile,int e)
{
	if(e==0)
	Infofile<<"AND3\t"<<ID<<"\t"<<getLabel()<<"\t"<<(m_GfxInfo.x1)<<"\t"<<(m_GfxInfo.y1)<<"\n";//no tab after"AND2"
}

void AND3:: setID(int id)
{
	ID=id;
}
int AND3:: get_ID()
 {
	 return ID ;
 }
 void AND3::set_string(string t)
 {
	 Component::set_string(t);
 }
string AND3::getLabel()
{
	return (Component::getLabel());
}

void AND3::SetCompCoordinates(GraphicsInfo Coordinate)
{
	m_GfxInfo.x1 = Coordinate.x1;
	m_GfxInfo.y1 = Coordinate.y1;
	m_GfxInfo.x2 = Coordinate.x2;
	m_GfxInfo.y2 = Coordinate.y2;
	
	inpp[0].x = Coordinate.x1;
	inpp[0].y = Coordinate.y1 + 12;
	inpp[1].x = Coordinate.x1;
	inpp[1].y = Coordinate.y1 + 25;
	inpp[2].x = Coordinate.x1;
	inpp[2].y = Coordinate.y1 + 50 -12;
	outp.x = Coordinate.x2;
	outp.y = Coordinate.y2 - 25;
}
void AND3::ComponentLow(Output * POut)
{
	m_OutputPin.setStatus(LOW);
}
