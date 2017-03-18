#include "address_map_nios2.h"
#include <stdio.h>
#include <math.h>
#include "head.h"

volatile int pauseTime = 3000000;
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
			int choice = showScene(currentSceneVal);
			previousSceneVal=currentSceneVal;
			currentSceneVal = getNextScene(previousSceneVal,choice);
			volatile int time = 1000000;
			pause(pauseTime);
		}
	}
}
int showScene(int nextSceneVal) //currently, one scene holds one box of dialogue
{
	char * text = getDialogue(nextSceneVal);
	int bgc = getBGC(nextSceneVal);
	
	colorScreen(bgc);
	drawDialogueBox();
	displayDialogue(text);
	return getChoice(1);
}
int getChoice(int maxVal)
{
	return getYesOrNo();
}
int getYesOrNo()
{
	//press 3 for yes, 2 for no
	volatile int * buttonPtr = (int *) KEY_BASE;
	while (1)
	{
		switch (*buttonPtr)
		{
			case 8: return 1;
			case 4: return 0;
			default: continue;
		}
		/*
		int buttonVal = *buttonPtr;
		if (buttonVal == 8)
		{
			return 1;
		}
		if (buttonVal == 4)
		{
			return 0;
		}
		*/
	}
}
void pause(volatile int val)
{
	for (int i=0;i<val;i++)
	{
		
	}
}