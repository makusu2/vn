void getBGC(int sceneNum);
void getDialogue(int sceneNum);
void getSceneName(int sceneNum);

void getBGC(int sceneNum)
{
	switch (sceneNum)
	{
		case 0:
			return 0x0000;
		
		default:
			return 0xF000;
	}
}
void getDialogue(int sceneNum)
{
	switch (sceneNum)
	{
		case 0:
			return "Default dialogue";
		case 1:
			return "Hi what's up";
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
			return "Wow, you're kind of a downer. Bye."
		case 9:
			return "Then you are a God. Am I correct?";
		case 10:
			return: "Then is the person themself the person who should judge themself?";
		
		default:
			printf("Dialogue error");
	}
}
void getSceneName(int sceneNum)
{
	switch (sceneNum)
	{
		case 0:
			return "default";
		case 1:
			return "first";
		case 2:
			return "testQuestion";
		case 3:
			return "hitler";
		case 4:
			return "anyGood";
		default:
			printf("Scene name error");
	}
}
void getNextScene(int sceneNum, int yes)
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
			if (yes)
			{
				return 0;
			}
			else
			{
				return 0;
			}
		case 2:
			if (yes)
			{
				return 3;
			}
			else:
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
			return 0;
		case
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