#pragma once
#include "Action.h"
#include"../Components/Connection.h"

class AddConnection :    public Action
{
    GraphicsInfo coOr;//the GraphicsInfo of the connection

    int crconn;//the number of pin the connection connected to
public:
    AddConnection(ApplicationManager* pApp);
    virtual ~AddConnection(void); 
    void ReadActionParameters();
    virtual void Execute();
    //To undo this action (code depends on action type)
    virtual void Undo() ;
    virtual GraphicsInfo GetCompcoor();
    virtual void SetCompcoor(GraphicsInfo GxInfo);
    virtual void SetDisPinNum(int PinNum);
    //To redo this action (code depends on action type)
    virtual void Redo() ;
   
    
};

