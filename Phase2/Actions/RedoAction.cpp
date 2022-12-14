#include "RedoAction.h"

RedoAction::RedoAction(ApplicationManager* pApp) : Action(pApp)
{

	current = 0;
	ptr = new Action * [5];
	for (int i = 0; i < 5; i++)
	{
		ptrs_act[i] = -1;
		arr[i] = NULL;
		ptr[i] = NULL;
		indices[i] = -1;
	}

}

void RedoAction::Execute()
{
	ReadActionParameters();
	bool flag = false;
	int index;
	if (current > 0)
	{
		switch (ptrs_act[current - 1])
		{
		case(1):			//adding a figure		//testing: to transfer indices between tools
			for (int i = 4; i >= 0; i--)
			{
				if (!flag)
				{
					if (indices[i] > -1)
					{
						index = indices[i];
						indices[i] = -1;
						flag = true;
					}
				}
			}
			pManager->Fig_Unhide(index);
			pManager->Fig_Undel(index);
			pManager->send_action_undo(ptrs_act[current - 1], NULL);
			this->dec_act();
			break;
		case(2):
			for (int i = 4; i >= 0; i--)
			{
				if (!flag)
				{
					if (ptr[i] != NULL)
					{
						ptr[i]->redo(); //exception handle
						pManager->send_action_undo(0, ptr[i]);
						ptr[i] = NULL;
						flag = true;
					}
				}

			}
			this->dec_act();

			break;
		case(3):			//deletion

			for (int i = 4; i >= 0; i--)
			{
				if (!flag)
				{
					if (arr[i] != NULL)
					{
						arr[i]->Hide(true);
						arr[i]->Delete(true);
						pManager->send_action_undo(ptrs_act[current - 1], NULL);
						pManager->send_fig_undo(arr[i]);
						//pManager->AddFigure(arr[i]);
						arr[i] = NULL;
						flag = true;
					}
				}

			}

			this->dec_act();

			break;
		case(4):	//moving //test:::::
			for (int i = 4; i >= 0; i--)
			{
				if (!flag)
				{
					if (ptr[i] != NULL)
					{
						ptr[i]->redo(); //exception handle
						pManager->send_action_undo(0, ptr[i]);
						ptr[i] = NULL;
						flag = true;
					}
				}

			}
			this->dec_act();

			break;
		}
	}
	if (pManager->get_IsRecording() == true)
		pManager->AddToRecordingList(this);
	Output* p_out = pManager->GetOutput();
	p_out->ClearDrawArea();
	pManager->UpdateInterface();
}

void RedoAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Action: Redo action , Click anywhere");
}


void RedoAction::add_act(int act_type)
{
	if (act_type == 1 || act_type == 2 || act_type == 3 || act_type == 4)
	{
		if (current < 5)
		{
			ptrs_act[current] = act_type;
			current++;
		}
		else
		{
			for (int i = 1; i <= 4; i++)
				ptrs_act[i - 1] = ptrs_act[i];
			ptrs_act[4] = act_type;
		}
	}
}

void RedoAction::dec_act()
{
	ptrs_act[current - 1] = -1;
	current--;
}

void RedoAction::add_fig(CFigure* fig)
{
	bool flag = false;
	for (int i = 0; i < 5; i++)
	{
		if (!flag)
			if (arr[i] == NULL)
			{
				arr[i] = fig;
				flag = true;
			}
	}
	if (!flag)
	{
		for (int i = 1; i <= 4; i++)
			arr[i - 1] = arr[i];
		arr[4] = fig;
	}
}
void RedoAction::add_index(int index)
{
	bool flag = false;
	for (int i = 0; i < 5; i++)
	{
		if (!flag)
			if (indices[i] == -1)
			{
				indices[i] = index;
				flag = true;
			}
	}
	if (!flag)
	{
		for (int i = 1; i <= 4; i++)
			indices[i - 1] = indices[i];
		indices[4] = index;
	}
}
void RedoAction::clear()
{
	for (int i = 0; i < 5; i++)
	{
		ptrs_act[i] = -1;
		arr[i] = NULL;
		ptr[i] = NULL;
	}
	current = 0;
}

void RedoAction::add_action(Action* ptr_act)
{
	if (ptr_act->ActType() == 4 || ptr_act->ActType() == 2)
	{
		bool flag = false;
		for (int i = 0; i < 5; i++)
		{
			if (!flag)
				if (ptr[i] == NULL)
				{
					ptr[i] = ptr_act;
					ptr_act = NULL;
					flag = true;
				}
		}
		if (!flag)
		{
			for (int i = 1; i <= 4; i++)
				ptr[i - 1] = ptr[i];
			ptr[4] = ptr_act;
		}
	}
}

void RedoAction::play()
{
	Execute();
}

RedoAction::~RedoAction()
{
	delete[] ptr;
}
