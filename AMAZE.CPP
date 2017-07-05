/*
	Name of the Game:	CRAZY BAR
	Creator: 		CH.SRI SAI GOUTHAM
*/
#include<stdlib.h>
#include<process.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
void main()
{
int l,sd=0,k,s,w=1,x1=275,i,j,y1=460,x2=365,y2=474;
int b[7]={5,95,185,275,365,455,545};
int Y1[6]={70,150,230,310,390,470},Y2[6]={80,160,240,320,400,480};
int gdriver = DETECT,gmode;
char ch;
initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
settextstyle(3,0,5);
outtextxy(270,37,"AMAZE");
settextstyle(3,0,3);
outtextxy(210,85,"F for 2 left steps");
outtextxy(210,110,"G for 1 left step");
outtextxy(210,135,"H for 1 right step");
outtextxy(210,160,"J for 2 right steps");
outtextxy(210,185,"Q to exit from GAME");
settextstyle(3,0,2);
getch();
cleardevice();
bar(x1,y1,x2,y2);
rectangle(5,5,635,475);
while(1)
{
settextstyle(3,0,1);
outtextxy(50,10,"Press Q to Quit");
outtextxy(520,10,"SCORE");
gotoxy(580,3);
printf("%d",w);
rectangle(5,5,635,475);

rectangle(5,Y1[0],635,Y2[0]);
rectangle(5,Y1[1],635,Y2[1]);
rectangle(5,Y1[2],635,Y2[2]);
rectangle(5,Y1[3],635,Y2[3]);
rectangle(5,Y1[4],635,Y2[4]);
rectangle(5,Y1[5],635,Y2[5]);
bar(b[0],Y1[0],b[0]+90,Y2[0]);
bar(b[6],Y1[1],b[6]+90,Y2[1]);
bar(b[4],Y1[2],b[4]+90,Y2[2]);
bar(b[3],Y1[3],b[3]+90,Y2[3]);
bar(b[5],Y1[4],b[5]+90,Y2[4]);
bar(b[1],Y1[5],b[1]+90,Y2[5]);

bar(x1,y1,x2,y2);
setfillstyle(1,WHITE);
delay(100);
cleardevice();
for(i=0;i<6;i++)
{
Y1[i]+=10;
Y2[i]+=10;
if(Y1[i]>=480)
{
Y1[i]=5;
Y2[i]=Y1[i]+10;
w++;
k=i;
}
}
s=w%7;
switch(s)
{
case 0:
l=3;
bar(b[3],Y1[k],b[3]+90,Y2[k]);
break;
case 1:
bar(b[4],Y1[k],b[4]+90,Y2[k]);
l=4;
break;
case 2:
bar(b[2],Y1[k],b[1]+90,Y2[k]);
l=2;
break;
case 3:
l=6;
bar(b[6],Y1[k],b[0]+90,Y2[k]);
break;
case 4:
l=1;
bar(b[1],Y1[k],b[1]+90,Y2[k]);
break;
case 5:
l=5;
bar(b[5],Y1[k],b[5]+90,Y2[k]);

break;
case 6:
bar(b[0],Y1[k],b[5]+90,Y2[k]);
l=0;

break;
}
if(kbhit())
{
ch=getch();
switch(ch)
{
case 102://f
if(x1>184)
{
x1-=180;
x2-=180;
cleardevice();
bar(x1,y1,x2,y2);
}
break;
case 103://g
if(x1>94)
{
x1-=90;
x2-=90;
cleardevice();
bar(x1,y1,x2,y2);
}
break;
case 104://h
if(x2<546)
{
cleardevice();
x1+=90;
x2+=90;
bar(x1,y1,x2,y2);
}
break;
case 106://j
if(x2<456)
{
cleardevice();
x1+=180;
x2+=180;
bar(x1,y1,x2,y2);
}
break;
case 113:
exit(0);
}
}
if(w>3)
{
if((x1>=(b[l]-5))&&(x2<=(b[l]+95)))
{
cleardevice();
settextstyle(3,0,3);
outtextxy(140,80,"YOUR SCORE IS");
gotoxy(45,7);
printf("%d",w-5);
nosound();

getch();
exit(0);
}
}
rectangle(5,5,635,475);
settextstyle(3,0,1);
outtextxy(50,10,"Press Q to Quit");
outtextxy(520,10,"SCORE");
gotoxy(580,3);
delay(50);
if(w>=5)
printf("%d",w-5);
else
printf("0");
nosound();
sound(5*random(100));
}
getch();
}





