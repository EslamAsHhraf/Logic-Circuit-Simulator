#pragma once

#include <sstream>
#include"Actions\Action.h"
#include <iostream>
#include "Components\AND2.h"
#include"Components\AND3.h"
#include"Components\Buff.h"
#include"Components\Component.h"
#include"Components\INV.h"
#include"Components\LAMP.h"
#include"Components\NAND2.h"
#include"Components\NAND3.h"
#include"Components\NOR2.h"
#include"Components\NOR3.h"
#include"Components\OR2.h"
#include"Components\OR3.h"
#include"Components\SWITCH.h"
#include"Components\XNOR2.h"
#include"Components\XNOR3.h"
#include"Components\XOR2.h"
#include"Components\XOR3.h"

#include"Defs.H"
#include <fstream>
#include<cstring>
using namespace std;
#include"ApplicationManager.h"
#include"Components\Connection.h"

class load :public Action
{
public:
	load(ApplicationManager *pApp);
	virtual ~load(void);

	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();



};

