#include<bits/stdc++.h>
#include<time.h>
#include<graphics.h>
using namespace std;
void topology()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm,"C:\\TC\\BGI");
	   settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(getmaxx()/2,60,"AA:AA:AA:EH:0D:AA");
         outtextxy(getmaxx()/2,75,"HUB");
         settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(getmaxx()/10+50,200,"AA:AA:AA:44:A0:AB");

         settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(getmaxx()/10+150,250,"AA:AA:AA:11:0E:AC");

         settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(getmaxx()/10+250,300,"AA:00:1B:AA:AA:AD");

         settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(getmaxx()/10+350,250,"B0:11:AA:AA:AA:AE");

          settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(getmaxx()/10+450,200,"AA:E1:33:AA:AA:AF");

       circle(getmaxx()/2,60,60);
       //rectangle(getmaxx()/10,150,getmaxx()/10+100,210);
        line(getmaxx()/2,110,getmaxx()/10+40,185);


        line(getmaxx()/2,110,getmaxx()/10+140,235);



        line(getmaxx()/2-10,110,getmaxx()/10+240,285);


        line(getmaxx()/2-10,110,getmaxx()/10+350,235);


        line(getmaxx()/2-10,110,getmaxx()/10+450,185);
        settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(getmaxx()/2,getmaxy()-20,"STAR TOPOLOGY SHOWING HUB AND CONNECTED DEVICES");
        	getch();
	closegraph();

}

