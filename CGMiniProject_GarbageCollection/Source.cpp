#include<stdlib.h>
#include<gl/glut.h>
#include<string.h>
#include <windows.h>
#include<math.h>
#include<stdio.h>
#define PI 3.141589

int scene = 1;
int xshifter = 0;
bool shift = false;
int x1 = 0, y11 = 0;
int i;
float fuel = 0;
float c = 0, xs = 1350, ys = 60;
int gc1 = 1;
int gw1 = 3;
int gc2 = 1;
int gw2 = 3;
int gc3 = 1;
int gw3 = 3;
int sensor = 0;
int p = 1;
int r = 0, g = 0;
float signal = 0;
float lz = 1;
int sign = 1;

void myInit(){
	glClearColor(0.5, 2.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1350.0, 0.0, 700.0);
}

void output(int s, float x, float y, char *str)
{
	int len;
	glRasterPos2f(x, y);
	len = strlen(str);
	glLineWidth(25.0);
	for (int i = 0; i<len; i++)
	if (s == 2)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
	else if (s == 1)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);
}

void frontpage(){
	glBegin(GL_POLYGON);
	glColor3f(0, 1, 1);
	glVertex2f(-10, -10);
	glVertex2f(-10, 1350);
	glColor3f(1, 1, 0);
	glVertex2f(1360, 1350);
	glVertex2f(1360, -10);
	glEnd();
	glBegin(GL_2D);
	glColor3f(0, 0, 0);
	output(2, 350, 620, "SAHYADRI COLLEGE OF ENGINEERING AND MANAGEMENT");
	output(2, 550, 580, "ADYAR, MANGALURU");
	output(2, 350, 540, "DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
	output(2, 420, 500, "COMPUTER GRAPHICS AND VISUALIZATION");
	output(2, 550, 430, "MINI PROJECT ON");
	output(2, 530, 390, "Smart Garbage Collection");
	output(2, 50, 290, "TEAM MEMBERS");
	output(2, 50, 250, "Shravya J Poojary  4SF18CS142");
	output(2, 50, 210, "Suma Gowri           4SF18CS161");
	output(2, 50, 170, "Dept of CSE sec B");
	output(2, 1000, 290, "PROJECT GUIDED BY");
	output(2, 1000, 250, "Supriya");
	output(2, 1000, 210, "Assistant Professor");
	output(2, 1000, 170, "Dept of CSE");
	glColor3f(1, 0, 0);
	output(1, 610, 100, "click 'n' to next scene");
	output(1, 590, 80, "click 'b' for preveios scene");
	output(1, 595, 60, "click 's' to start the scene");
	glEnd();
}



//DISPLAY 1
//ROAD
void road(){
	//road
	glColor3f(0.8, 0.8, 0.8);
	glBegin(GL_POLYGON);
	glVertex2i(0, 250);
	glVertex2i(1350, 250);
	glVertex2i(1350, 100);
	glVertex2i(0, 100);
	glEnd();
	//road middle line
	for (i = 0; i<1350; i = i + 80)
	{
		glLineWidth(2);
		glColor3f(1, 1, 1);
		glBegin(GL_LINES);
		glVertex2i(i + 20, 175);
		glVertex2i(i + 60, 175);
		glEnd();
	}
	//road outlines
	glLineWidth(2);
	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	glVertex2i(0, 240);
	glVertex2i(1350, 240);
	glEnd();

	glLineWidth(2);
	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	glVertex2i(0, 110);
	glVertex2i(1350, 110);
	glEnd();
}

//Garbage
void garbage(){
	//garbage piles
	glColor3f(0.55, 0.47, 0.14);
	glBegin(GL_TRIANGLES);
	glVertex2i(-200, 300);
	glVertex2i(800, 300);
	glVertex2i(200, 650);
	glEnd();

	glColor3f(0.52, 0.37, 0.26);
	glBegin(GL_TRIANGLES);
	glVertex2i(200, 300);
	glVertex2i(1000, 300);
	glVertex2i(700, 670);
	glEnd();

	glColor3f(0.72, 0.45, 0.20);
	glBegin(GL_TRIANGLES);
	glVertex2i(600, 300);
	glVertex2i(1500, 300);
	glVertex2i(1300, 650);
	glEnd();

	//buldozer hand
	glColor3f(0.85, 0.85, 0.10);
	glBegin(GL_POLYGON);
	glVertex2i(0, 300);
	glVertex2i(240, 690);
	glVertex2i(260, 690);
	glVertex2i(50, 300);
	glEnd();
	//buldozer hand outline
	glLineWidth(2);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(0, 300);
	glVertex2i(240, 690);
	glVertex2i(260, 690);
	glVertex2i(50, 300);
	glEnd();
	//crane cabin
	glColor3f(0.85, 0.85, 0.10);
	glBegin(GL_POLYGON);
	glVertex2i(10, 300);
	glVertex2i(100, 300);
	glVertex2i(100, 500);
	glVertex2i(10, 500);
	glEnd();
	//crane window
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2i(40, 400);
	glVertex2i(90, 400);
	glVertex2i(90, 490);
	glVertex2i(40, 490);
	glEnd();
	//crane outline
	glLineWidth(2);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(10, 300);
	glVertex2i(100, 300);
	glVertex2i(100, 500);
	glVertex2i(10, 500);
	glEnd();
	//crane rope
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(260, 690);
	glVertex2i(260, 560);
	glEnd();
	//crane handle
	glLineWidth(4);
	glBegin(GL_LINES);
	glVertex2i(240, 560);
	glVertex2i(280, 560);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2i(240, 560);
	glVertex2i(255, 560);
	glVertex2i(255, 500);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2i(265, 560);
	glVertex2i(265, 500);
	glVertex2i(280, 560);
	glEnd();
}

//Building
void building(){
	//body
	glLineWidth(1);
	glColor3f(0.658824, 0.658824, 0.658824);
	glBegin(GL_POLYGON);
	glVertex2i(500, 300);
	glVertex2i(1100, 300);
	glVertex2i(1100, 650);
	glVertex2i(500, 650);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(500, 300);
	glVertex2i(1100, 300);
	glVertex2i(1100, 650);
	glVertex2i(500, 650);
	glEnd();
	//top
	glColor3f(0.80, 0.80, 0.80);
	glBegin(GL_POLYGON);
	glVertex2i(470, 600);
	glVertex2i(1130, 600);
	glVertex2i(1130, 650);
	glVertex2i(470, 650);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(470, 600);
	glVertex2i(1130, 600);
	glVertex2i(1130, 650);
	glVertex2i(470, 650);
	glEnd();
	//middle
	glColor3f(0.80, 0.80, 0.80);
	glBegin(GL_POLYGON);
	glVertex2i(600, 550);
	glVertex2i(1000, 550);
	glVertex2i(1000, 570);
	glVertex2i(600, 570);
	glEnd();
	
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(600, 550);
	glVertex2i(1000, 550);
	glVertex2i(1000, 570);
	glVertex2i(600, 570);
	glEnd();
	//inside
	glColor3f(0.329412, 0.329412, 0.329412);
	glBegin(GL_POLYGON);
	glVertex2i(650, 550);
	glVertex2i(950, 550);
	glVertex2i(950, 300);
	glVertex2i(650, 300);
	glEnd();

}

//Fence
void fence(){
	//first part fence
	glColor3f(0.65, 0.50, 0.39);
	glBegin(GL_POLYGON);
	glVertex2i(0, 300);
	glVertex2i(700, 300);
	glVertex2i(700, 450);
	glVertex2i(0, 450);
	glEnd();
	for (i = 0; i <= 700; i = i + 20)
	{
		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_LINES);
		glVertex2i(i, 300);
		glVertex2i(i, 450);
		glEnd();
	}
	//second part fence
	glColor3f(0.65, 0.50, 0.39);
	glBegin(GL_POLYGON);
	glVertex2i(1000, 300);
	glVertex2i(1500, 300);
	glVertex2i(1500, 450);
	glVertex2i(1000, 450);
	glEnd();
	for (i = 1000; i <= 1350; i = i + 20)
	{
		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_LINES);
		glVertex2i(i, 300);
		glVertex2i(i, 450);
		glEnd();
	}
	//gate grid lines
	for (i = 700; i <= 1000; i = i + 10)
	{
		glLineWidth(1.5);
		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_LINES);
		glVertex2i(i, 300);
		glVertex2i(i, 450);
		glEnd();
	}
	//THE GATE top nd bottom lines
	glLineWidth(1.5);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(700, 300);
	glVertex2i(1000, 300);
	glEnd();

	glLineWidth(1.5);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(700, 450);
	glVertex2i(1000, 450);
	glEnd();

}

