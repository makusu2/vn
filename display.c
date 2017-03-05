void drawDialogueBox();
void drawImageBox();
void drawPixel(int row, int col, short color);
void colorArea(int startRow, int endRow, int startCol, int endCol, short color);
void colorScreen(short color);
void clearScreen();
void displayDialogue(char * text_ptr);
void displayChar(int row, int col, char c);
int sWidth=300;//319. Width is columns. Cols go left to right.
int sHeight=200;//239. Height is rows. Rows go up to down.
int sTrueWidth=320;
int sTrueHeight=240;

void drawDialogueBox()
{
	short color = 0xF00F; //Can change
	int startRow=sHeight-50;
	int endRow=sHeight-5;
	int startCol=5;
	int endCol=sWidth-5;
	colorArea(startRow,endRow,startCol,endCol,color);
}

void drawPixel(int row,int col,short color)
{
	volatile short * pixel_address = (volatile short *)(0x08000000 + (row<<10)+(col<<1));
	*pixel_address = color;
}

void colorArea(int startRow, int endRow, int startCol, int endCol, short color)
{
	for (int currentRow=startRow;currentRow<endRow;currentRow++)
	{
		for (int currentCol=startCol;currentCol<endCol;currentCol++)
		{
			drawPixel(currentRow,currentCol,color);
		}
	}
}
void colorScreen(short color)
{
	colorArea(0,sHeight,0,sWidth,color);
}
void clearScreen()
{
	colorArea(0,sTrueHeight,0,sTrueWidth,0x0000);
}
/*void displayDialogue(char * text_ptr)
{
	int startCol=10;
	int startRow=sHeight-55;
	while (*text_ptr)
	{
		drawCharacter(startCol,startRow,*text_ptr);
		startCol++;
		text_ptr++;
	}
}*/
void displayDialogue(char * text_ptr)
{
	int startRow = 30;
	int startCol = 30;
	int offset = (startRow << 7) + startCol;
  	volatile char * character_buffer = (char *) FPGA_CHAR_BASE;	// VGA character buffer

	/* assume that the text string fits on one line */
	//offset = (y << 7) + x;
	while ( *(text_ptr) )
	{
		*(character_buffer + offset) = *(text_ptr);	// write to the character buffer
		++text_ptr;
		++offset;
	}
}
//void displayChar(int row, int col, char c)
//{
//	volatile char * character_buffer = (char *)(0x09000000+(col<<9)+row);
//	*character_buffer=myChar;
//}