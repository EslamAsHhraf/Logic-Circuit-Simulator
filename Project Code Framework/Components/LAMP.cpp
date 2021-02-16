#include "LAMP.h"
#include "Component.h"
LAMP::LAMP(const GraphicsInfo &r_GfxInfo, int r_FanOut) 
{
	currentinpp = 0;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	inpp.x = m_GfxInfo.x1;
	inpp.y= m_GfxInfo.y2-25;
	inpconn = false;
	
	
}
void LAMP::Operate()
{
}
void LAMP::Draw(Output* pOut, bool select) {
	if (select == false)
	{
		if (GetInputPinStatus(0) == LOW)
		{

			pOut->ConvertLamp(m_GfxInfo, LOW);
		}
		else
		{

			pOut->ConvertLamp(m_GfxInfo, HIGH);
		}
	}
	else
	pOut->DrawLAMP(m_GfxInfo, true);

}

int LAMP::GetOutPinStatus() 
{
	return -1;

 }
int LAMP::GetInputPinStatus(int n) {
	return m_InputPins.getStatus();
 }

void LAMP::setInputPinStatus(int n, STATUS s) {
	m_InputPins.setStatus(s);
 }
//Calculates the output according to the inputs

pincoor* LAMP::getinppcoor()
{
	return &inpp;
}
////////////////
bool LAMP::freeinpp()
{
	
	for (int i = 0; i < 1; i++)
	{
		if (inpconn == false)
		{
			inpconn = true;
			
			return true;
		}
	}
	return false ;
}
int LAMP::getcurrentpin()
{
	for (int i = 0; i < 1; i++)
	{
		if (inpconn == false)
		{
			currentinpp = i;
			break;
		}
	}
	return currentinpp;
}
InputPin* LAMP::getm_InpPutpin(int n)
{
	return & m_InputPins;
}

void LAMP::DoAllConnections()
{
}
int LAMP::get_intm_Inputs()
{
	return 1;
}
LAMP::LAMP(const LAMP& C)
{
	currentinpp = 0;
	m_GfxInfo.x1 = C.m_GfxInfo.x1;
	m_GfxInfo.y1 = C.m_GfxInfo.y1;
	m_GfxInfo.x2 = C.m_GfxInfo.x2;
	m_GfxInfo.y2 = C.m_GfxInfo.y2;
	inpp.x = m_GfxInfo.x1;
	inpp.y =m_GfxInfo.y2 - 25;
	inpconn = false;
}
LAMP::~LAMP(){ }
/////////////////////////////////////////////////////
void LAMP::Get_String(Input* pIn,Output* pOut)
{
	
	set_string(pIn->GetSrting(pOut,m_GfxInfo));
}

void LAMP:: SAVE(ofstream &Infofile,int e)
{
	if(e==0)
	Infofile<<"LAMP\t"<<ID<<"\t"<<getLabel()<<"\t"<<(m_GfxInfo.x1)<<"\t"<<(m_GfxInfo.y1)<<"\n";
}
void LAMP::setID(int id)
{
	ID=id;
}
int LAMP::get_ID()
 {
	 return ID ;
 }

void LAMP::set_string(string t)
 {
	 Component::set_string(t);
 }
string LAMP::getLabel()
{
	return (Component::getLabel());
}
void LAMP::SetCompCoordinates(GraphicsInfo Coordinate)
{
	m_GfxInfo.x1 = Coordinate.x1;
	m_GfxInfo.y1 = Coordinate.y1;
	m_GfxInfo.x2 = Coordinate.x2;
	m_GfxInfo.y2 = Coordinate.y2;
	inpp.x = Coordinate.x1;
	inpp.y = Coordinate.y2 - 25;
}
void LAMP::setinpconn(int n, bool validation)
{
	inpconn = validation;
}
void LAMP::ComponentLow(Output * pOut)
{
	pOut->ConvertLamp(m_GfxInfo);
}