//draw circle
void drawcircle(int cr, int cg, int cb, int type, int cx, int cy, int r, int section)
{
	glColor3f(cr, cg, cb);
	if (type == 1){
		glBegin(GL_POLYGON);
		for (double i = 0; i < section*PI / 2; i += PI / 6000) //<-- Change this Value
			glVertex3f(cx + cos(i) * r, cy + sin(i) * r, 0);
		glEnd();
	}
	else if (type == 0)
	{
		glBegin(GL_LINE_LOOP);
		for (double i = 0; i < section*PI / 2; i += PI / 6000) //<-- Change this Value
			glVertex3f(cx + cos(i) * r, cy + sin(i) * r, 0.0);
		glEnd();
	}
	return;
}

void truck(int xs){
	//truck body green outside
	glColor3f(0.184314, 0.409804, 0.184314);
	glBegin(GL_POLYGON);
	glVertex2i(xs + 700, 200);
	glVertex2i(xs + 1200, 200);
	glVertex2i(xs + 1200, 420);
	glVertex2i(xs + 1100, 500);
	glVertex2i(xs + 700, 500);
	glEnd();
	//truck body green inside
	glColor3f(0.184314, 0.509804, 0.284314);
	glBegin(GL_POLYGON);
	glVertex2i(xs + 740, 270);
	glVertex2i(xs + 1160, 270);
	glVertex2i(xs + 1160, 390);
	glVertex2i(xs + 1060, 470);
	glVertex2i(xs + 740, 470);
	glEnd();
	//truck body down black
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2i(xs + 490, 200);
	glVertex2i(xs + 1210, 200);
	glVertex2i(xs + 1210, 240);
	glVertex2i(xs + 490, 240);
	glEnd();
	//truck body green outline
	glLineWidth(3);
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(xs + 700, 200);
	glVertex2i(xs + 1200, 200);
	glVertex2i(xs + 1200, 420);
	glVertex2i(xs + 1100, 500);
	glVertex2i(xs + 700, 500);
	glEnd();
	//truck front white
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2i(xs + 700, 200);
	glVertex2i(xs + 500, 200);
	glVertex2i(xs + 500, 330);
	glVertex2i(xs + 520, 350);
	glVertex2i(xs + 570, 350);
	glVertex2i(xs + 600, 450);
	glVertex2i(xs + 700, 450);
	glEnd();
	//truck front white outline
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(xs + 700, 200);
	glVertex2i(xs + 500, 200);
	glVertex2i(xs + 500, 330);
	glVertex2i(xs + 520, 350);
	glVertex2i(xs + 570, 350);
	glVertex2i(xs + 600, 450);
	glVertex2i(xs + 700, 450);
	glEnd();
	//truck window
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2i(xs + 690, 360);
	glVertex2i(xs + 590, 360);
	glVertex2i(xs + 610, 440);
	glVertex2i(xs + 690, 440);
	glEnd();
	//headlight
	glColor3f(1, 0.6, 0);
	glBegin(GL_POLYGON);
	glVertex2i(xs + 500, 320);
	glVertex2i(xs + 500, 240);
	glVertex2i(xs + 515, 240);
	glVertex2i(xs + 515, 310);
	glEnd();
	//headlight outline
	glLineWidth(1);
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(xs + 500, 320);
	glVertex2i(xs + 500, 240);
	glVertex2i(xs + 515, 240);
	glVertex2i(xs + 515, 310);
	glEnd();
	//backlight
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2i(xs + 1200, 240);
	glVertex2i(xs + 1200, 290);
	glVertex2i(xs + 1185, 290);
	glVertex2i(xs + 1185, 240);
	glEnd();
	//backlight outline
	glLineWidth(1);
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(xs + 1200, 240);
	glVertex2i(xs + 1200, 290);
	glVertex2i(xs + 1185, 290);
	glVertex2i(xs + 1185, 240);
	glEnd();
	//drawcircle(1,0,0,1,1000,350,50,4);
	drawcircle(1, 0, 0.5, 1, xs + 1000, 200, 68, 2);
	drawcircle(0, 0, 0, 1, xs + 1000, 200, 60, 4);
	drawcircle(1, 1, 1, 1, xs + 1000, 200, 35, 4);
	drawcircle(0, 0, 0, 1, xs + 1000, 200, 5, 4);
	//tyres
	drawcircle(1, 0, 0.5, 1, xs + 600, 200, 68, 2);
	drawcircle(0, 0, 0, 1, xs + 600, 200, 60, 4);
	drawcircle(1, 1, 1, 1, xs + 600, 200, 35, 4);
	drawcircle(0, 0, 0, 1, xs + 600, 200, 5, 4);
	glBegin(GL_2D);
	glColor3f(0, 0, 0);
	glEnd();

	output(1, 680, 553, "GARBAGE DISPOSAL YARD");
}

