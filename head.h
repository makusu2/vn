void drawDialogueBox();
void drawImageBox();
void drawPixel(int row, int col, short color);
void colorArea(int startRow, int endRow, int startCol, int endCol, short color);
void colorScreen(short color);
void clearScreen();
void displayDialogue(char * text_ptr);
void displayChar(int row, int col, char c);
int getChoice(int maxVal);
int showScene(int nextSceneVal);
int getYesOrNo();
int getBGC(int sceneNum);
char * getDialogue(int sceneNum);
char * getSceneName(int sceneNum);
int getNextScene(int sceneNum, int yes);

void pause(volatile int val);