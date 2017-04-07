#include "address_map_nios2.h"
#include <stdio.h>
#include <math.h>
#include "head.h"

volatile int pauseTime = 3000000;//A number which relates to the amount of time the device should allow for before allowing for another key press
int main(void)
{
	//So, we can put variables here, in main, and use them as "objects"
	int previousSceneVal = 0;//So it doesn't have to redisplay every cycle
	int currentSceneVal = 2;
	int gameIsOver = 0;//turn to 1 when game finishes, exiting "while" loop
	while(!gameIsOver) //this will always run
	{
		if (previousSceneVal != currentSceneVal) //if the next scene is the same, just loop again
		{
			clearScreen(); //set all pixels to the same color
			int choice = showScene(currentSceneVal); //this method both updates the screen and returns the user's choice
			previousSceneVal=currentSceneVal; //this method is so that the game recognizes the current scene
			currentSceneVal = getNextScene(previousSceneVal,choice); //This updates the scene based on the user's choice
			volatile int time = 1000000; //This is for a shorter break between button presses
			pause(pauseTime); //This pauses the game for a mostly unnoticeable time, but enough for the user to press and release the button
		}
	}
}
int showScene(int nextSceneVal) //one scene holds one box of dialogue
{
	char * text = getDialogue(nextSceneVal); //this gets the appropriate dialogue
	int bgc = getBGC(nextSceneVal); //This gets the background color
	int mood = getSceneMood(nextSceneVal); //This gets the mood for the scene; the entity image
	
	colorScreen(bgc); //this colors the screen
	drawEntity(mood); //This draws the image of the entity
	drawDialogueBox(); //This draws the dialogue box, in which the dialogue goes
	displayDialogue(text); //This puts the dialogue where it should go
	return getChoice(1); //This returns the user's choice
}
int getChoice(int maxVal)//This is a method that simply holds another method; however, this way, it can be easily changed.
{
	return getYesOrNo();
}
int getYesOrNo() //This is a method for getting two options; yes or no.
{
	//press 3 for yes, 2 for no
	volatile int * buttonPtr = (int *) KEY_BASE; //getting ready for the button press
	while (1) //while the user has yet to do anything
	{
		int possibleChoice = wobble();
		if (possibleChoice != 0)
		{
			
			switch (possibleChoice) //this looks at the value currently being pressed
			{
				case 8: return 1; //If the user is pressing button 3, return "yes" as a value
				case 4: return 0; //If the user is pressing button 2, return "no" as a value
				case 1: return main();
				default: continue; //If the user is not pressing anything, simply run the loop again
			}
		}
		switch (*buttonPtr) //this looks at the value currently being pressed
		{
			case 8: return 1; //If the user is pressing button 3, return "yes" as a value
			case 4: return 0; //If the user is pressing button 2, return "no" as a value
			case 1: return main();
			default: continue; //If the user is not pressing anything, simply run the loop again
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
void pause(volatile int val) //This method only serves to pause the code, to give the user time to lift their finger from the button
{
	for (int i=0;i<val;i++)
	{
		
	}
}