#include "address_map_nios2.h"
#include <stdio.h>
#include <math.h>
//#include <display.c>
//#include <scenes.c>
#include "head.h"

int main(void)
{
	//So, we can put variables here, in main, and use them as "objects"
	int previousSceneVal = 0;//So it doesn't have to redisplay every cycle
	int currentSceneVal = 2;
	int gameIsOver = 0;//turn to 1 when game finishes, exiting "while" loop
	
	
	
	while(!gameIsOver)
	{
		if (previousSceneVal != currentSceneVal)
		{
			clearScreen();
			showScene(currentSceneVal);
			previousSceneVal=currentSceneVal;
		}
		//maybe have a box of options to choose from? With keyboard input, perhaps?
		
	}
}
int showScene(int nextSceneVal) //currently, one scene holds one box of dialogue
{
	char * text = getDialogue(nextSceneVal);
	int bgc = getBGC(nextSceneVal);
	
	colorScreen(bgc);
	drawDialogueBox();
	displayDialogue(text);
	//displayQuestion(question);//TODO
	return getChoice(1);//Can I return the next scene number instead?
}
int getChoice(int maxVal)
{
	//TODO add some way to get the user's choice
	//should just be yes or no
	return getYesOrNo();//TODO
	
	//return -1;
}
int getYesOrNo()
{
	//press 3 for yes, 2 for no
	volatile int * buttonPtr = (int *) KEY_BASE;
	while (1)
	{
		int buttonVal = *buttonPtr;
		if (buttonVal == 8)
		{
			return 1;
		}
		if (buttonVal == 4)
		{
			return 0;
		}
	}
}