void display1(){
	if (xshifter > -1250){
		if (shift) xshifter -= 2;

		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(0.0, 1.0, 0.0);

		//for land
		glBegin(GL_POLYGON);
		glVertex2i(0, 300);
		glVertex2i(1350, 300);
		glVertex2i(1350, 0);
		glVertex2i(0, 0);
		glEnd();

		//garbage hill
		road();
		garbage();
		building();

		//for fence
		fence();
		glColor3f(0.8, 0.7, 0.5);
		truck(xshifter);
	}
	else{
		scene = 3;
		shift = false;
	}
}


//DISPLAY2
//Roads
void roadVertical(int xstart, int ystart, int xend, int yend){
	if (xstart == xend){
		//road
		glColor3f(0, 0, 0);
		glBegin(GL_POLYGON);
		glVertex2i(xstart, ystart);
		glVertex2i(xstart + 50, ystart);
		glVertex2i(xend + 50, yend);
		glVertex2i(xend, yend);
		glEnd();
		//road outlines
		glColor3f(1, 1, 1);
		glLineWidth(4);
		glBegin(GL_LINES);
		glVertex2i(xstart, ystart);
		glVertex2i(xend, yend);
		glEnd();
		glBegin(GL_LINES);
		glVertex2i(xstart + 50, ystart);
		glVertex2i(xend + 50, yend);
		glEnd();
		//road dotted lines
		for (int i = ystart - 40; i >= yend; i = i - 40){
			glColor3f(1, 1, 1);
			glBegin(GL_LINES);
			glVertex2i(xstart + 25, i);
			glVertex2i(xstart + 25, i + 20);
			glEnd();
		}
	}
	else printf("error in calling vertical road. condition->start and end x-axis value must be same");
}

void roadHorizontal(int xstart, int ystart, int xend, int yend){
	if (ystart == yend){
		//road
		glColor3i(0, 0, 0);
		glBegin(GL_POLYGON);
		glVertex2i(xstart, ystart);
		glVertex2i(xend, yend);
		glVertex2i(xend, yend - 50);
		glVertex2i(xstart, ystart - 50);
		glEnd();
		//road outlines
		glColor3f(1, 1, 1);
		glLineWidth(4);
		glBegin(GL_LINES);
		glVertex2i(xstart, ystart);
		glVertex2i(xend, yend);
		glEnd();
		glBegin(GL_LINES);
		glVertex2i(xstart, ystart - 50);
		glVertex2i(xend, yend - 50);
		glEnd();
		//road doted lines
		for (int i = xstart + 40; i <= xend; i = i + 40){
			glColor3f(1, 1, 1);
			glBegin(GL_LINES);
			glVertex2i(i, ystart - 25);
			glVertex2i(i - 20, ystart - 25);
			glEnd();
		}
	}
	else{
		printf("error in calling horizontal road. condition->start and end y-axis value must be same");
	}
}

void intersection(int x, int y)
{
	//intersection
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + 50, y);
	glVertex2i(x + 50, y + 50);
	glVertex2i(x, y + 50);
	glEnd();
	//outline
	glLineWidth(2);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(x, y);
	glVertex2i(x + 50, y);
	glVertex2i(x + 50, y + 50);
	glVertex2i(x, y + 50);
	glEnd();
}

void drawroad()
{
	roadHorizontal(100, 100, 1350, 100);//bottom road
	roadVertical(50, 630, 50, 100);
	roadHorizontal(100, 670, 1200, 670);//top road
	roadVertical(1200, 620, 1200, 98);

	roadHorizontal(98, 490, 1200, 490);//top-1
	//vertical 2 together
	roadVertical(700, 442, 700, 98);
	roadVertical(950, 442, 950, 98);

	roadHorizontal(97, 300, 702, 300);//botoom-1
	roadVertical(350, 622, 350, 298);//vertical top left
	roadVertical(750, 622, 750, 488);//vertical top right
	roadVertical(400, 252, 400, 98);//vertical bottom left
	//roadVertical(400, 633, 400, 447);
	intersection(50, 50);
	intersection(50, 620);
	intersection(1200, 620);
	intersection(350, 440);
}

void determineColourForHouse(int x, int flag){
	if (flag == 0){
		if (x == 1){
			glColor3f(1, 0, 0);
		}
		else if (x == 2){
			glColor3f(0, 1, 0);
		}
		else{
			glColor3f(0, 0, 1);
		}
	}
	else if (flag == 1){
		if (x == 1){
			glColor3f(1, 0.2, 0.2);
		}
		else if (x == 2){
			glColor3f(0, 1, 0);
		}
		else{
			glColor3f(0.2, 0.2, 1);
		}
	}
	else{
		if (x == 1){
			glColor3f(1, 00.3, 0.5);
		}
		else if (x == 2){
			glColor3f(0, 1, 0);
		}
		else{
			glColor3f(0.5, 0.3, 1);
		}
	}
}

