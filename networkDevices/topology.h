#include<bits/stdc++.h>
#include<time.h>
#include<graphics.h>
using namespace std;
void topology()
{
	int gd = DETECT, gm;
  char c[]= "C:\\TC\\BGI" ;
	initgraph(&gd, &gm,c);
	   settextjustify(CENTER_TEXT, CENTER_TEXT);
     char a[]="AA:AA:AA:EH:0D:AA";
        outtextxy(getmaxx()/2,60,a);
        char ed[]="HUB";
         outtextxy(getmaxx()/2,75,ed);
         settextjustify(CENTER_TEXT, CENTER_TEXT);
    char b[]="AA:AA:AA:44:A0:AB";
        outtextxy(getmaxx()/10+50,200,b);
    char d[]="AA:AA:AA:11:0E:AC";
         settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(getmaxx()/10+150,250,d);
    char e[]="AA:00:1B:AA:AA:AD";
         settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(getmaxx()/10+250,300,e);
    char f[]="B0:11:AA:AA:AA:AE";
    
         settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(getmaxx()/10+350,250,f);
    char g[]="AA:E1:33:AA:AA:AF";
  
          settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(getmaxx()/10+450,200,g);

       circle(getmaxx()/2,60,60);
       //rectangle(getmaxx()/10,150,getmaxx()/10+100,210);
        line(getmaxx()/2,110,getmaxx()/10+40,185);


        line(getmaxx()/2,110,getmaxx()/10+140,235);



        line(getmaxx()/2-10,110,getmaxx()/10+240,285);


        line(getmaxx()/2-10,110,getmaxx()/10+350,235);


        line(getmaxx()/2-10,110,getmaxx()/10+450,185);
        settextjustify(CENTER_TEXT, CENTER_TEXT);
        char er[]="STAR TOPOLOGY SHOWING HUB AND CONNECTED DEVICES";
        outtextxy(getmaxx()/2,getmaxy()-20,er);
        	getch();
	closegraph();

}

