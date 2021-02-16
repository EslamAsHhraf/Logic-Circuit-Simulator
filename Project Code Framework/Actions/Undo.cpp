#include "Undo.h"

UndoAction::UndoAction(ApplicationManager* pApp) :Action(pApp)
{
}

UndoAction::~UndoAction(void)
{
}

void UndoAction::ReadActionParameters()
{
}

void UndoAction::Execute()
{
	pManager->GetLastActionUndo()->Undo();
	pManager->RemoveUndoAct();
}

void UndoAction::Undo()
{
}

void UndoAction::Redo()
{
}
