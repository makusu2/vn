#include "address_map_nios2.h"
#include <stdio.h>
#include <math.h>
#include <display.c>
#include <scenes.c>
int getChoice(int maxVal);
void showScene(int nextSceneVal);

int main(void)
{
	//So, we can put variables here, in main, and use them as "objects"
	int previousSceneVal = 0;//So it doesn't have to redisplay every cycle
	int currentSceneVal = 1;
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
void showScene(int nextSceneVal) //currently, one scene holds one box of dialogue
{
	char text[100] = getDialogue(nextSceneVal);
	int bgc = getBGC(nextSceneVal);
	
	colorScreen(bgc);
	drawDialogueBox();
	displayDialogue(text);
	/*if (nextSceneVal == 1) 
	{
		//volatile int * SW_val = (int *) 0xff200040;
		char text[50] = "Hi what's up";
		colorScreen(0xF000);
		drawDialogueBox();
		displayDialogue(text);
	}*/
}
int getChoice(int maxVal)
{
	//TODO add some way to get the user's choice
	return -1;
}