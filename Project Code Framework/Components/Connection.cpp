#include "Connection.h"
	
void Connection::ClearComp(Output* pOut)
{
	pOut->ClearConnection(m_GfxInfo);
}


void Connection::setSourcePin(OutputPin *pSrcPin)
{	SrcPin = pSrcPin;	}

OutputPin* Connection::getSourcePin()
{	return SrcPin;	}


void Connection::setDestPin(InputPin *pDstPin)
{	DstPin = pDstPin;	}

InputPin* Connection::getDestPin()
{	return DstPin;	}



Connection::Connection(const GraphicsInfo& r_GfxInfo, Component* pS, Component* pD, int Pin):Component(r_GfxInfo)
{
	INDEX = UI.Counter++;
	SrcCmpnt = pS;
	DstCmpnt = pD;
	DstPinnumber = Pin;
	this->setSourcePin(&SrcCmpnt->getm_outputpin());
	this->setDestPin(DstCmpnt->getm_InpPutpin(Pin));
}

Connection::~Connection()
{
	DstPin->setStatus(LOW);
	DstCmpnt->setinpconn(DstPinnumber, false);
	SrcPin->Delete_Conn(this);
}

void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus((STATUS)SrcPin->getStatus());
}

void Connection::Draw(Output* pOut, bool select)
{
	if (!select)
	{
		if (GetOutPinStatus() == LOW)
		{

			pOut->ConvertConnection(m_GfxInfo, LOW);
		}
		else
		{

			pOut->ConvertConnection(m_GfxInfo, HIGH);
		}
	}
	else
		pOut->DrawConnection(m_GfxInfo, 1);
}

int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}
//////////////////////////////////////////////////////////

void Connection::set_string(string t)
{
	Component::set_string(t);
}
string Connection::getLabel()
{
	return (Component::getLabel());
}
	void Connection::SAVE(ofstream &Infofile,int e) 
	{
		if(e==1)
			Infofile<<SrcCmpnt->get_ID()<<"\t"<<DstCmpnt->get_ID()<<"\t"<< DstPinnumber <<endl;
	}
	//virtual void LOAD(ifstream &gfile) = 0;	
	void Connection::Get_String(Input* pIn,Output* pOut){ 
		set_string(pIn->GetSrting(pOut, m_GfxInfo));
	}
	void Connection::setID(int id){ }
	int Connection::get_ID() { return  ID; }
//////////////////////////////////////////////////////////////////

	
	Component* Connection::GetSrcCmpnt()
	{
		return SrcCmpnt;
	}

	Component* Connection::GetDstCmpnt()
	{
		return DstCmpnt;
	}

	int Connection::GetDstPinnumber()
	{
		return DstPinnumber;
	}
	void Connection::ComponentLow(Output * POut)
	{
		DstPin->setStatus(LOW);
		POut->ConvertConnection(m_GfxInfo);
	}