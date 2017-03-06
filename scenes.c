void getBGC(int sceneNum);
void getDialogue(int sceneNum);
void getSceneName(int sceneNum);

void getBGC(int sceneNum)
{
	switch (sceneNum)
	{
		case 0:
			return 0x0000;
		case 1:
			return 0xF000;
		default:
			printf("BGC ERROR");
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
		default:
			printf("Scene name error");
	}
}