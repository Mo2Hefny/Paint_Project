#include "UndoAction.h"


UndoAction::UndoAction(ApplicationManager* pApp) : Action(pApp)
{
	current = 0;
	//test:
	ptr = new Action* [5];
	for (int i = 0; i < 5; i++)
	{
		ptrs_act[i] = -1;
		arr[i] = NULL;
		
		ptr[i] = NULL;
		
	}
	



}

void UndoAction::Execute()
{
	bool flag = false;
	if (current > 0)
	{
		switch (ptrs_act[current - 1])
		{
		case(1):			//adding a figure
			pManager->deleteFig((pManager->get_max_ID_index()));
			this->dec_act();
		case(2):
			//changing color //test:
			for (int i = 0; i < 5; i++)
			{
				if (!flag)
				{
					if (ptr[i] != NULL)
					{
						ptr[i]->undo();
						ptr[i] = NULL;
						flag = true;
					}
				}

			}
			this->dec_act();


			break;
		case(3):			//deletion

			for (int i = 0; i < 5; i++)
			{
				if (!flag)
				{
					if (arr[i] != NULL)
					{
						arr[i]->SetSelected(false);
						pManager->AddFigure(arr[i]);
						arr[i] = NULL;
						flag = true;
					}
				}

			}
			this->dec_act();
			break;
		case(4):	//moving //test:::::
			for (int i = 0; i < 5; i++)
			{
				if (!flag)
				{
					if (ptr[i] != NULL)
					{
						ptr[i]->undo(); //exception handle
						ptr[i] = NULL;
						flag = true;
					}
				}

			}
			this->dec_act();

			break;
		}
	}
	Output* p_out = pManager->GetOutput();
	p_out->ClearDrawArea();
	pManager->UpdateInterface();
}

void UndoAction::add_act(int act_type)
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
			for (int i = 1; i < 4; i++)
				ptrs_act[i - 1] = ptrs_act[i];
			ptrs_act[4] = act_type;
		}
	}
}

void UndoAction::dec_act()
{
	ptrs_act[current - 1] = -1;
	current--;
}

void UndoAction::add_fig(CFigure* fig)
{
	bool flag = false;
	for (int i = 0; i < 5; i++)
	{
		if(!flag)
			if (arr[i] != NULL)
			{
				arr[i] = fig;
				flag = true;
			}
	}
	if (!flag)
	{
		for (int i = 1; i < 4; i++)
			arr[i - 1] = arr[i];
		arr[4] = fig;
	}
}

void UndoAction::clear()
{
	for (int i = 0; i < 5; i++)
	{
		ptrs_act[i] = -1;
		arr[i] = NULL;
	}
	current = 0;
}

int UndoAction::act_type()
{
	if (current > 0)
		return ptrs_act[current - 1];
	else return 0;
}

void UndoAction::add_action(Action* ptr_act)
{
	if (ptr_act->ActType() == 4 || ptr_act->ActType() == 2 || ptr_act->ActType() == 4 || ptr_act->ActType() == 4)
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
			for (int i = 1; i < 4; i++)
				ptr[i - 1] = ptr[i];
			ptr[4] = ptr_act;
		}
	}
}
