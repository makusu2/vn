#include "address_map_nios2.h"
#include <time.h>
#include <stdlib.h>
#include "head.h"
#include <stdio.h>
int sWidth=300;//319. Width is columns. Cols go left to right.
int sHeight=200;//239. Height is rows. Rows go up to down.
int sTrueWidth=320;
int sTrueHeight=240;
int generalStartCol = 5;
int generalEndCol = 295;//sWidth-5
short black = 0x0000;
short pink = 0xF00F;
short green = 0x0FF0;
short blue = 0x00FF;
short red = 0xF000;
short white = 0xFFFF;
//The colors represent the values which the VGI connector will use to display color

void drawEntityBox()
{
	int startRow = 5; //Where the entity's start row is
	int endRow = sHeight-55; //Where the entity's end row is
	int startCol = generalStartCol; //Where the entity's start column is
	int endCol = generalEndCol; //Where the entity's end column is
	colorArea(startRow,endRow,startCol,endCol,green); //Color the area that will hold the entity
}
void drawEntity(int mood)
{
	//Note: Center row is 75, center col is 150
	drawEntityBox();
	int colors[6] = {black,pink,green,blue,red,white};
	switch (mood)
	{
		case 0: //neutral
			//draw interesting lines
			colorLine(38,38,40,110,white);
			colorLine(43,43,190,260,white);
			colorLine(70,70,60,190,white);
			colorLine(100,100,200,290,white);
			colorLine(130,130,45,125,white);
			return;
		case 1: //happy
			//draw happy face
			//No, draw interesting
			//First do the weird thing
			for (int col=generalStartCol;col<generalEndCol;col++)
			{
				for (int row=5;row<sHeight-55;row++)
				{
					int index = rand()%7;
					int randColor = colors[index];
					drawPixel(row,col,randColor);
				}
			}
			srand(time(NULL)); 
			int randIndex = rand()%7;
			
			
			
			colorArea(30,130,190,300,black);
			colorArea(40,120,180,290,white);
			colorArea(50,110,170,280,red);
			colorArea(60,100,160,270,blue);
			colorArea(70,90,150,260,green);
			colorArea(75,85,140,250,pink);
			//colorArea(20,130,80,190,white);//use yellow later
			//colorArea(30,40,110,120,blue);
			//colorArea(30,40,150,160,blue);
			//colorLine(90,110,100,100,red);
			//colorLine(110,110,100,170,red);
			//colorLine(90,110,170,170,red);
			return;
		case 2: //angry
			//draw red X
			colorLine(20,130,100,200,red);
			colorLine(130,20,100,200,red);
			return;
		case 3: //curious
			//draw question mark
			colorArea(30,50,120,130,white);
			colorArea(15,30,130,160,white);
			colorArea(30,90,160,170,white);
			colorArea(90,100,140,165,white);
			colorArea(100,120,140,150,white);
			colorArea(125,135,140,150,white);
			return;
		case 4: //right and wrong
			//draw yingyang
			//cols 80 to 200
			//rows 10 to 130, so minibox size of 60
			//140 in middle, so white goes from 80 to 110
			colorArea(10,130,80,110,white);
			colorArea(10,130,170,200,black);
			colorArea(10,70,110,170,white);
			colorArea(70,130,110,170,black);
			colorArea(25,55,125,155,black);
			colorArea(85,115,125,155,white);
			return;
		case 5: //content, probably for successes
			//draw peace symbol
			colorLine(20,70,100,150,blue);
			colorLine(70,20,150,200,blue);
			colorLine(70,110,150,150,blue);
			return;
		default:
			return;
	}
}
void drawDialogueBox() //Draws a colored box to prepare for dialogue
{
	short color = pink; //Can change
	int startRow=sHeight-50;//150
	int endRow=sHeight-10;//190
	int startCol=5;
	int endCol=sWidth-5;
	colorArea(startRow,endRow,startCol,endCol,color);
}



void colorScreen(short color)
{
	colorArea(0,sHeight,0,sWidth,color);
}
void clearScreen()
{
	colorArea(0,sTrueHeight,0,sTrueWidth,0x0000);
}
int wobble()
{
	int charStartRow = 40;
	int charStartCol = 5;
	volatile char * character_buffer = (char *) FPGA_CHAR_BASE;	// VGA character buffer
	//int origOffset = (charStartRow << 7) + charStartCol;
	//volatile char * origCharacter_buffer = (char *) FPGA_CHAR_BASE;	// VGA character buffer
	int originalChar[46][56] = {};
	for (int row=charStartRow;row<charStartRow+5;row++)
	{
		for (int col=charStartCol;col<charStartCol+51;col++)
		{
			int origOffset = (row << 7) + col;
			//++origOffset;
			//printf("Val: %d\n",*(character_buffer + origOffset));
			originalChar[row][col] = *(character_buffer + origOffset);
			//printf("originalChar: %d\n",originalChar[row][col]);
		}
	}
	while (1) //This is new
	{
		int startRow = 5; //Where the entity's start row is
		int endRow = sHeight-55; //Where the entity's end row is
		int startCol = generalStartCol; //Where the entity's start column is
		int endCol = generalEndCol; //Where the entity's end column is
		//printf("First");
		volatile int * buttonPtr = (int *) KEY_BASE; //getting ready for the button press
		for (int i=0;i<10;i++)
		{
			int col = rand()%(endCol-startCol);
			int row = rand()%(endRow-startRow);
			int rowDif = (rand()%2)-(rand()%2);
			int colDif = (rand()%2)-(rand()%2);
			
			short colorAbove = getPixel(row+rowDif,col+colDif);
			drawPixel(row,col,colorAbove);
			
			
			switch (*buttonPtr) //this looks at the value currently being pressed
			{
				case 8: return 8; //If the user is pressing button 3, return "yes" as a value
				case 4: return 4; //If the user is pressing button 2, return "no" as a value
				case 1: return 1;
				default: continue; //If the user is not pressing anything, simply run the loop again
			}
			
		}
		
		
		
		//int charStartRow = 40;//was 30. I think this is unrelated to the pixel thing?
		//int charStartCol = 5;
		//int charInt = *(character_buffer + offset);
		for (int row=charStartRow;row<charStartRow+4;row++)
		{
			for (int col=charStartCol;col<charStartCol+50;col++)
			{
				int offset = (row << 7) + col;
				
				//++offset;
				int dontDoIt = rand()%10;
				if (dontDoIt || (*(character_buffer + offset) == ' '))
				{
					continue;
				}
				int toOrig = rand()%100;
				if (toOrig)
				{
					*(character_buffer + offset) = originalChar[row][col];
				}
				else
				{
					*(character_buffer + offset) = (rand()%123)+128;
				}
			}
		}
	}
	
	return 0;
}