#include "Redo.h"

RedoAction::RedoAction(ApplicationManager* pApp) :Action(pApp)
{
}

RedoAction::~RedoAction(void)
{
}

void RedoAction::ReadActionParameters()
{
}

void RedoAction::Execute()
{
	pManager->GetLastActionRedo()->Redo();
	pManager->RemoveRedoAct();
}

void RedoAction::Undo()
{
}

void RedoAction::Redo()
{
}
