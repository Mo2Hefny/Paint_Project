#include "GUI\Input.h"
#include "GUI\Output.h"
#include<string>;
//This is a test code to test the Input and Output classes

int main()
{
	int x, y;

	//Create Input and Output objects to test
	Output* pOut = new Output();
	Input* pIn = pOut->CreateInput();

	//Starting the test
	pOut->PrintMessage("This demo is to test input and output classes, Click anywhere to start the test");
	pIn->GetPointClicked(x, y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:	
	//			Create The FULL Tool bar, the drawing area and the status bar	
	//			This has already been done through the constrcutor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST1: Drawing Tool bar and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	
	//			Drawing all the Figures with all possible states: 
	//			Non-filled, Filled, and highlighted in both cases			
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST2: Now we will show that Output class can draw any figure in any state, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	GfxInfo gfxInfo;//to be used with draw function of the class Ouput
	Point P1, P2;

	/// 2.1- Rectangle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Rectangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	// 2.1.1 - Drawing non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> non-filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawRect(P1, P2, gfxInfo, false);
	// 2.1.2 - Drawing highlighted non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawRect(P1, P2, gfxInfo, true);
	// 2.1.3 - Drawing a filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = GREEN;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->DrawRect(P1, P2, gfxInfo, false);
	// 2.1.4 - Drawing a highlighted filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawRect(P1, P2, gfxInfo, true);
	pOut->PrintMessage("Drawing a Rectangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.2- Square Test ///
	/// ============== 
	pOut->PrintMessage("Drawing a Square, filled/unfilled and Highlighted filled/unfilled, Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	/* 2.2.1 - Drawing non - filled square */
	pOut->PrintMessage("Drawing a Square ==> non-filled, Click the center of the square");
	pIn->GetPointClicked(P1.x, P1.y);
	gfxInfo.isFilled = false;
	pOut->DrawSquare(P1, gfxInfo, false);
	/* 2.2.2 - Drawing highlighted non - filled square */
	pOut->PrintMessage("Drawing a Square ==> Highlighted unfilled, Click to highlight");
	pIn->GetPointClicked(x, y);
	pOut->DrawSquare(P1, gfxInfo, true);
	/* 2.2.3 - Drawing a filled square */
	pOut->PrintMessage("Drawing a Square==> filled,click the center of the square");
	pIn->GetPointClicked(P1.x, P1.y);
	gfxInfo.isFilled = true;
	pOut->DrawSquare(P1, gfxInfo, false);
	/* 2.2.4 - Drawing a highlighted filled square */
	pOut->PrintMessage("Drawing a Square ==> filled highlighted,click to highlight");
	pIn->GetPointClicked(x, y);
	pOut->DrawSquare(P1, gfxInfo, true);
	///TODO: Add code to draw Square, Normal and Highlighted
	pOut->PrintMessage("Drawing a Square Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.3- Triangle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Triangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	Point P3;
	/* 2.3.1 - Drawing non - filled triangle */
	pOut->PrintMessage("Drawing a Triangle==>non filled, click the 3 vertices");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->GetPointClicked(P3.x, P3.y);
	gfxInfo.isFilled = false;
	pOut->DrawTriangle(P1, P2, P3, gfxInfo, false);
	/* 2.3.2 - Drawing highlighted non - filled triangle */
	pOut->PrintMessage("Drawing a Triangle==>non filled highlighted, click to highlight");
	pIn->GetPointClicked(x, y);
	pOut->DrawTriangle(P1, P2, P3, gfxInfo, true);
	/* 2.3.3 - Drawing a filled triangle */
	pOut->PrintMessage("Drawing a Triangle==>filled,click the 3 vertices");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->GetPointClicked(P3.x, P3.y);
	gfxInfo.isFilled = true;
	pOut->DrawTriangle(P1, P2, P3, gfxInfo, false);
	/* 2.3.4 - Drawing a highlighted filled triangle */
	pOut->PrintMessage("Drawing a Triangle==> filled highlighted, click to highlight");
	pIn->GetPointClicked(x, y);
	pOut->DrawTriangle(P1, P2, P3, gfxInfo, true);
	///TODO: Add code to draw Triangle in all possible states
	pOut->PrintMessage("Drawing a Triangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.4- Hexagon Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Hexagon, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(P1.x, P1.y);	//Wait for any click
	///TODO: Add code to draw Hexagon in all possible states
	/* 2.4.1 - Drawing non - filled Hexagon */
	pOut->PrintMessage("Drawing a Hexagon Test ==> non-filled,  Click the center of the hexagon");
	pIn->GetPointClicked(P2.x, P2.y);
	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawHex(P2, gfxInfo, false);
	/* 2.4.2 - Drawing highlighted non - filled hexagon */
	pOut->PrintMessage("Drawing a Hexagon ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawHex(P2, gfxInfo, true);
	/* 2.4.3 - Drawing a filled hexagon */
	pOut->PrintMessage("Drawing a Hexagon ==> filled,  Click the center of the hexagon");
	pIn->GetPointClicked(P1.x, P1.y);
	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = GREEN;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->DrawHex(P1, gfxInfo, false);
	/* 2.4.4 - Drawing a highlighted filled hexagon */
	pOut->PrintMessage("Drawing a Hexagon ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawHex(P1, gfxInfo, true);
	pOut->PrintMessage("Drawing a Hexagon Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.5- Circle Test ///
	/// =================== 
	
	pOut->PrintMessage("Drawing an Circle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click


	pOut->PrintMessage("Drawing a Cricle==>non filled, click the center & a point");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	gfxInfo.isFilled = false;
	pOut->DrawCircle(P1, P2, gfxInfo, false);
	pOut->PrintMessage("Drawing a Circle==>non filled highlighted, click to highlight");
	pIn->GetPointClicked(x, y);
	pOut->DrawCircle(P1, P2, gfxInfo, true);
	pOut->PrintMessage("Drawing a Circle==>filled,click the center & a point");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);

	gfxInfo.isFilled = true;
	pOut->DrawCircle(P1, P2, gfxInfo, false);
	pOut->PrintMessage("Drawing a Circle==> filled highlighted, click to highlight");
	pIn->GetPointClicked(x, y);
	pOut->DrawCircle(P1, P2, gfxInfo, true);
	///TODO: Add code to draw Circle in all possible states

	pOut->PrintMessage("Drawing a Circle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: 
	//			Input Class: Read strings from the user
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST3: Now Time to test class Input, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->PrintMessage("Testing input ability to read strings");
	///TODO: Add code here to 
	// 1- Read a string from the user on the status bar
	// 2- After reading the string clear the status bar
	// 3- print on the status bar "You Entered" then print the string
	string str = pIn->GetSrting(pOut);
	pOut->PrintMessage("You entered " + str + " ,click any where to continue");
	pIn->GetPointClicked(x, y);

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4: 
	//			Input Class : Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST4: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;

	///TODO:  
	//You must add a case for each action (both Draw mode and Play mode actions)
	//Add cases for the missing actions below
	do
	{
		ActType = pIn->GetUserAction();

		switch (ActType)
		{
		case DRAW_SHAPE:
			pOut->PrintMessage("Action: Select a shape to draw");
			UI.InterfaceMode = MODE_SHAPE;
			pOut->CreateDrawToolBar();
			break;
		case DRAW_RECT:
			pOut->PrintMessage("Action: Draw a Rectangle , Click anywhere");
			break;
		case DRAW_SQR:
			pOut->PrintMessage("Action: Draw a Square , Click anywhere");
			break;
		case DRAW_TRI:
			pOut->PrintMessage("Action: Draw a Triangle , Click anywhere");
			break;
		case DRAW_CRCL:
			pOut->PrintMessage("Action: Draw a Circle , Click anywhere");
			break;
		case DRAW_HEX:
			pOut->PrintMessage("Action: Draw a Hexagon , Click anywhere");
			break;
		case DRAW_SELECT:
			pOut->PrintMessage("Action: Select object , Click anywhere");
			break;
		case DRAW_FillCol:
			pOut->PrintMessage("Action: Fill object , Select color");
			UI.InterfaceMode = MODE_COL;
			pOut->CreateDrawToolBar();
			break;
		case DRAW_DrawCol:
			pOut->PrintMessage("Action: Draw color , Select color");
			UI.InterfaceMode = MODE_COL;
			pOut->CreateDrawToolBar();
			break;
		case DRAW_BLACK:
			pOut->PrintMessage("Action: Selected color Black , Click anywhere");
			break;
		case DRAW_YELLOW:
			pOut->PrintMessage("Action: Selected color Yellow , Click anywhere");
			break;
		case DRAW_ORANGE:
			pOut->PrintMessage("Action: Selected color Orange , Click anywhere");
			break;
		case DRAW_RED:
			pOut->PrintMessage("Action: Selected color Red , Click anywhere");
			break;
		case DRAW_BLUE:
			pOut->PrintMessage("Action: Selected color Blue , Click anywhere");
			break;
		case DRAW_GREEN:
			pOut->PrintMessage("Action: Selected color Green , Click anywhere");
			break;
		case DRAW_MOVE:
			pOut->PrintMessage("Action: Move object , Click anywhere");
			break;
		case DRAW_DEL:
			pOut->PrintMessage("Action: Delete object , Click anywhere");
			break;
		case DRAW_UNDO:
			pOut->PrintMessage("Action: Undo action , Click anywhere");
			break;
		case DRAW_REDO:
			pOut->PrintMessage("Action: Redo action , Click anywhere");
			break;
		case DRAW_CLEAR:
			pOut->PrintMessage("Action: Clear drawing area , Click anywhere");
			break;
		case DRAW_StartRec:
			pOut->PrintMessage("Action: Start recording , Click anywhere");
			break;
		case DRAW_StopRec:
			pOut->PrintMessage("Action: Stop recording , Click anywhere");
			break;
		case DRAW_PlayRec:
			pOut->PrintMessage("Action: Play last record , Click anywhere");
			break;
		case DRAW_SAVE:
			pOut->PrintMessage("Action: Save file , Click anywhere");
			break;
		case DRAW_LOAD:
			pOut->PrintMessage("Action: Load file , Click anywhere");
			break;
		case PLAY_TYPE:
			pOut->PrintMessage("Action: Select objects of the same type , Click anywhere");
			break;
		case PLAY_FILL:
			pOut->PrintMessage("Action: Select objects of the same color , Click anywhere");
			break;
		case PLAY_TypeFill:
			pOut->PrintMessage("Action: Select objects of the same type and color , Click anywhere");
			break;
		case STATUS:
			pOut->PrintMessage("Action: a click on the Status Bar, Click anywhere");
			break;

		case DRAWING_AREA:
			pOut->PrintMessage("Action: a click on the Drawing Area, Click anywhere");
			break;

		case EMPTY:
			pOut->PrintMessage("Action: a click on empty area in the Design Tool Bar, Click anywhere");
			break;

		case TO_DRAW:
			pOut->PrintMessage("Action: Switch to Draw Mode, creating simualtion tool bar");
			UI.InterfaceMode = MODE_DRAW;
			pOut->CreateDrawToolBar();
			break;

		case TO_PLAY:
			pOut->PrintMessage("Action: Switch to Play Mode, creating Design tool bar");
			pOut->CreatePlayToolBar();
			break;


			///TODO: Add more cases for the other action types


		case EXIT:
			break;
		}
	} while (ActType != EXIT);


	/// Exiting
	pOut->PrintMessage("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(x, y);


	delete pIn;
	delete pOut;
	return 0;
}


