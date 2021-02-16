#include "NOR2.h"

NOR2::NOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
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


void NOR2::Operate()
{
	
	int a1,a2;
	a1=GetInputPinStatus(1);
	a2=GetInputPinStatus(2);
	if (!(a1||a2))
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);

}


// Function Draw
// Draws 2-input NOR gate
void NOR2::Draw(Output* pOut, bool select)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNOR2(m_GfxInfo, select);
}

//returns status of outputpin
int NOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
////////////////////////////////////////////////////////////////////////////////////////////////////

pincoor NOR2::getouppcoor()
{
	return outp;
}

pincoor* NOR2::getinppcoor()
{
	return inpp;
}
OutputPin& NOR2::getm_outputpin()
{
	return m_OutputPin;
}
////////////////

void NOR2::setinpconn(int n, bool valid)
{
	inpconn[n] = valid;
}




bool NOR2::freeinpp()
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

int NOR2::getcurrentpin()
{
	for (int i = 0; i < 2; i++)
	{
		if (inpconn[i] == false)
		{
			currentinpp=i;
			 break;
		}
	}
	return currentinpp;
}
InputPin* NOR2::getm_InpPutpin(int n)
{
	return &m_InputPins[n];
}
void NOR2::DoAllConnections()
{
	m_OutputPin.getAllConnection();
}

NOR2::NOR2(const NOR2& C) :Gate(2, AND2_FANOUT)
{
	//currentinpp = 0;
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
NOR2::~NOR2()
{
	delete[]inpp;
	delete[]inpconn;
	
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
void NOR2::Get_String(Input* pIn,Output* pOut)
{
	
	set_string(pIn->GetSrting(pOut,m_GfxInfo));
}

void NOR2:: SAVE(ofstream &Infofile,int e)
{
	if(e==0)
	Infofile<<"NOR2\t"<<ID<<"\t"<<getLabel()<<"\t"<<(m_GfxInfo.x1)<<"\t"<<(m_GfxInfo.y1)<<"\n";//no tab after"AND2"
}

void NOR2:: setID(int id)
{
	ID=id;
}
int NOR2:: get_ID()
 {
	 return ID ;
 }
 void NOR2::set_string(string t)
 {
	 Component::set_string(t);
 }
string NOR2::getLabel()
{
	return (Component::getLabel());
}
void NOR2::ComponentLow(Output * POut)
{
	m_OutputPin.setStatus(LOW);
}