//code for house
void houseVertical(int xpos, int ypos, int x){
	determineColourForHouse(x, 0);
	glBegin(GL_POLYGON);
	glVertex2i(xpos, ypos);
	glVertex2i(xpos + 45, ypos);
	glVertex2i(xpos + 45, ypos - 90);
	glVertex2i(xpos, ypos - 90);
	glEnd();
	//outline white
	glColor3f(0, 0, 0);
	glLineWidth(1);
	glBegin(GL_LINE_LOOP);
	glVertex2i(xpos, ypos);
	glVertex2i(xpos + 45, ypos);
	glVertex2i(xpos + 45, ypos - 90);
	glVertex2i(xpos, ypos - 90);
	glEnd();
	//outline top triangle
	glBegin(GL_LINE_LOOP);
	glVertex2i(xpos, ypos);
	glVertex2i(xpos + 45, ypos);
	glVertex2f((2 * xpos + 45) / 2, ypos - 30);
	glEnd();
	//outline
	glBegin(GL_LINES);
	glVertex2f((2 * xpos + 45) / 2, ypos - 30);
	glVertex2f((2 * xpos + 45) / 2, ypos - 65);
	glEnd();
	//triangle down outline
	glBegin(GL_LINE_LOOP);
	glVertex2i(xpos, ypos - 90);
	glVertex2i(xpos + 45, ypos - 90);
	glVertex2f((2 * xpos + 45) / 2, ypos - 65);
	glEnd();
	//polygon
	determineColourForHouse(x, 1);
	glBegin(GL_POLYGON);
	glVertex2f((2 * xpos + 45) / 2, ypos - 30);
	glVertex2f(xpos + 45, ypos);
	glVertex2f(xpos + 45, ypos - 90);
	glVertex2f((2 * xpos + 45) / 2, ypos - 65);
	glEnd();
	//triangle down
	determineColourForHouse(x, 2);
	glBegin(GL_TRIANGLES);
	glVertex2f(xpos, ypos - 90);
	glVertex2f((2 * xpos + 45) / 2, ypos - 65);
	glVertex2f(xpos + 45, ypos - 90);
	glEnd();
}

void houseHorizontal(int xpos, int ypos, int x){
	determineColourForHouse(x, 0);
	//house
	glBegin(GL_POLYGON);
	glVertex2i(xpos, ypos);
	glVertex2i(xpos + 90, ypos);
	glVertex2i(xpos + 90, ypos - 45);
	glVertex2i(xpos, ypos - 45);
	glEnd();
	//white outline
	glColor3f(0, 0, 0);
	glLineWidth(1);
	glBegin(GL_LINE_LOOP);
	glVertex2i(xpos, ypos);
	glVertex2i(xpos + 90, ypos);
	glVertex2i(xpos + 90, ypos - 45);
	glVertex2i(xpos, ypos - 45);
	glEnd();
	//outline top triangle
	glBegin(GL_LINE_LOOP);
	glVertex2i(xpos, ypos);
	glVertex2i(xpos, ypos - 45);
	glVertex2f(xpos + 30, ypos - (45 / 2));
	glEnd();
	//parallel lines
	glBegin(GL_LINES);
	glVertex2f(xpos + 30, ypos - (45 / 2));
	glVertex2f(xpos + 65, ypos - (45 / 2));
	glEnd();
	//triangle outline
	glBegin(GL_LINE_LOOP);
	glVertex2i(xpos + 90, ypos);
	glVertex2i(xpos + 90, ypos - 45);
	glVertex2f(xpos + 65, ypos - (45 / 2));
	glEnd();
	//triangle
	determineColourForHouse(x, 1);
	glBegin(GL_TRIANGLES);
	glVertex2f(xpos + 90, ypos);
	glVertex2f(xpos + 90, ypos - 45);
	glVertex2f(xpos + 65, ypos - 45 / 2);
	glEnd();
	//polygon
	determineColourForHouse(x, 2);
	glBegin(GL_POLYGON);
	glVertex2f(xpos + 30, ypos - 45 / 2);
	glVertex2f(xpos, ypos - 45);
	glVertex2f(xpos + 90, ypos - 45);
	glVertex2f(xpos + 65, ypos - 45 / 2);
	glEnd();

}

