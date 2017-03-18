#include "address_map_nios2.h"

#include "head.h"
int sWidth=300;//319. Width is columns. Cols go left to right.
int sHeight=200;//239. Height is rows. Rows go up to down.
int sTrueWidth=320;
int sTrueHeight=240;
int generalStartCol = 5;
int generalEndCol = 295;//sWidth-5
short pink = 0xF00F;
short green = 0x0FF0;
short blue = 0x00FF;
short red = 0xF000;

void drawEntity()
{
	int startRow = 5;
	int endRow = sHeight-55;
	int startCol = generalStartCol;
	int endCol = generalEndCol;
	colorArea(startRow,endRow,startCol,endCol,green);
	
}
void drawDialogueBox()
{
	short color = pink; //Can change
	int startRow=sHeight-50;//150
	int endRow=sHeight-10;//190
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
void displayDialogue(char * text_ptr)
{
	clearDialogue();
	int startRow = 40;//was 30. I think this is unrelated to the pixel thing?
	int startCol = 5;
	int offset = (startRow << 7) + startCol;
  	volatile char * character_buffer = (char *) FPGA_CHAR_BASE;	// VGA character buffer

	while ( *(text_ptr) )
	{
		*(character_buffer + offset) = *(text_ptr);	// write to the character buffer
		++text_ptr;
		++offset;
	}
}
void clearDialogue()
{
	int startRow = 40;
	int startCol = 5;
	int offset = (startRow << 7) + startCol;
  	volatile char * character_buffer = (char *) FPGA_CHAR_BASE;	// VGA character buffer

	for (int i=0;i<100;i++)
	{
		*(character_buffer + offset) = ' ';	// write to the character buffer
		++offset;
	}
	
}