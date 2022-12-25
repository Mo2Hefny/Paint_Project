#include "Undo.h"





#include "Undo.h"

void Undo::addAct(Action* act)
{
	if (current < 5)

	{
		ptrs[current] = act->ActType();
		current++;
	}
	else
	{
		for (int i = 1; i < 4; i++)
			ptrs[i - 1] = ptrs[i];
		ptrs[4] = act->ActType();
	}
}

/*void Undo::Execute()
{

	if (current > 0)
	{
		//delete ptrs[current - 1];
		current--;

	}

}*/
int Undo::undo(int x)
{
	
	if (current > 0 && x > 0)
	{
		
		switch (ptrs[current - 1])
		case (1):
		{
			if (current_redo < 5)
			{
				ptrs_redo[current_redo] = ptrs[current];
				current_redo++;
			}
			else
			{
				for (int i = 1; i < 4; i++)
					ptrs_redo[i - 1] = ptrs_redo[i];
				ptrs_redo[4] = ptrs[current];
			}
			x--;
			current--;
		}


	}
	return x;
}
int Undo::redo(int y)
{
	if (current_redo > 0)
	{
		switch (ptrs_redo[current_redo - 1])
		case (1):
		if (current < 5)
		{
			ptrs[current_redo] = ptrs_redo[current];
			current++;
		}
		else
		{
			for (int i = 1; i < 4; i++)
				ptrs[i - 1] = ptrs[i];
			ptrs[4] = ptrs_redo[current_redo];
		}
		y++;
		current_redo--;
	}
	return y;
}
void Undo::clear_redo()
{
	for (int i = 0; i < current_redo; i++)
	{
		ptrs_redo[i] = NULL;
	}
	current_redo = 0;
}
Undo::Undo()
{
	for (int i = 0; i < 5; i++)
	{
		ptrs[i] = NULL;
		ptrs_redo[i] = NULL;
	}
	current = 0;
	current_redo = 0;
}
