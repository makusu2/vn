#include <stdio.h>

#include "head.h"

int getBGC(int sceneNum)
{
	switch (sceneNum)
	{
		case 0:
			return 0x0000;
		case 1:
			return 0x0000;
		default:
			return 0xF000;
	}
}
char * getDialogue(int sceneNum)
{
	switch (sceneNum)
	{
		case 0:
			return "Default dialogue";
		case 1:
			return "GAME OVER";
		case 2:
			return "Are all humans good?";
		case 3:
			return "By that logic, Hitler was a good person. Would you agree?";
		case 4:
			return "Then is any human good?";
		case 5:
			return "oh. okay. I don't think I want to talk to you anymore.";
		case 6:
			return "Then you've lied to me. Good-bye.";
		case 7:
			return "Then someone must be able to choose who is good and who is not. Are you that person?";
		case 8:
			return "Wow, you're kind of a downer. Bye.";
		case 9:
			return "Then you are a God. Am I correct?";
		case 10:
			return "Then is the person themself the person who should judge themself?";
		case 11:
			return "I'm an athiest. You're lying. Good-bye.";
		case 12:
			return "Then you have no right to be the only person to judge other people."; //improve this one
		case 13:
			return "Neato, so they judge themselves. Bye.";//improve
		case 14:
			return "Then is the person to judge them god?";
		default:
			printf("Dialogue error");
	}
}
char * getSceneName(int sceneNum)
{
	switch (sceneNum)
	{
		case 0:
			return "default";
		case 1:
			return "gameOver";
		case 2:
			return "testQuestion";
		case 3:
			return "hitler";
		case 4:
			return "anyGood";
		case 5:
			return "noWantToTalk";
		case 6:
			return "liar";
		case 7:
			return "doYouDecide";
		case 8:
			return "downer";
		case 9:
			return "areYouGod";
		case 10:
			return "doTheyJudgeThemselves";
		case 11:
			return "athiest";
		case 12:
			return "noRightToJudge";
		case 13:
			return "theyJudgeThemselves";
		case 14:
			return "doesGodJudgeThem";
		default:
			printf("Scene name error");
	}
}
int getNextScene(int sceneNum, int yes)
{
	switch (sceneNum)
	{
		case 0:
			if (yes)
			{
				return 1;
			}
			else
			{
				return 1;
			}
		case 1:
			return 1;
		case 2:
			if (yes)
			{
				return 3;
			}
			else
			{
				return 4;
			}
		case 3:
			if (yes)
			{
				return 5;
			}
			else
			{
				return 6;
			}
		case 4:
			if (yes)
			{
				return 7;
			}
			else
			{
				return 8;
			}
		case 5:
			return 1;
		case 6:
			return 1;
		case 7:
			if (yes)
			{
				return 9;
			}
			else
			{
				return 10;
			}
		case 8:
			return 1;
		case 9:
			if (yes)
			{
				return 11;
			}
			else
			{
				return 12;
			}
		case 10:
			if (yes)
			{
				return 13;
			}
			else
			{
				return 14;
			}
		case 11:
			return 1;
		case 12:
			return 1;
		case 13:
			return 1;
		case 14:
			return 0;
	}
}
//Include question in dialogue
/*
void getQuestion(int sceneNum)
{
	switch (sceneNum)
	{
		case 0:
			return "Default Scene Question";
		case 1:
			return "Do you respond with not much?";
		case 2:
			return "Answer the question; are all humans good?";
		case 3:
			return "Was he?";
		case 4:
			return "Is any human good?";
		
		default:
			return "Continue?";
	}
}
*/