#include <stdio.h>
void display(int sceneVal);

int main(void)
{
	//So, we can put variables here, in main, and use them as "objects"
	int previousSceneVal = -1;//So it doesn't have to redisplay every cycle
	int currentSceneVal = 0;
	int gameIsOver = 0;//turn to 1 when game finishes, exiting "while" loop
	while(!gameIsOver)
	{
		if (previousSceneVal != currentSceneVal)
		{
			display(currentSceneVal);
			previousSceneVal=currentSceneVal;
		}
		//maybe have a box of options to choose from? With keyboard input, perhaps?
		
	}
}
void display(int sceneVal)
{
	//maybe use file IO and have all the "data" for scenes stored in a folder? Could use a dictionary to turn the sceneVal into the file name.
}
void getChoice(int maxVal)
{
	//TODO add some way to get the user's choice
	return -1
}