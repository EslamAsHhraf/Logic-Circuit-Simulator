#include "SWITCH.h"
SWITCH::SWITCH(const GraphicsInfo &r_GfxInfo, int r_FanOut) :m_OutputPin(r_FanOut)


{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	outp.x= r_GfxInfo.x2;
	outp.y= r_GfxInfo.y1+25;

}
void SWITCH::Operate()
{
	
}

void SWITCH::Draw(Output* pOut, bool select)
{
	
	if (select == false)
	{
		if (GetOutPinStatus() == LOW)
		{

			pOut->ConvertSwitch(m_GfxInfo, LOW);
		}
		else
		{
			pOut->ConvertSwitch(m_GfxInfo, HIGH);
		}
	}
	else
		pOut->DrawSWITCH(m_GfxInfo, true);
}
int SWITCH::GetOutPinStatus() 
{
	return m_OutputPin.getStatus();
}
SWITCH::SWITCH(const SWITCH& C) :m_OutputPin(AND2_FANOUT)
{
	m_GfxInfo.x1 = C.m_GfxInfo.x1;
	m_GfxInfo.y1 = C.m_GfxInfo.y1;
	m_GfxInfo.x2 = C.m_GfxInfo.x2;
	m_GfxInfo.y2 = C.m_GfxInfo.y2;
	outp.x = C.m_GfxInfo.x2;
	outp.y =C. m_GfxInfo.y1 + 25;
}
int SWITCH::get_intm_Inputs()
{
	return -1;
}
int SWITCH::GetInputPinStatus(int n) 
{
	return -1;
}
void SWITCH::setInputPinStatus(int n, STATUS s) 
{

}
pincoor SWITCH::getouppcoor()
{
	return outp;
}


OutputPin& SWITCH::getm_outputpin()
{
	return m_OutputPin;
}

void SWITCH::convert()
{
	if (GetOutPinStatus() == LOW)
	{
		getm_outputpin().setStatus(HIGH);
		
	}
	else
	{
		getm_outputpin().setStatus(LOW);
	}
}
void SWITCH::DoAllConnections()
{
	m_OutputPin.getAllConnection();
}

SWITCH::~SWITCH(){ }
/////////////////////////////////////////////////////
void SWITCH::Get_String(Input* pIn,Output* pOut)
{
	
	set_string(pIn->GetSrting(pOut,m_GfxInfo));
}

void SWITCH:: SAVE(ofstream &Infofile,int e)
{
	if(e==0)
	Infofile<<"SWITCH\t"<<ID<<"\t"<<SWITCH::getLabel()<<"\t"<<(m_GfxInfo.x1)<<"\t"<<(m_GfxInfo.y1)<<"\n";
}

void SWITCH::setID(int id)
{
	ID=id;
}
int SWITCH::get_ID()
 {
	 return ID ;
 }
void SWITCH::set_string(string t)
 {
	 Component::set_string(t);
 }
string SWITCH::getLabel()
{
	return (Component::getLabel());
}
void SWITCH::SetCompCoordinates(GraphicsInfo Coordinate)
{
	m_GfxInfo.x1 = Coordinate.x1;
	m_GfxInfo.y1 = Coordinate.y1;
	m_GfxInfo.x2 = Coordinate.x2;
	m_GfxInfo.y2 = Coordinate.y2;
	outp.x = Coordinate.x2;
	outp.y = Coordinate.y1 + 25;

}
void SWITCH::ComponentLow(Output * POut)
{
	m_OutputPin.setStatus(LOW);
	POut->ConvertSwitch(m_GfxInfo);
}
