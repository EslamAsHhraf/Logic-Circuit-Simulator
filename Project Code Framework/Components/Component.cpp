#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;	
}

GraphicsInfo Component::GetCompCoordinates()
{
	return m_GfxInfo;
}

void Component::SetCompCoordinates(GraphicsInfo Coordinate)
{
	m_GfxInfo = Coordinate;
}

void Component::ClearComp(Output* pOut)
{
	pOut->ClearComponent(m_GfxInfo);
}

pincoor* Component::getinppcoor()
{
	return nullptr;
}

pincoor Component::getouppcoor()
{
	return pincoor();
}

bool Component::freeinpp()
{
	return false;
}

int Component::getcurrentpin()
{
	return 0;
}

void Component::setinpconn(int n, bool validation)
{

}

int Component::get_intm_Inputs()
{
	return 0;
}

OutputPin& Component::getm_outputpin()
{
	return OutputPin();
}

InputPin* Component::getm_InpPutpin(int n)
{
	return nullptr;
	
}

void Component::DoAllConnections()
{

}
void Component::convert()
{
}

Component::Component()
{}

Component::~Component()
{}

void Component:: set_string(string t)//samaa
{
	m_Label= t;
}
string Component::getLabel()//samaa
 {
	 return m_Label;
 }

int Component::GetDstPinnumber()
{
	return -1;
}

void Component::SetINDX(int id)
{
	UI.Counter--;
	INDEX = id;
}
