#include "RedoAction.h"

RedoAction::RedoAction(ApplicationManager* pApp) : Action(pApp)
{
	
		current = 0;
		for (int i = 0; i < 5; i++)
		{
			ptrs_act[i] = -1;
			arr[i] = NULL;
		}
	
}

void RedoAction::Execute()
{

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
			for (int i = 1; i < 4; i++)
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

void RedoAction::clear()
{
	for (int i = 0; i < 5; i++)
	{
		ptrs_act[i] = -1;
		arr[i] = NULL;
	}
	current = 0;
}
