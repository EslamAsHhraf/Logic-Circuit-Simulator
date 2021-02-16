#include "AND2.h"

AND2::AND2(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(2, r_FanOut)
{
	
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	inpp = new pincoor[2];
	inpp[0].x = r_GfxInfo.x1;
	inpp[0].y = r_GfxInfo.y1 + 15;
	inpp[1].x = r_GfxInfo.x1; 
	inpp[1].y = r_GfxInfo.y1 + 50-15;
	outp.x = r_GfxInfo.x2;
	outp.y = r_GfxInfo.y2 - 25;
	inpconn = new bool[2];
	for (int i = 0; i < 2; i++) { inpconn[i] = false; }

}


void AND2::Operate()
{
	
	int a1, a2;
	a1 = GetInputPinStatus(1);
	a2 = GetInputPinStatus(2);
	if (a1 && a2)
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);


}


// Function Draw
// Draws 2-input AND gate
void AND2::Draw(Output* pOut, bool select)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawAND2(m_GfxInfo,select);
}

//returns status of outputpin
int AND2::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}

/////////////////////////////////////////////////////////////////////////////////////////////
//returns status of Inputpin #n
int AND2::GetInputPinStatus(int n)	
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void AND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}
////////////////////////////////////////////////////////////////////////////////////////////////////

pincoor AND2::getouppcoor()
{
	return outp;
}

pincoor* AND2::getinppcoor()
{
	return inpp;
}
OutputPin& AND2::getm_outputpin()
{
	return m_OutputPin;
}
////////////////

void AND2::setinpconn(int n, bool valid)
{
	inpconn[n] = valid;
}




bool AND2::freeinpp()
{
	for (int i = 0; i < 2; i++)
	{
		if (inpconn[i] == false)
		{
			inpconn[i] = true;
			
			return true;
		}
	}
	return false;
}

int AND2::getcurrentpin()
{
	for (int i = 0; i < 2; i++)
	{
		if (inpconn[i] == false)
		{

			currentinpp = i;
			break;
		}
	}
	return currentinpp;
}
InputPin* AND2::getm_InpPutpin(int n)
{
	return &m_InputPins[n];
}
void AND2::DoAllConnections()
{
	m_OutputPin.getAllConnection();
}

AND2::AND2(const AND2& C) :Gate(2, AND2_FANOUT)
{
	m_GfxInfo.x1 = C.m_GfxInfo.x1;
	m_GfxInfo.y1 = C.m_GfxInfo.y1;
	m_GfxInfo.x2 = C.m_GfxInfo.x2;
	m_GfxInfo.y2 = C.m_GfxInfo.y2;
	inpp = new pincoor[2];
	inpp[0].x = C.m_GfxInfo.x1;
	inpp[0].y = C.m_GfxInfo.y1 + 15;
	inpp[1].x = C.m_GfxInfo.x1;
	inpp[1].y = C.m_GfxInfo.y1 + 50-15;
	outp.x = C.m_GfxInfo.x2;
	outp.y = C.m_GfxInfo.y2 - 25;
	inpconn = new bool[2];
	for (int i = 0; i < 2; i++) { inpconn[i] = false; }
}
AND2::~AND2()
{
	delete[]inpp;
	delete[]inpconn;
	
}
void AND2::Get_String(Input* pIn,Output* pOut)
{
	
	set_string(pIn->GetSrting(pOut,m_GfxInfo));
	
}
void AND2:: SAVE(ofstream &Infofile,int e)
{
	if(e==0)
	Infofile<<"AND2\t"<<ID<<"\t"<<getLabel()<<"\t"<<(m_GfxInfo.x1)<<"\t"<<(m_GfxInfo.y1)<<"\n";//no tab after"AND2"
}

void AND2:: setID(int id)
{
	ID=id;
}
int AND2:: get_ID()
 {
	 return ID ;
 }

 void AND2::set_string(string t)
 {
	 Component::set_string(t);
 }
string AND2::getLabel()
{
	return (Component::getLabel());
}
void AND2::ComponentLow(Output * POut)
{
	m_OutputPin.setStatus(LOW);
}
