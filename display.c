#include "address_map_nios2.h"

#include "head.h"
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


void drawEntityBox()
{
	int startRow = 5;
	int endRow = sHeight-55;
	int startCol = generalStartCol;
	int endCol = generalEndCol;
	colorArea(startRow,endRow,startCol,endCol,green);
}
void drawEntity(int mood)
{
	//Note: Center row is 75, center col is 150
	drawEntityBox();
	switch (mood)
	{
		case 0: //neutral
			return;
		case 1: //happy
			//draw happy face
			colorArea(20,130,80,190,white);//use yellow later
			colorArea(30,40,110,120,blue);
			colorArea(30,40,150,160,blue);
			colorLine(90,110,100,100,red);
			colorLine(110,110,100,170,red);
			colorLine(90,110,170,170,red);
			return;
		case 2: //angry
			//draw red X
			colorLine(20,130,100,200,red);
			colorLine(130,20,100,200,red);
			return;
		case 3: //curious
			//draw question mark
			//r[
			colorArea(30,50,120,130,white);
			colorArea(15,30,130,160,white);
			colorArea(30,90,160,170,white);
			colorArea(90,100,140,165,white);
			colorArea(100,120,140,150,white);
			colorArea(125,135,140,150,white);
			return;
		case 4: //right and wrong
			//draw yingyang
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
void drawDialogueBox()
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