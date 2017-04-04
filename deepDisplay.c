#include "address_map_nios2.h"

#include "head.h"


void colorArea(int startRow, int endRow, int startCol, int endCol, short color)
{
	for (int currentRow=startRow;currentRow<endRow;currentRow++) //for each row
	{
		for (int currentCol=startCol;currentCol<endCol;currentCol++) //for each column in that row (every pixel)
		{
			drawPixel(currentRow,currentCol,color); //color that pixel with the given color
		}
	}
}

void colorLine(int startRow, int endRow, int startCol, int endCol, short color)
{
	int slopesUp = (startRow>endRow); //This tells if a line will slope up or down
	if (startCol == endCol) //The slope would be infinity, which would not be possible
	{
		int currentRow = startRow;
		int currentCol = startCol;
		while (currentRow<=endRow)
		{
			drawPixel(currentRow,currentCol,color);
			currentRow++;
		}
	}
	else if (startRow == endRow) //the slope would be zero, so nothing would ever change
	{
		int currentRow = startRow;
		int currentCol = startCol;
		while (currentCol<=endCol)
		{
			drawPixel(currentRow,currentCol,color);
			currentCol++;
		}
	}
	else //The line is sloped
	{
		int dRow = endRow-startRow; //The change in row
		int dCol = endCol-startCol; //The change in column
		//if (slopesUp)
		//{
		//	dRow = -dRow;
		//}
		float invSlope = (float)dRow/(float)dCol; //The slope
		int currentRow = startRow;
		int currentCol = startCol;
		//So, we want to at least one pixel on every row/col
		if (invSlope>1)
		{
			float floatCol = (float)currentCol; //Taking a general approximation of the current column
			while (((!slopesUp) & (currentRow<=endRow)) | (slopesUp & (currentRow>=endRow)))
			{
				drawPixel(currentRow,currentCol,color); //Draws a pixel at the most general column
				currentRow++;
				floatCol+=1/invSlope;
				currentCol = (int)floatCol; 
			}
		}
		else
		{
			float floatRow = (float)currentRow;
			while (currentCol<=endCol)
			{
				drawPixel(currentRow,currentCol,color);
				currentCol++;
				floatRow+=invSlope;
				currentRow = (int)floatRow;
			}
		}
	}
}
void drawPixel(int row,int col,short color) //The very general method for deciding the color of a pixel
{
	volatile short * pixel_address = (volatile short *)(0x08000000 + (row<<10)+(col<<1));
	*pixel_address = color;
}
void displayDialogue(char * text_ptr)
{
	clearDialogue(); //removes dialogue already there
	int startRow = 40;//was 30. I think this is unrelated to the pixel thing?
	int startCol = 5;
	int offset = (startRow << 7) + startCol;
  	volatile char * character_buffer = (char *) FPGA_CHAR_BASE;	// VGA character buffer
	int charCounter = 0;
	int readyForNewLine = 0;
	volatile int pauseTime = 300000;
	while ( *(text_ptr) ) //while there is still dialogue left in the array
	{
		pause(pauseTime);
		*(character_buffer + offset) = *(text_ptr);	// write to the character buffer
		++text_ptr;
		++offset;
		++charCounter;
		//updating all values
		if ((charCounter == 50) || (charCounter == 100)) //This tells that the dialogue is almost off-screen
		{
			readyForNewLine = 1;
		}
		int charIsSpace = 0;
		if ((char)*(text_ptr) == ' ')
		{
			charIsSpace = 1; //Tells if the current char is just a space
		}
		if (charIsSpace && readyForNewLine) //If the current char is space and the next line should be used, change rows
		{
			int rowDiff = (charCounter/50);
			offset = ((startRow+rowDiff)<<7)+startCol;
			readyForNewLine=0;
			/*if (charCounter>100)
			{
				offset = ((startRow+2)<<7)+startCol;
				readyForNewLine = 0;
			}
			else if (charCounter>50)
			{
				offset = ((startRow+1)<<7)+startCol;//tbh dunno what I'm doing here
				readyForNewLine = 0;
			}*/
		}
	}
}
void clearDialogue() //Removes all current dialogue
{
	int startRow = 40;
	int startCol = 5;
  	volatile char * character_buffer = (char *) FPGA_CHAR_BASE;	// VGA character buffer
	for (int startRow=40;startRow<45;startRow++)
	{
		int offset = (startRow << 7) + startCol;
		for (int i=0;i<100;i++)
		{
			*(character_buffer + offset) = ' ';	// write to the character buffer
			++offset;
		}
	}
}