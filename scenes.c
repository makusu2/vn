#include <stdio.h>
#include "head.h"
int getBGC(int sceneNum)
{
	switch (sceneNum)
	{
		case 0: return 0x0000;
		case 1: return 0x0000;
		default: return 0xF000;
	}
}
int getSceneMood(int sceneNum)
{
	//0 neutral, 1 happy, 2 angry, 3 curious, 4 yingyang, 5 content
	switch (sceneNum)
	{
		case 0: return 0;
		case 1: return 2;
		case 2: return 3;
		case 3: return 4;
		case 4: return 3;
		case 5: return 4;
		case 6: return 2;
		case 7: return 3;
		case 8: return 0;
		case 9: return 1;
		case 10: return 0;
		case 11: return 2;
		case 12: return 2;
		case 13: return 0;
		case 14: return 4;
		case 15: return 4;
		case 16: return 0;
		case 17: return 4; //This one should be special
		case 18: return 4;
		case 19: return 5;
		case 20: return 5;
		case 21: return 0;
		case 22: return 2;
		case 23: return 2;
	}
}
char * getDialogue(int sceneNum)
{
	switch (sceneNum)
	{
		case 0: return "Default dialogue";
		case 1: return "GAME OVER";
		case 2: return "Are all humans good?";
		case 3: return "By that logic, Hitler was a good person. Would you agree?";
		case 4: return "Then is any human good?";
		case 5: return "oh. okay. I don't think I want to talk to you anymore.";
		case 6: return "Then you've lied to me. Good-bye.";
		case 7: return "Then someone must be able to choose who is good and who is not. Are you that person?";
		case 8: return "Wow, you're kind of a downer. Bye.";
		case 9: return "Then you are a God. Am I correct?";
		case 10: return "Then is the person themself the person who should judge themself?";
		case 11: return "I'm an athiest. You're lying. Good-bye.";
		case 12: return "Then you have no right to be the only person to judge other people."; //improve this one
		case 13: return "Hitler likely thought he was a good person. Was Hitler a good person?";
		case 14: return "Then is the person to judge them god?";
		case 15: return "Then does God exist?";
		case 16: return "Then no one exists to judge the person. Is that correct?";
		case 17: return "You are implying that information can exist without ever having been created. Is that true?";
		case 18: return "Truly? So there is a god?";
		case 19: return "Then you have enlightened me. Thank you. You may pass.";
		case 20: return "YOU WIN!";
		case 21: return "Then explain who can judge the person.";
		case 22: return "That is not an answer.";
		case 23: return "A lie of omission is still a lie.";
		default: return "Dialogue error";
	}
}
char * getSceneName(int sceneNum)
{
	switch (sceneNum)
	{
		case 0: return "default";
		case 1: return "gameOver";
		case 2: return "firstQuestion";
		case 3: return "hitler";
		case 4: return "anyGood";
		case 5: return "noWantToTalk";
		case 6: return "liar";
		case 7: return "doYouDecide";
		case 8: return "downer";
		case 9: return "areYouGod";
		case 10: return "doTheyJudgeThemselves";
		case 11: return "athiest";
		case 12: return "noRightToJudge";
		case 13: return "theyJudgeThemselves";
		case 14: return "doesGodJudgeThem";
		case 15: return "doesGodExist";
		case 16: return "noOneJudges";
		case 17: return "informationExistance";
		case 18: return "soThereIsAGod";
		case 19: return "enlightened";
		case 20: return "victory";
		case 21: return "yesNo1";
		case 22: return "yesNo2";
		case 23: return "yesNo3";
		default: return "Scene name error";
	}
}
int getNextScene(int sceneNum, int yes)
{
	switch (sceneNum)
	{
		case 0: return 1;
		case 1: return 2;
		case 2: return (yes)?3:4;
		case 3: return (yes)?5:6;
		case 4: return (yes)?7:8;
		case 5: return 1;
		case 6: return 1;
		case 7: return (yes)?9:10;
		case 8: return 1;
		case 9: return (yes)?11:12;
		case 10: return (yes)?13:14;
		case 11: return 1;
		case 12: return 1;
		case 13: return (yes)?5:6;
		case 14: return (yes)?15:16;
		case 15: return (yes)?11:16;
		case 16: return (yes)?17:21;
		case 17: return (yes)?6:19;
		case 18: return (yes)?6:19;
		case 19: return 20;
		case 20: return 2;
		case 21: return 22;
		case 22: return 23;
		case 23: return 6;
	}
}