void garbageCan(int xpos, int ypos, int width, int y){
	//middle part
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex2f(xpos, ypos);
	glVertex2f(xpos + 50, ypos);
	glVertex2f(xpos + 50, ypos - 8);
	glVertex2f(xpos, ypos - 8);
	glEnd();
	//body
	glBegin(GL_POLYGON);
	glVertex2f(xpos + 5, ypos - 8);
	glVertex2f(xpos + 10, ypos - 50);
	glVertex2f(xpos + 40, ypos - 50);
	glVertex2f(xpos + 45, ypos - 8);
	glEnd();
	//top
	glBegin(GL_POLYGON);
	glVertex2f(xpos + 22, ypos);
	glVertex2f(xpos + 22, ypos + 5);
	glVertex2f(xpos + 28, ypos + 5);
	glVertex2f(xpos + 28, ypos);
	glEnd();
	r = y;
	glLineWidth(width);
	//middle part outline
	glColor3f(r, g, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(xpos, ypos);
	glVertex2f(xpos + 50, ypos);
	glVertex2f(xpos + 50, ypos - 8);
	glVertex2f(xpos, ypos - 8);
	glEnd();
	//body outline
	glBegin(GL_LINE_LOOP);
	glVertex2f(xpos + 5, ypos - 8);
	glVertex2f(xpos + 10, ypos - 50);
	glVertex2f(xpos + 40, ypos - 50);
	glVertex2f(xpos + 45, ypos - 8);
	glEnd();
	//top outline
	glBegin(GL_LINE_LOOP);
	glVertex2f(xpos + 22, ypos);
	glVertex2f(xpos + 22, ypos + 5);
	glVertex2f(xpos + 28, ypos + 5);
	glVertex2f(xpos + 28, ypos);
	glEnd();
	//sensor
	if (sensor == 1)
	{
		if (y == 1)
			glColor3f(0, 1, 0);
		else
			glColor3f(0, 0, 0);
		glBegin(GL_POLYGON);
		glVertex2f(xpos + 18, ypos - 20);
		glVertex2f(xpos + 18, ypos - 35);
		glVertex2f(xpos + 33, ypos - 35);
		glVertex2f(xpos + 33, ypos - 20);
		glEnd();
	}
}

void drawhouse(int gw1, int gw2, int gw3, int gc1, int gc2, int gc3)
{	
	//top part house
	houseVertical(120, 600, 1);
	houseVertical(280, 600, 3);
	garbageCan(200, 600, 1, 0);

	houseVertical(420, 600, 3);
	houseVertical(680, 600, 3);
	houseHorizontal(520, 550, 1);
	garbageCan(560, 610, gw2, gc2);

	houseVertical(1000, 600, 3);
	houseVertical(1110, 600, 1);
	houseHorizontal(840, 550, 1);
	garbageCan(905, 610, 1, 0);

	//middle
	houseVertical(120, 415, 1);
	houseVertical(285, 415, 3);
	garbageCan(200, 410, 1, 0);

	houseVertical(430, 415, 3);
	houseVertical(490, 415, 1);
	houseHorizontal(580, 360, 3);
	garbageCan(570, 420, gw1, gc1);

	//bottom
	houseVertical(130, 230, 3);
	houseVertical(310, 230, 3);
	houseHorizontal(210, 170, 1);
	garbageCan(230, 230, 1, 0);

	houseHorizontal(530, 210, 3);

	houseVertical(780, 220, 1);
	houseVertical(870, 220, 3);

	garbageCan(1120, 330, gw3, gc3);
}

void flats(int xpos, int ypos)
{
	//outer layer
	glColor3f(0.8, 0.8, 0.8);
	glBegin(GL_POLYGON); 
	glVertex2f(xpos, ypos);
	glVertex2f(xpos + 160, ypos);
	glVertex2f(xpos + 160, ypos - 80);
	glVertex2f(xpos + 90, ypos - 80);
	glVertex2f(xpos + 90, ypos - 160);
	glVertex2f(xpos, ypos - 160);
	glEnd();
	//inner layer
	glColor3f(0.6, 0.6, 0.6);
	glBegin(GL_POLYGON);
	glVertex2f(xpos + 10, ypos - 10);
	glVertex2f(xpos + 150, ypos - 10);
	glVertex2f(xpos + 150, ypos - 70);
	glVertex2f(xpos + 80, ypos - 70);
	glVertex2f(xpos + 80, ypos - 150);
	glVertex2f(xpos + 10, ypos - 150);
	glEnd();
	//inner middle
	glColor3f(0.8, 0.8, 0.8);
	glBegin(GL_POLYGON);
	glVertex2f(xpos + 20, ypos - 20);
	glVertex2f(xpos + 20, ypos - 60);
	glVertex2f(xpos + 60, ypos - 60);
	glVertex2f(xpos + 60, ypos - 20);
	glEnd();

	//inner middle outline
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(xpos + 20, ypos - 20);
	glVertex2f(xpos + 20, ypos - 60);
	glVertex2f(xpos + 60, ypos - 60);
	glVertex2f(xpos + 60, ypos - 20);
	glEnd();
	//outer outline
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(xpos, ypos);
	glVertex2f(xpos + 160, ypos);
	glVertex2f(xpos + 160, ypos - 80);
	glVertex2f(xpos + 90, ypos - 80);
	glVertex2f(xpos + 90, ypos - 160);
	glVertex2f(xpos, ypos - 160);
	glEnd();
	//inner outline
	glBegin(GL_LINE_LOOP);
	glVertex2f(xpos + 10, ypos - 10);
	glVertex2f(xpos + 150, ypos - 10);
	glVertex2f(xpos + 150, ypos - 70);
	glVertex2f(xpos + 80, ypos - 70);
	glVertex2f(xpos + 80, ypos - 150);
	glVertex2f(xpos + 10, ypos - 150);
	glEnd();
}

void drawback()
{	
	//Background green
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2i(0, 700);
	glVertex2i(1350, 700);
	glVertex2i(1350, 0);
	glVertex2i(0, 0);
	glEnd();

	drawroad();

	drawhouse(gw1, gw2, gw3, gc1, gc2, gc3);

	glLineWidth(1);
	flats(760, 430);
	flats(1010, 433);
	flats(1010, 270);

	if (scene != 5)
	{	
		//fuel
		glColor3f(0.5, 0.5, 0.5);
		glLineWidth(3);
		glBegin(GL_POLYGON);
		glVertex2f(1280, 200);
		glVertex2f(1280, 600);
		glVertex2f(1330, 600);
		glVertex2f(1330, 200);
		glEnd();

		glColor3f(0, 0.7, 1);
		glLineWidth(3);
		glBegin(GL_POLYGON);
		glVertex2f(1280, 200);
		glVertex2f(1280, 590 - fuel);
		glVertex2f(1330, 590 - fuel);
		glVertex2f(1330, 200);
		glEnd();

		glColor3f(0, 0, 0);
		glLineWidth(3);
		glBegin(GL_LINE_LOOP);
		glVertex2f(1280, 200);
		glVertex2f(1280, 600);
		glVertex2f(1330, 600);
		glVertex2f(1330, 200);
		glEnd();

		glBegin(GL_2D);
		glColor3f(0, 0, 1);
		output(2, 1275, 160, "FUEL");
		output(1, 570, 20, "TOP VIEW OF THE CITY");
		glEnd();

		if (shift && fuel<380 && scene == 3)
			fuel = fuel + 0.01;
		else if (shift && fuel<380 && scene == 6)
			fuel = fuel + 0.007;
	}
	//Top view writing
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
	glVertex2f(560, 10);
	glVertex2f(800, 10);
	glVertex2f(800, 40);
	glVertex2f(560, 40);
	glEnd();

	glColor3f(0.6, 0.6, 0.6);
	glBegin(GL_POLYGON);
	glVertex2f(560, 10);
	glVertex2f(800, 10);
	glVertex2f(800, 40);
	glVertex2f(560, 40);
	glEnd();

	glBegin(GL_2D);
	glColor3f(0, 0, 0);
	output(1, 570, 20, "TOP VIEW OF THE CITY");
	glEnd();
}

void drawtruck(float xs, float ys, int dir)
{
	//left direction
	if (dir == 1){
		glPushMatrix();
		glTranslatef(xs, ys, 0);
		glColor3f(0.184314, 0.509804, 0.184314);
		glBegin(GL_POLYGON);
		glVertex2f(0, 0);
		glVertex2f(60, 0);
		glVertex2f(60, 35);
		glVertex2f(0, 35);
		glEnd();

		glColor3f(1, 1, 1);
		glBegin(GL_POLYGON);
		glVertex2f(-15, 5);
		glVertex2f(0, 5);
		glVertex2f(0, 30);
		glVertex2f(-15, 30);
		glEnd();
		glPopMatrix();
	}
	//moving upwards
	else if (dir == 2)
	{
		glPushMatrix();
		glTranslatef(xs, ys, 0);
		glColor3f(0.184314, 0.509804, 0.184314);
		glBegin(GL_POLYGON);
		glVertex2f(0, 0);
		glVertex2f(0, 60);
		glVertex2f(35, 60);
		glVertex2f(35, 0);
		glEnd();

		glColor3f(1, 1, 1);
		glBegin(GL_POLYGON);
		glVertex2f(5, 60);
		glVertex2f(30, 60);
		glVertex2f(30, 70);
		glVertex2f(5, 70);
		glEnd();
		glPopMatrix();

	}
	//moving right
	else if (dir == 3){
		glPushMatrix();
		glTranslatef(xs, ys, 0);
		glColor3f(0.184314, 0.509804, 0.184314);
		glBegin(GL_POLYGON);
		glVertex2f(0, 0);
		glVertex2f(60, 0);
		glVertex2f(60, 35);
		glVertex2f(0, 35);
		glEnd();

		glColor3f(1, 1, 1);
		glBegin(GL_POLYGON);
		glVertex2f(60, 5);
		glVertex2f(60, 30);
		glVertex2f(75, 30);
		glVertex2f(75, 5);
		glEnd();
		glPopMatrix();
	}
	//moving downwards
	else if (dir == 4){
		glPushMatrix();
		glTranslatef(xs, ys, 0);
		glColor3f(0.184314, 0.509804, 0.184314);
		glBegin(GL_POLYGON);
		glVertex2f(0, 0);
		glVertex2f(0, 60);
		glVertex2f(35, 60);
		glVertex2f(35, 0);
		glEnd();

		glColor3f(1, 1, 1);
		glBegin(GL_POLYGON);
		glVertex2f(5, 0);
		glVertex2f(30, 0);
		glVertex2f(30, -10);
		glVertex2f(5, -10);
		glEnd();
		glPopMatrix();
	}
}

void display2(){
	drawback();
	//all left
	if (shift && xs>60 && p == 1)
	{
		drawback();
		xs = xs - 0.5;
		drawtruck(xs, ys, 1);
		if (xs <= 60)
			p = 2;
	}
	//upward
	else if (shift&& ys<260 && p == 2)
	{
		drawback();
		ys = ys + 0.5;
		drawtruck(xs, ys, 2);
		if (ys >= 260)
			p = 3;
	}
	//right
	else if (shift && xs<710 && p == 3)
	{
		drawback();
		xs = xs + 0.5;
		if (xs == 220)
			Sleep(1000);
		drawtruck(xs, ys, 3);
		if (xs >= 710)
			p = 4;
	}
	//upward
	else if (shift&& ys<445 && p == 4)
	{
		drawback();
		ys = ys + 0.5;
		drawtruck(xs, ys, 2);
		if (ys >= 445)
			p = 5;
	}
	//left
	else if (shift && xs>55 && p == 5)
	{
		drawback();
		xs = xs - 0.5;
		if (xs == 560)
			Sleep(1000);
		if (xs == 210)
			Sleep(1000);
		drawtruck(xs, ys, 1);
		if (xs <= 560)
		{
			gc1 = 0;
			gw1 = 1;
		}
		if (xs <= 55)
			p = 6;
	}
	//upward
	else if (shift&& ys<630 && p == 6)
	{
		drawback();
		ys = ys + 0.5;
		drawtruck(xs, ys, 2);
		if (ys >= 630)
			p = 7;
	}
	//all right
	else if (shift && xs<1210 && p == 7)
	{
		drawback();
		xs = xs + 0.5;
		if (xs == 210)
			Sleep(1000);
		if (xs == 560)
			Sleep(1000);
		if (xs == 905)
			Sleep(1000);
		drawtruck(xs, ys, 3);
		if (xs >= 560)
		{
			gc2 = 0;
			gw2 = 1;
		}
		if (xs >= 1210)
			p = 8;
	}
	//downward
	else if (shift && ys>60 && p == 8)
	{
		drawback();
		ys = ys - 0.5;
		if (ys == 300)
			Sleep(1000);
		drawtruck(xs, ys, 4);
		if (ys <= 300)
		{
			gc3 = 0;
			gw3 = 1;
		}
		if (ys <= 60)
			p = 9;
	}
	//right
	else if (shift && xs<1400 && p == 9)
	{
		drawback();
		xs = xs + 0.4;
		drawtruck(xs, ys, 3);
		if (xs>1400)
		{
			Sleep(4000);
			scene = 4;
			shift = false;
			gc1 = 1; gc2 = 1; gc3 = 1; gw1 = 3; gw2 = 3; gw3 = 3;
		}
	}
}



//DISPLAY3
//Garbage can embedded with sensors
void drawgarbage(){
	int j = 1, k = 1, l = 1;
	//body
	glColor3f(0.8, 0.8, 0.8);
	glBegin(GL_POLYGON);
	glVertex2f(610, 100);
	glVertex2f(890, 100);
	glVertex2f(900, 535);
	glVertex2f(600, 535);
	glEnd();

	glColor3f(0.8, 0.8, 0.8);
	glBegin(GL_POLYGON);
	glVertex2f(580, 535);
	glVertex2f(920, 535);
	glVertex2f(920, 585);
	glVertex2f(750, 605);
	glVertex2f(580, 585);
	glEnd();
	//filling garbage
	if (c>1.1)
	{
		c = 1.01;
	}
	if (c>1.0)
	{
		glColor3f(0.45, 0.65, 0.27);
		glBegin(GL_POLYGON);
		glVertex2f(900, 503);
		glVertex2f(900, 525);
		glVertex2f(605, 515);
		glVertex2f(610, 103);
		glEnd();
	}
	if (c>0.81)
	{
		glColor3f(0.62, 0.35, 0.30);
		glBegin(GL_POLYGON);
		glVertex2f(890, 303);
		glVertex2f(895, 506);
		glVertex2f(710, 525);
		glVertex2f(608, 483);
		glVertex2f(610, 103);
		glEnd();
	}
	if (c>0.61)
	{
		glColor3f(0.5, 0.377, 0.16);
		glBegin(GL_POLYGON);
		glVertex2f(890, 203);
		glVertex2f(893, 353);
		glVertex2f(608, 303);
		glVertex2f(610, 103);
		glEnd();
	}
	if (c>0.41)
	{
		glColor3f(0.72, 0.45, 0.20);
		glBegin(GL_POLYGON);
		glVertex2f(890, 103);
		glVertex2f(889, 203);
		glVertex2f(610, 203);
		glVertex2f(610, 103);
		glEnd();
	}
	if (c>0.21)
	{
		glColor3f(0.52, 0.37, 0.26);
		glBegin(GL_POLYGON);
		glVertex2f(609, 153);
		glVertex2f(889, 103);
		glVertex2f(889, 203);
		glVertex2f(806, 300);
		glEnd();
	}
	if (c>0.0)
	{
		glColor3f(0.55, 0.47, 0.14);
		glBegin(GL_TRIANGLES);
		glVertex2f(609, 103);
		glVertex2f(889, 103);
		glVertex2f(606, 200);
		glEnd();
	}
	//outlines according to garbage filled
	glColor3f(0 + c, 1 - c, 0);
	glLineWidth(5);
	glBegin(GL_LINE_LOOP);
	glVertex2f(610, 100);
	glVertex2f(890, 100);
	glVertex2f(900, 535);
	glVertex2f(600, 535);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2f(580, 535);
	glVertex2f(920, 535);
	glVertex2f(920, 585);
	glVertex2f(750, 605);
	glVertex2f(580, 585);
	glEnd();
	//transmitter
	glColor3f(1, 1, 1);
	glLineWidth(1);
	glBegin(GL_TRIANGLES);
	glVertex2f(705, 500);
	glVertex2f(745, 500);
	glVertex2f(725, 555);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(705, 500);
	glVertex2f(745, 500);
	glVertex2f(725, 555);
	glEnd();
	//receiver
	glColor3f(1, 1, 1);
	glBegin(GL_TRIANGLES);
	glVertex2f(755, 500);
	glVertex2f(795, 500);
	glVertex2f(775, 555);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(755, 500);
	glVertex2f(795, 500);
	glVertex2f(775, 555);
	glEnd();
	//sensor
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(700, 535);
	glVertex2f(800, 535);
	glVertex2f(800, 570);
	glVertex2f(700, 570);
	glEnd();
	//embedded box
	glColor3f(0.2, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2f(650, 200);
	glVertex2f(850, 200);
	glVertex2f(850, 370);
	glVertex2f(650, 370);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(650, 200);
	glVertex2f(850, 200);
	glVertex2f(850, 370);
	glVertex2f(650, 370);

	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(660, 210);
	glVertex2f(840, 210);
	glVertex2f(840, 360);
	glVertex2f(660, 360);
	glEnd();

	glBegin(GL_2D);
	glColor3f(1, 1, 1);
	output(2, 680, 300, "EMBEDDED ");
	output(2, 700, 270, "SYSTEM ");
	glEnd();
	//antenna
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(850, 260);
	glVertex2f(950, 260);
	glVertex2f(950, 270);
	glVertex2f(850, 270);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2f(940, 260);
	glVertex2f(960, 260);
	glVertex2f(950, 400);
	glEnd();
	//lines connection
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2f(660, 370);
	glVertex2f(660, 560);
	glEnd();
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2f(700, 560);
	glVertex2f(660, 560);
	glEnd();
	glLineWidth(1);

	if (c>1)
	{
		//lines connection
		j = l = 0;
		k = 1;
		glColor3f(0, 1, 0);
		glLineWidth(4);
		glBegin(GL_LINES);
		glVertex2f(660, 370);
		glVertex2f(660, 560);
		glEnd();
		glLineWidth(4);
		glBegin(GL_LINES);
		glVertex2f(700, 560);
		glVertex2f(660, 560);
		glEnd();
		//three signals
		glColor3f(1, 1, 1);
		glLineWidth(3);
		glBegin(GL_LINES);
		glVertex2f(950, 397);
		glVertex2f(950 - signal / 5, 400 + signal);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(950, 400);
		glVertex2f(950, 400 + signal);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(953, 400);
		glVertex2f(953 + signal / 5, 400 + signal);
		glEnd();
		signal = signal + 0.5;
		if (signal == 100)
			signal = 0;
	}
	drawcircle(j, k, l, 1, 750, 550, 8, 4);
	drawcircle(j, k, l, 1, 750, 340, 15, 4);
	drawcircle(0, 0, 0, 0, 750, 340, 15, 4);
}

//Description
void description(){
	//box
	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex2f(95, 600);
	glVertex2f(370, 600);
	glVertex2f(370, 640);
	glVertex2f(95, 640);
	glEnd();
	//box outline
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(95, 600);
	glVertex2f(370, 600);
	glVertex2f(370, 640);
	glVertex2f(95, 640);
	glEnd();
	//descriptions
	glBegin(GL_2D);
	glColor3f(1, 1, 1);
	output(2, 100, 610, "SMART GARBAGE BIN:");
	glColor3f(0, 0, 0);
	output(1, 100, 560, "DESCRIPTION:");
	output(1, 100, 510, "The ultrasonic sensor will detect the garbage level");
	output(1, 100, 460, "and once the garbage bin becomes almost  full the  ");
	output(1, 100, 410, "embedded system will send signals  to the system");
	output(1, 100, 360, "installed in the garbage truck.  Using these signals");
	output(1, 100, 310, "shortest route is  calculated  and displayed to  the");
	output(1, 100, 260, "driver.");
	output(1, 100, 210, "->Press g to increase garbage level.");
	glEnd();
	//indicators
	glLineWidth(1);
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(800, 560);
	glVertex2f(1000, 560);
	glEnd();
	glLineWidth(1);
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(793, 510);
	glVertex2f(1000, 510);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(725, 460);
	glVertex2f(1000, 460);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(725, 460);
	glVertex2f(725, 500);
	glEnd();
	//indicator box
	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex2f(1000, 580);
	glVertex2f(1250, 580);
	glVertex2f(1250, 540);
	glVertex2f(1000, 540);
	glEnd();
	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex2f(1000, 490);
	glVertex2f(1250, 490);
	glVertex2f(1250, 530);
	glVertex2f(1000, 530);
	glEnd();
	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex2f(1000, 480);
	glVertex2f(1250, 480);
	glVertex2f(1250, 440);
	glVertex2f(1000, 440);
	glEnd();
	//labels
	glBegin(GL_2D);
	glColor3f(1, 1, 1);
	output(1, 1020, 555, "ULTRA SONIC SENSOR");
	output(1, 1050, 505, "TRANSMITTOR");
	output(1, 1075, 455, "RECIEVER");
	glEnd();
	//outline
	glLineWidth(1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(1000, 580);
	glVertex2f(1250, 580);
	glVertex2f(1250, 540);
	glVertex2f(1000, 540);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2f(1000, 490);
	glVertex2f(1250, 490);
	glVertex2f(1250, 530);
	glVertex2f(1000, 530);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2f(1000, 440);
	glVertex2f(1250, 440);
	glVertex2f(1250, 480);
	glVertex2f(1000, 480);
	glEnd();
}

void display3(){
	glBegin(GL_POLYGON);
	glColor3f(0, 0.5, 1);
	glVertex2f(-100, -100);
	glVertex2f(1500, -100);
	glColor3f(0, 1, 1);
	glVertex2f(1500, 800);
	glVertex2f(-100, 800);
	glEnd();

	drawgarbage();
	description();
}



void display4(){
	sensor = 1;
	drawback();
	if (shift){
		//linewidth increase and decrease
		if (sign == 1)
		{
			lz = lz + 0.05;
			if (lz>15)
				sign = 0;
		}
		else{
			lz = lz - 0.05;
			if (lz<1)
				sign = 1;
		}
		//path
		glLineWidth(lz);
		glColor3f(1, 1, 0);
		glBegin(GL_LINE_LOOP);
		glVertex2f(1350, 80);
		glVertex2f(980, 80);
		glVertex2f(980, 460);
		glVertex2f(370, 460);
		glVertex2f(370, 640);
		glVertex2f(1230, 640);
		glVertex2f(1230, 80);
		glEnd();
	}
}



//Path outline
void drawgps(){
	//path
	glLineWidth(6);
	glColor3f(0.7, 0.7, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(1350, 80);
	glVertex2f(980, 80);
	glVertex2f(980, 460);
	glVertex2f(370, 460);
	glVertex2f(370, 640);
	glVertex2f(1230, 640);
	glVertex2f(1230, 80);
	glEnd();
}

void display5(){
	sensor = 1;
	drawback();
	drawgps();
	//left
	if (shift && xs>960 && p == 1)
	{
		drawback();
		drawgps();
		xs = xs - 0.5;
		drawtruck(xs, ys, 1);
		if (xs <= 960)
			p = 2;
	}
	//upward
	else if (shift&& ys<450 && p == 2)
	{
		drawback();
		drawgps();
		ys = ys + 0.5;
		drawtruck(xs, ys, 2);
		if (ys >= 450)
			p = 3;
	}
	//left
	else if (shift && xs>360 && p == 3)
	{
		drawback();
		drawgps();
		xs = xs - 0.5;
		if (xs == 560)
			Sleep(1000);
		drawtruck(xs, ys, 1);
		if (xs <= 560)
		{
			gc1 = 0;
			gw1 = 1;
		}
		if (xs <= 360)
			p = 4;
	}
	//upward
	else if (shift && ys<630 && p == 4)
	{
		drawback();
		drawgps();
		ys = ys + 0.5;
		drawtruck(xs, ys, 2);
		if (ys >= 630)
			p = 5;
	}
	//right
	else if (shift && xs<1210 && p == 5)
	{
		drawback();
		drawgps();
		xs = xs + 0.5;
		if (xs == 560)
			Sleep(1000);
		drawtruck(xs, ys, 3);
		if (xs >= 560)
		{
			gc2 = 0;
			gw2 = 1;
		}
		if (xs >= 1210)
			p = 6;
	}
	//dwonward
	else if (shift&& ys>60 && p == 6)
	{
		drawback();
		drawgps();
		ys = ys - 0.5;
		if (ys == 300)
			Sleep(1000);
		drawtruck(xs, ys, 4);
		if (ys <= 300)
		{
			gc3 = 0;
			gw3 = 1;
		}
		if (ys <= 60)
			p = 7;
	}
	//left
	else if (shift && xs<1350 && p == 7)
	{
		drawback();
		drawgps();
		xs = xs + 0.3;
		drawtruck(xs, ys, 3);
		if (xs >= 1350)
		{
			Sleep(4000);
			scene = 7;
			shift = false;
			gc1 = 1; gc2 = 1; gc3 = 1; gw1 = 3; gw2 = 3; gw3 = 3;
		}
	}
}



void displayEND(){
	glBegin(GL_POLYGON);
	glColor3f(0, 1, 1);
	glVertex2f(-10, -10);
	glVertex2f(-10, 1400);
	glColor3f(1, 1, 0);
	glVertex2f(1410, 800);
	glVertex2f(1410, -10);
	glEnd();
	glBegin(GL_2D);
	glColor3f(0, 0, 0);
	output(2, 550, 350, "THANK YOU");
	glEnd();
}



void display(){
	switch (scene)
	{
	case 1:frontpage();
		break;
	case 2:display1();
		break;
	case 3:display2();
		break;
	case 4: display3();
		break;
	case 5:display4();
		break;
	case 6:display5();
		break;
	case 7: displayEND();
		break;
	}
	glutPostRedisplay();
	glFlush();
}

void keys(unsigned char key, int x, int y){
	if (key == 'n') { fuel = 0; c = 0; scene++; sensor = 0; shift = false; xshifter = 0; xs = 1350; ys = 60; p = 1; gc1 = 1; gc2 = 1; gc3 = 1; gw1 = 3; gw2 = 3; gw3 = 3; }
	if (key == 'b') { fuel = 0; c = 0; scene--; sensor = 0; shift = false; xshifter = 0; xs = 1350; ys = 60; p = 1; gc1 = 1; gc2 = 1; gc3 = 1; gw1 = 3; gw2 = 3; gw3 = 3; }
	if (key == 's'){ shift = true; }
	if (key == 'g'){ c += 0.2; }
	if (scene>8)
		scene = 8;
	if (scene<1)
		scene = 1;
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1350, 700);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Garbage Collection");
	glutDisplayFunc(display);
	glutKeyboardFunc(keys);
	myInit();
	glutMainLoop();
	return 0;
}